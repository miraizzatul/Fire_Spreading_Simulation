// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorSpawner.h"
#include "FireManager.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "LandscapeStreamingProxy.h"
#include "EngineUtils.h"

AActorSpawner::AActorSpawner()
{
	PrimaryActorTick.bCanEverTick = false;

	// Create HISM as subobject (visible in editor and Blueprint)
	HISM = CreateDefaultSubobject<UHierarchicalInstancedStaticMeshComponent>(TEXT("HISM"));
	RootComponent = HISM;

	// Set mobility and enable custom data
	HISM->SetMobility(EComponentMobility::Movable);
	HISM->NumCustomDataFloats = 2; // 0 = FireState, 1 = BurnProgress
}

void AActorSpawner::GenerateScene(int32 NumActors)
{
    for (TActorIterator<AFireManager> It(GetWorld()); It; ++It)
    {
        fireManager = *It;
        break;
    }

    if (!objMesh || !fireManager || !HISM) return;

    //pause the simulation
    bool isFireSimulationActive = fireManager->bIsSimulationRunning;

    if (isFireSimulationActive)
        fireManager->SetSimulationRunning(false);

    // Clear the previous Fire Instances
    fireManager->fireInstances.Empty();

    // Assign mesh
    HISM->SetStaticMesh(objMesh);
    HISM->ClearInstances();

    // Object scaling
    FVector ObjScale = FVector(0.5f); // 0.5m cube
    FVector MeshExtent = objMesh->GetBounds().BoxExtent; // half-size
    float ObjHalf = MeshExtent.Z * ObjScale.Z;           // half-height
    float ObjSizeXY = MeshExtent.X * 2.f * ObjScale.X;   // full X size for spacing

    // Adaptive spawning parameters
    const float InitialMinGap = 100.f;   // starting minimum gap between instances
    const float MinAllowedGap = 0.f;     // smallest gap allowed when relaxing constraints
    const int32 MaxAttempts = 4;         // number of times to rebuild candidates with relaxed gap
    const float RelaxationFactor = 0.5f; // how much to reduce MinGap on each attempt

    float CurrentMinGap = InitialMinGap;

    float MaxSlopeAngle = 30.f;     // max terrain slope
    float MaxScatter = 0.f;         // will be computed per attempt

    int32 RequestedNumActors = NumActors;

    int32 FinalPlacedCount = 0;

    // Try several attempts with progressively relaxed spacing to try to meet NumActors.
    for (int32 Attempt = 0; Attempt < MaxAttempts; ++Attempt)
    {
        // Recompute parameters that depend on gap/step
        float MinGap = CurrentMinGap;
        float Step = ObjSizeXY + MinGap;
        MaxScatter = Step / 4.f;

        // Candidate struct with per-candidate bounds
        struct FCandidate
        {
            FVector Pos;
            float MinX, MaxX;
            float MinY, MaxY;
        };

        TArray<FCandidate> CandidatePositions;

        // Iterate all loaded Landscape Streaming Proxies
        for (TActorIterator<ALandscapeStreamingProxy> It(GetWorld()); It; ++It)
        {
            ALandscapeStreamingProxy* Proxy = *It;
            if (!Proxy) continue;

            ULevel* ProxyLevel = Proxy->GetLevel();
            if (!ProxyLevel || !ProxyLevel->bIsVisible) continue; // skip unloaded proxies

            FVector MinBound = Proxy->GetComponentsBoundingBox().Min;
            FVector MaxBound = Proxy->GetComponentsBoundingBox().Max;

            // Clamp candidate positions so full cube + scatter stays inside bounds
            float MinX = MinBound.X + ObjHalf + MaxScatter;
            float MaxX = MaxBound.X - ObjHalf - MaxScatter;
            float MinY = MinBound.Y + ObjHalf + MaxScatter;
            float MaxY = MaxBound.Y - ObjHalf - MaxScatter;

            // If bounds are degenerate, skip this proxy
            if (MinX > MaxX || MinY > MaxY) continue;

            for (float X = MinX; X <= MaxX; X += Step)
            {
                for (float Y = MinY; Y <= MaxY; Y += Step)
                {
                    FCandidate C;
                    C.Pos = FVector(X, Y, 0.f); // Z will be set by line trace
                    C.MinX = MinX;
                    C.MaxX = MaxX;
                    C.MinY = MinY;
                    C.MaxY = MaxY;
                    CandidatePositions.Add(C);
                }
            }
        }

        // If there are no candidates at all, no need to continue
        if (CandidatePositions.Num() == 0)
        {
            UE_LOG(LogTemp, Warning, TEXT("GenerateScene: No placement candidates found (attempt %d)."), Attempt + 1);
            // Relax spacing and try again
            CurrentMinGap = FMath::Max(CurrentMinGap * RelaxationFactor, MinAllowedGap);
            continue;
        }

        // Shuffle candidates for random placement
        for (int32 i = 0; i < CandidatePositions.Num(); i++)
        {
            int32 SwapIdx = FMath::RandRange(0, CandidatePositions.Num() - 1);
            CandidatePositions.Swap(i, SwapIdx);
        }

        //Make spawning adaptive to available candidates
        NumActors = FMath::Min(NumActors, CandidatePositions.Num());

        int32 PlacedCount = 0;

        while (PlacedCount < NumActors && CandidatePositions.Num() > 0)
        {
            FCandidate Candidate = CandidatePositions[0];
            CandidatePositions.RemoveAt(0);

            // Random scatter
            Candidate.Pos.X += FMath::RandRange(-MaxScatter, MaxScatter);
            Candidate.Pos.Y += FMath::RandRange(-MaxScatter, MaxScatter);

            // Clamp using candidate-specific bounds
            Candidate.Pos.X = FMath::Clamp(Candidate.Pos.X, Candidate.MinX, Candidate.MaxX);
            Candidate.Pos.Y = FMath::Clamp(Candidate.Pos.Y, Candidate.MinY, Candidate.MaxY);

            // Line trace down to terrain
            FVector TraceStart = Candidate.Pos + FVector(0.f, 0.f, 5000.f);
            FVector TraceEnd = Candidate.Pos - FVector(0.f, 0.f, 5000.f);

            FHitResult HitResult;
            FCollisionQueryParams Params;
            Params.AddIgnoredActor(this);

            if (!GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECC_WorldStatic, Params))
                continue;

            // Slope filtering
            float SlopeAngle = FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(HitResult.Normal, FVector::UpVector)));
            if (SlopeAngle > MaxSlopeAngle) continue;

            // Final position: terrain height + half cube height
            FVector FinalPos = HitResult.Location;
            FinalPos.Z += ObjHalf;

            // Align rotation to terrain normal
            FRotator InstanceRotation = FRotationMatrix::MakeFromZX(HitResult.Normal, FVector::ForwardVector).Rotator();
            FTransform InstanceTransform(InstanceRotation, FinalPos, ObjScale);

            int32 Index = HISM->AddInstance(InstanceTransform);
            if (fireManager)
                fireManager->RegisterFireComponent(Index, this);

            PlacedCount++;

            // Random per-instance gap
            float Gap = FMath::RandRange(0.f, 300.f);
            float ClearRadius = ObjSizeXY + Gap;

            // Remove nearby candidates to maintain spacing
            for (int32 i = CandidatePositions.Num() - 1; i >= 0; i--)
            {
                if (FVector::Dist2D(FinalPos, CandidatePositions[i].Pos) < ClearRadius)
                {
                    CandidatePositions.RemoveAt(i);
                }
            }
        }

        FinalPlacedCount = PlacedCount;

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
        if (CurrentMinGap <= MinAllowedGap + KINDA_SMALL_NUMBER)
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
