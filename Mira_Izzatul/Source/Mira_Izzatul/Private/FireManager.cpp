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

void AFireManager::BeginPlay()
{
	Super::BeginPlay();

	FVector WindXY = windDirection;
	WindXY.Z = 0.f;

	UpdateWindDecalFX(WindXY, windSpeed);
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
	Spawner->HISM->SetCustomDataValue(InstanceIndex, 0, 0.f, false); // Fire State (0 = Fresh)
	Spawner->HISM->SetCustomDataValue(InstanceIndex, 1, 0.f, true); // Burn Progress (0%)

	fireInstances.Add(NewInstance);
}

void AFireManager::TrySpread()
{
	if (!bIsSimulationRunning) return;

	for (FFireInstanceData& FireSource : fireInstances)
	{
		if (FireSource.FireState != EFireState::Burning) continue;

		FTransform SourceInstanceTransform;
		FVector SourceLoc;
		if (FireSource.Spawner->HISM->GetInstanceTransform(FireSource.InstanceIndex, SourceInstanceTransform, true))
			SourceLoc = SourceInstanceTransform.GetLocation();

		for (FFireInstanceData& Target : fireInstances)
		{
			if (Target.FireState != EFireState::Fresh) continue;

			FTransform TargetInstanceTransform;
			FVector TargetLoc;
			if (FireSource.Spawner->HISM->GetInstanceTransform(Target.InstanceIndex, TargetInstanceTransform, true))
				TargetLoc = TargetInstanceTransform.GetLocation();

			float Dist = FVector::Dist(SourceLoc, TargetLoc);
			if (Dist > spreadRadius) continue;

			// Direction from source to target
			FVector ToTarget = (TargetLoc - SourceLoc).GetSafeNormal();

			// Wind influence (dot product)
			float WindDot = FVector::DotProduct(ToTarget, windDirection.GetSafeNormal());

			// Minimum spread factor ensures fire can always spread a bit (e.g., 10%)
			const float MinFactor = 0.1f;

			// Apply wind influence, scaled and clamped between MinFactor and 1 + windStrength
			float WindFactor = FMath::Clamp(1.0f + WindDot * windSpeed, MinFactor, 1.0f + windSpeed);

			// Final chance
			float FinalChance = spreadChance * WindFactor;

			// Ensure FinalChance does not exceed 1.0
			FinalChance = FMath::Min(FinalChance, 1.0f);

			// Attempt to ignite
			if (FMath::FRand() < FinalChance)
				IgniteInstance(Target);
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

