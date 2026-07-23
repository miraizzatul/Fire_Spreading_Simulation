// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorSpawner.h"
#include "FireManager.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "LandscapeStreamingProxy.h"
#include "EngineUtils.h"
#include "ProfilingDebugging/MiscTrace.h"

AActorSpawner::AActorSpawner()
{
	PrimaryActorTick.bCanEverTick = false;

	// Create HISM as subobject (visible in editor and Blueprint)
	HISM = CreateDefaultSubobject<UHierarchicalInstancedStaticMeshComponent>(TEXT("HISM"));
	RootComponent = HISM;

	// Configure collision for HISM: ignore all channels except visibility (for line traces)
    HISM->SetCollisionObjectType(ECC_WorldStatic);
    HISM->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    HISM->SetCollisionResponseToAllChannels(ECR_Ignore);
    HISM->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	// Set mobility and enable custom data
	HISM->SetMobility(EComponentMobility::Movable);
	HISM->NumCustomDataFloats = 2; // 0 = FireState, 1 = BurnProgress
    HISM->SetGenerateOverlapEvents(false);
    HISM->SetCanEverAffectNavigation(false);
}

int32 AActorSpawner::GetMaxSpawnable() const
{
    return MaxSpawnable;
}

void AActorSpawner::BeginPlay()
{
    Super::BeginPlay();

    UE_LOG(LogTemp, Error, TEXT("ActorSpawner BeginPlay"));

    // Precompute maximum candidate positions using the smallest allowed gap so this
    // represents the maximal number of possible placements. This avoids recomputing
    // the grid every call to GenerateScene.
    if (!objMesh)
    {
        UE_LOG(LogTemp, Warning, TEXT("AActorSpawner::BeginPlay - objMesh not assigned; cannot precompute candidates."));
        return;
    }

	// Compute initial object size and step based on the mesh bounds and scale. This assumes uniform scaling.
    ObjScale = FVector(0.5f);
    MeshExtent = objMesh->GetBounds().BoxExtent;
    ObjHalf = MeshExtent.Z * ObjScale.Z;
    ObjSizeXY = MeshExtent.X * 2.f * ObjScale.X;
    Step = ObjSizeXY + MinAllowedGap;

    double TotalLandscapeArea = 0.0;

    // Call GetCandidatePositions once to get both candidates and landscape area.
    CachedCandidates = GetCandidatePositions(ObjHalf, MaxScatter, Step, &TotalLandscapeArea);

    UE_LOG(LogTemp, Warning, TEXT("CachedCandidates = %d"), CachedCandidates.Num());
    // Compute a simple landscape-area based estimate (sum of proxy XY areas returned by GetCandidatePositions).
    // Avoid division by zero
    const double CellArea = FMath::Max(1.0f, static_cast<double>(Step) * static_cast<double>(Step));
    const int32 TheoreticalMax = static_cast<int32>(FMath::FloorToFloat(static_cast<float>(TotalLandscapeArea / CellArea)));

    // Set MaxSpawnable to the best available estimate: use the cached exact count when available,
    // otherwise fall back to the theoretical area-based estimate. This avoids reporting zero
    // when discrete candidates were found but area calculation missed proxies (streaming not ready).
    MaxSpawnable = FMath::Max(TheoreticalMax, CachedCandidates.Num());

    if (MaxSpawnable == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("AActorSpawner::BeginPlay - computed MaxSpawnable == 0. CachedCandidates=%d, TheoreticalMax=%d. If level streaming loads proxies after BeginPlay, call RecomputeCachedCandidates()."), CachedCandidates.Num(), TheoreticalMax);
    }

    UE_LOG(LogTemp, Log, TEXT("AActorSpawner::BeginPlay - Precomputed %d candidate positions (exact). Theoretical max based on landscape area: %d."),
        CachedCandidates.Num(), MaxSpawnable);

    for (TActorIterator<AFireManager> It(GetWorld()); It; ++It)
    {
        fireManager = *It;
        break;
    }

    // Broadcast the initial MaxSpawnable value
    OnMaxSpawnableChanged.Broadcast(MaxSpawnable);
}

void AActorSpawner::GenerateScene(int32 NumActors)
{
    TRACE_BOOKMARK(TEXT("Generate Scene Started"));

    if (!objMesh || !fireManager || !HISM) return;

    //pause the simulation
    bool isFireSimulationActive = fireManager->bIsSimulationRunning;

    if (isFireSimulationActive)
        fireManager->SetSimulationRunning(false);

    //Reserve fireInstances array to avoid reallocations during GenerateScene  
    fireManager->fireInstances.Reset();
    fireManager->fireInstances.Reserve(RequestedNumActors);

    // Assign mesh
    HISM->SetStaticMesh(objMesh);
    HISM->ClearInstances();

    UE_LOG(LogTemp, Warning,TEXT("CubeSize=%f InitialGap=%f MinAllowedGap=%f"), ObjSizeXY, InitialMinGap, MinAllowedGap);

    float CurrentMinGap = InitialMinGap;
    float MinGap = 0.f;

    RequestedNumActors = NumActors;
	int32 AttemptTarget = 0;

    int32 FinalPlacedCount = 0;

    float StepForCache = ObjSizeXY + MinAllowedGap;
    float ScatterForCache = StepForCache / 4.f;

    int32 CandidateIndex = 0;
    FCandidate Candidate;

    FVector TraceStart;
    FVector TraceEnd;
    FHitResult HitResult;
    FCollisionQueryParams Params;
    FVector FinalPos;

    int32 Index;
    int32 PlacedCount = 0;
    int32 TraceFailures = 0;

    TArray<FTransform> Transforms;
    FRotator InstanceRotation;

    // Try several attempts with progressively relaxed spacing to try to meet NumActors.
    for (int32 Attempt = 0; Attempt < MaxAttempts; ++Attempt)
    {
        // Recompute parameters that depend on gap/step
        MinGap = CurrentMinGap;
        Step = ObjSizeXY + MinGap;
        MaxScatter = Step * 0.15f;

		// Reset candidate positions to the cached values for this attempt
        CandidatePositions.Reset();
        CandidatePositions.Append(CachedCandidates);

        UE_LOG(LogTemp, Warning, TEXT("Step=%f Scatter=%f Candidates=%d"), Step, MaxScatter, CandidatePositions.Num());

        // If cache is empty (objMesh missing at begin or precompute skipped), build on demand for this call
        if (CandidatePositions.Num() == 0)
        {
            CandidatePositions = GetCandidatePositions(ObjHalf, ScatterForCache, StepForCache);

            // Update cache and MaxSpawnable for future calls
            CachedCandidates = CandidatePositions;
            MaxSpawnable = CachedCandidates.Num();
            UE_LOG(LogTemp, Log, TEXT("AActorSpawner::GenerateScene - Built fallback cache with %d candidates."), MaxSpawnable);
        }

        //Make spawning adaptive to available candidates
        AttemptTarget = FMath::Min(RequestedNumActors, CandidatePositions.Num());

        Transforms.Reserve(AttemptTarget);

        while (PlacedCount < AttemptTarget && CandidatePositions.Num() > 0)
        {
            CandidateIndex = FMath::RandRange(0, CandidatePositions.Num() - 1);

            CandidatePositions.Swap(CandidateIndex, CandidatePositions.Num() - 1);

            Candidate = MoveTemp(CandidatePositions.Last());
            CandidatePositions.Pop(false);

            // Clamp using candidate-specific bounds
            Candidate.Pos.X = FMath::Clamp(Candidate.Pos.X, Candidate.MinX, Candidate.MaxX);
            Candidate.Pos.Y = FMath::Clamp(Candidate.Pos.Y, Candidate.MinY, Candidate.MaxY);

            // Line trace down to terrain
            TraceStart = Candidate.Pos + FVector(0.f, 0.f, 1000.f);
            TraceEnd = Candidate.Pos - FVector(0.f, 0.f, 1000.f);

            Params.AddIgnoredActor(this);

            if (!GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECC_WorldStatic, Params))
            {
                TraceFailures++;
                continue;
            }

            // Slope filtering
            /*float SlopeAngle = FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(HitResult.Normal, FVector::UpVector)));
            if (SlopeAngle > 30.f) continue;*/

            // Final position: terrain height + half cube height
            FinalPos = HitResult.Location;
            FinalPos.Z += ObjHalf;

            // Align rotation to terrain normal
            InstanceRotation = FRotationMatrix::MakeFromZX(HitResult.Normal, FVector::ForwardVector).Rotator();
            Transforms.Add(FTransform(InstanceRotation, FinalPos, ObjScale));

            //int32 Index = HISM->AddInstance(InstanceTransform);
            PlacedCount++;
        }

        Index = HISM->GetInstanceCount();
        HISM->AddInstances(Transforms, false, true, false);
        HISM->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
        HISM->BuildTreeIfOutdated(true, false);

        for (int32 i = 0; i < Transforms.Num(); i++)
        {
            fireManager->RegisterFireComponent(Index + i, this);
        }

        FinalPlacedCount = FMath::Max(FinalPlacedCount, PlacedCount);

        // If we placed enough, break out
        if (FinalPlacedCount >= RequestedNumActors)
        {
            break;
        }

        // Not enough placed: log and relax constraints for next attempt
        UE_LOG(LogTemp, Warning, TEXT("GenerateScene attempt %d: placed %d / requested %d. Relaxing spacing and retrying."),
            Attempt + 1, FinalPlacedCount, RequestedNumActors);

        // Clear instances and registered data to retry with relaxed gap
        HISM->ClearInstances();
        fireManager->fireInstances.Empty();

        // Relax spacing
        CurrentMinGap = FMath::Max(CurrentMinGap * RelaxationFactor, MinAllowedGap);

        // If gap is already at minimum and still not enough, stop early
        if (CurrentMinGap <= MinAllowedGap + (1.e-4f))
        {
            UE_LOG(LogTemp, Warning, TEXT("GenerateScene: reached minimum allowed gap and still couldn't place all requested actors."));
            break;
        }

        // Next attempt will rebuild candidate grid using the new CurrentMinGap
    }

    // If after attempts we still couldn't place all requested, notify
    if (FinalPlacedCount < RequestedNumActors)
    {
        UE_LOG(LogTemp, Warning, TEXT("GenerateScene: Requested %d objects but only placed %d due to space constraints."), RequestedNumActors, FinalPlacedCount);
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("GenerateScene: Successfully placed %d objects (requested %d)."), FinalPlacedCount, RequestedNumActors);
    }

    //Set previous simulation state back
    fireManager->SetSimulationRunning(isFireSimulationActive);
}

TArray<FCandidate> AActorSpawner::GetCandidatePositions(float objHalf, float maxScatter, float step, double* OutTotalArea /*= nullptr */)
{
    double AccumArea = 0.0;

    ALandscapeStreamingProxy* Proxy = nullptr;
    ULevel* ProxyLevel = nullptr;
    FVector MinBound = FVector::ZeroVector;
    FVector MaxBound = FVector::ZeroVector;

    float MinX = 0.0f;
    float MaxX = 0.0f;
    float MinY = 0.0f;
    float MaxY = 0.0f;

    FCandidate C;

    // Iterate all loaded Landscape Streaming Proxies
    for (TActorIterator<ALandscapeStreamingProxy> It(GetWorld()); It; ++It)
    {
        Proxy = *It;
        if (!Proxy) continue;

        ProxyLevel = Proxy->GetLevel();
        if (!ProxyLevel || !ProxyLevel->bIsVisible) continue; // skip unloaded proxies

        MinBound = Proxy->GetComponentsBoundingBox().Min;
        MaxBound = Proxy->GetComponentsBoundingBox().Max;

        // Accumulate proxy XY area for a fast landscape-size estimate
        const double Width = FMath::Max(0.0f, MaxBound.X - MinBound.X);
        const double Height = FMath::Max(0.0f, MaxBound.Y - MinBound.Y);
        AccumArea += Width * Height;

        // Clamp candidate positions so full cube + scatter stays inside bounds
        MinX = MinBound.X + objHalf + maxScatter;
        MaxX = MaxBound.X - objHalf - maxScatter;
        MinY = MinBound.Y + objHalf + maxScatter;
        MaxY = MaxBound.Y - objHalf - maxScatter;

        // If bounds are degenerate, skip this proxy
        if (MinX > MaxX || MinY > MaxY) continue;

        for (float X = MinX; X <= MaxX; X += step)
        {
            for (float Y = MinY; Y <= MaxY; Y += step)
            {
                float RandomOffsetX = FMath::FRandRange(-maxScatter, maxScatter);
                float RandomOffsetY = FMath::FRandRange(-maxScatter, maxScatter);

                C.Pos = FVector(X + RandomOffsetX, Y + RandomOffsetY, 0.f);

                C.MinX = MinX;
                C.MaxX = MaxX;
                C.MinY = MinY;
                C.MaxY = MaxY;

                CandidatePositions.Add(C);
            }
        }
    }

    if (OutTotalArea)
    {
        *OutTotalArea = AccumArea;
    }

    return CandidatePositions;
}
