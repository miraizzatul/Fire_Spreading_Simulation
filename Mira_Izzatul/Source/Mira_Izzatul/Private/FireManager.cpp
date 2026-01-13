// Fill out your copyright notice in the Description page of Project Settings.


#include "FireManager.h"
#include "Engine/World.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "ActorSpawner.h"
#include "Components/DecalComponent.h"

// Sets default values
AFireManager::AFireManager()
{
	PrimaryActorTick.bCanEverTick = false;

	// Create the Decal Component
	WindDecalComponent = CreateDefaultSubobject<UDecalComponent>(TEXT("MyDecalComponent"));

	// Attach it to the root component (or another component)
	WindDecalComponent->SetupAttachment(RootComponent);
	WindDecalComponent->DecalSize = FVector(20.0f, 20.0f, 20.0f); // Adjust size as needed
}

int64 AFireManager::ComputeCellKey(int32 CellX, int32 CellY) const
{
	// pack two signed 32-bit ints into one 64-bit key
	return (static_cast<int64>(CellX) << 32) | static_cast<uint32>(CellY);
}

void AFireManager::GetCellCoords(const FVector& Pos, int32& OutX, int32& OutY) const
{
	const float CellSize = SpatialCellSize > 0.f ? SpatialCellSize : FMath::Max(spreadRadius, 1.f);
	OutX = FMath::FloorToInt(Pos.X / CellSize);
	OutY = FMath::FloorToInt(Pos.Y / CellSize);
}

void AFireManager::InsertInstanceIntoGrid(int32 FireArrayIndex)
{
	if (!fireInstances.IsValidIndex(FireArrayIndex)) return;

	const FVector& Pos = fireInstances[FireArrayIndex].CachedLocation;
	int32 CX = 0, CY = 0;
	GetCellCoords(Pos, CX, CY);
	int64 Key = ComputeCellKey(CX, CY);

	TArray<int32>& Bucket = SpatialHashGrid.FindOrAdd(Key);
	Bucket.AddUnique(FireArrayIndex);
}

void AFireManager::RebuildSpatialIndex()
{
	SpatialHashGrid.Empty();
	// set cell size from spreadRadius to avoid tiny/zero cells
	SpatialCellSize = FMath::Max(spreadRadius, 1.f);

	for (int32 i = 0; i < fireInstances.Num(); ++i)
	{
		InsertInstanceIntoGrid(i);
	}
}

void AFireManager::BeginPlay()
{
	Super::BeginPlay();

	FVector WindXY = windDirection;
	WindXY.Z = 0.f;

	UpdateWindDecalFX(WindXY, windSpeed);

	// Initialize spatial index cell size and index for already-registered instances (if any)
	SpatialCellSize = FMath::Max(spreadRadius, 1.f);
	RebuildSpatialIndex();
}

void AFireManager::SetSimulationRunning(bool bRun)
{
	bIsSimulationRunning = bRun;

	if (bIsSimulationRunning)
	{
		// Spread timer
		if (!GetWorld()->GetTimerManager().IsTimerActive(spreadTimerHandle))
		{
			GetWorld()->GetTimerManager().SetTimer(spreadTimerHandle, this, &AFireManager::TrySpread, 0.5f, true);
		}

		// Burn update timer (every 0.1s)
		if (!GetWorld()->GetTimerManager().IsTimerActive(burnUpdateTimerHandle))
		{
			GetWorld()->GetTimerManager().SetTimer(burnUpdateTimerHandle, this, &AFireManager::UpdateBurnProgress, 0.1f, true);
		}
	}
	else
	{
		GetWorld()->GetTimerManager().PauseTimer(spreadTimerHandle);
		GetWorld()->GetTimerManager().PauseTimer(burnUpdateTimerHandle);
	}
}

void AFireManager::RegisterFireComponent(int32 InstanceIndex, AActorSpawner* Spawner)
{
	FFireInstanceData NewInstance;
	NewInstance.Spawner = Spawner;
	NewInstance.InstanceIndex = InstanceIndex;

	// Initialize fire state + burn progress in HISM custom data
	if (Spawner && Spawner->HISM)
	{
		Spawner->HISM->SetCustomDataValue(InstanceIndex, 0, 0.f, false); // Fire State (0 = Fresh)
		Spawner->HISM->SetCustomDataValue(InstanceIndex, 1, 0.f, true);  // Burn Progress (0%)
	}

	// Try to cache the instance world location now to avoid querying transform every spread tick
	if (Spawner && Spawner->HISM)
	{
		FTransform InstanceTransform;
		if (Spawner->HISM->GetInstanceTransform(InstanceIndex, InstanceTransform, true))
		{
			NewInstance.CachedLocation = InstanceTransform.GetLocation();
		}
	}

	// Add instance and insert to spatial grid
	int32 NewArrayIndex = fireInstances.Add(NewInstance);
	InsertInstanceIntoGrid(NewArrayIndex);
}

void AFireManager::TrySpread()
{
	if (!bIsSimulationRunning) return;

	if (fireInstances.Num() == 0) return;

	// Precompute some values outside inner loops
	const float CellSize = SpatialCellSize > 0.f ? SpatialCellSize : FMath::Max(spreadRadius, 1.f);
	const int32 RadiusInCells = FMath::CeilToInt(spreadRadius / CellSize);
	const FVector WindNorm = windDirection.GetSafeNormal();

	// Iterate only burning instances and query nearby buckets
	for (int32 SourceIdx = 0; SourceIdx < fireInstances.Num(); ++SourceIdx)
	{
		FFireInstanceData& FireSource = fireInstances[SourceIdx];
		if (FireSource.FireState != EFireState::Burning) continue;

		const FVector SourceLoc = FireSource.CachedLocation;

		int32 SourceCellX = 0, SourceCellY = 0;
		GetCellCoords(SourceLoc, SourceCellX, SourceCellY);

		for (int32 dx = -RadiusInCells; dx <= RadiusInCells; ++dx)
		{
			for (int32 dy = -RadiusInCells; dy <= RadiusInCells; ++dy)
			{
				int64 Key = ComputeCellKey(SourceCellX + dx, SourceCellY + dy);
				if (TArray<int32>* Bucket = SpatialHashGrid.Find(Key))
				{
					for (int32 TargetArrayIdx : *Bucket)
					{
						// Skip self
						if (TargetArrayIdx == SourceIdx) continue;

						// bounds check (shouldn't be necessary)
						if (!fireInstances.IsValidIndex(TargetArrayIdx)) continue;

						FFireInstanceData& Target = fireInstances[TargetArrayIdx];

						// Only attempt ignition on fresh instances
						if (Target.FireState != EFireState::Fresh) continue;

						// Quick AABB/cell-based distance reject could be done earlier; here precise distance
						const FVector TargetLoc = Target.CachedLocation;
						const float Dist = FVector::Dist(SourceLoc, TargetLoc);
						if (Dist > spreadRadius) continue;

						// Direction from source to target
						const FVector ToTarget = (TargetLoc - SourceLoc).GetSafeNormal();

						// Wind influence (dot product)
						const float WindDot = FVector::DotProduct(ToTarget, WindNorm);

						// Minimum spread factor ensures fire can always spread a bit (e.g., 10%)
						const float MinFactor = 0.1f;

						// Apply wind influence, scaled and clamped between MinFactor and 1 + windStrength
						const float WindFactor = FMath::Clamp(1.0f + WindDot * windSpeed, MinFactor, 1.0f + windSpeed);

						// Final chance
						float FinalChance = spreadChance * WindFactor;

						// Ensure FinalChance does not exceed 1.0
						FinalChance = FMath::Min(FinalChance, 1.0f);

						// Attempt to ignite
						if (FMath::FRand() < FinalChance)
						{
							IgniteInstance(Target);
						}
					}
				}
			}
		}
	}
}

void AFireManager::IgniteInstance(FFireInstanceData& Instance)
{
	// Already bruning or done
	if (Instance.FireState == EFireState::Burning || Instance.FireState == EFireState::Burnt) return;

	// Start burning using current world time
	Instance.StartBurn(GetWorld()->GetTimeSeconds());

	if (Instance.Spawner && Instance.Spawner->HISM)
	{
		Instance.Spawner->HISM->SetCustomDataValue(Instance.InstanceIndex, 0, 1.f); // e.g., 1 = burning
		Instance.Spawner->HISM->SetCustomDataValue(Instance.InstanceIndex, 1, 0.f); // Reset burn progress
	}
}

void AFireManager::UpdateBurnProgress()
{
	const float TimerDeltaTime = 0.1f; // Match burn progress timer interval

	for (FFireInstanceData& Instance : fireInstances)
	{
		if (Instance.FireState != EFireState::Burning)
			continue;

		Instance.ElapsedTime += TimerDeltaTime;
		float Progress = FMath::Clamp(Instance.ElapsedTime / burnDuration, 0.f, 1.f);

		if (Instance.Spawner && Instance.Spawner->HISM)
		{
			// Update burn progress slot (Slot1)
			Instance.Spawner->HISM->SetCustomDataValue(Instance.InstanceIndex, 1, Progress, true);
		}

		// When burn finished
		if (Progress >= 1.f)
		{
			Instance.FireState = EFireState::Burnt;

			if (Instance.Spawner && Instance.Spawner->HISM)
			{
				// Update FireState to Burnt (Slot0 = 2)
				Instance.Spawner->HISM->SetCustomDataValue(Instance.InstanceIndex, 0, 2.f, true);
				Instance.Spawner->HISM->SetCustomDataValue(Instance.InstanceIndex, 1, 1.f, true); // ensure progress = 1
			}
		}
	}
}

void AFireManager::UpdateWindDecalFX(FVector Direction, float Speed)
{
	UMaterialInstanceDynamic* WindMat = WindDecalComponent->CreateDynamicMaterialInstance();
	if (WindMat)
	{
		WindMat->SetVectorParameterValue("WindDirection", Direction.GetSafeNormal());
		WindMat->SetScalarParameterValue("WindSpeed", Speed);

		if (Speed <= 0.f)
			WindDecalComponent->SetVisibility(false);
		else
		{
			if (WindDecalComponent->IsVisible() != bIsWindFXVisible)
				WindDecalComponent->SetVisibility(bIsWindFXVisible);
		}
	}
}

void AFireManager::IgniteInstanceByIndex(AActorSpawner* Spawner, int32 InstanceIndex)
{
	for (FFireInstanceData& Instance : fireInstances)
	{
		if (Instance.Spawner == Spawner && Instance.InstanceIndex == InstanceIndex)
		{
			IgniteInstance(Instance);
			break;
		}
	}
}

void AFireManager::CalculateWindDirection(float WindAngleDegrees)
{
	float WindAngleRadians = FMath::DegreesToRadians(WindAngleDegrees);
	windDirection = FVector(FMath::Cos(WindAngleRadians), FMath::Sin(WindAngleRadians), 0.f);

	FVector WindXY = windDirection;
	WindXY.Z = 0.f;

	UpdateWindDecalFX(WindXY, windSpeed);
}

void AFireManager::UpdateNewWindSpeed(float Speed)
{
	windSpeed = Speed;

	FVector WindXY = windDirection;
	WindXY.Z = 0.f;

	UpdateWindDecalFX(WindXY, Speed);
}

void AFireManager::ToggleWindVisual(bool bOn)
{
	bIsWindFXVisible = bOn;

	if (windSpeed <= 0.f) return;

	if (WindDecalComponent->IsVisible() != bIsWindFXVisible)
		WindDecalComponent->SetVisibility(bIsWindFXVisible);
}

