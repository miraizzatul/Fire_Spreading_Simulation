// Fill out your copyright notice in the Description page of Project Settings.


#include "FirePlayerController.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "ActorSpawner.h"
#include "Kismet/KismetSystemLibrary.h"

void AFirePlayerController::BeginPlay()
{
	Super::BeginPlay();

	//Add input mapping context
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (PlayerMappingContext)
				Subsystem->AddMappingContext(PlayerMappingContext, 0);
		}
	}
}

void AFirePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
	{
		if (ClickFireAction)
		{
			EnhancedInput->BindAction(ClickFireAction, ETriggerEvent::Started, this, &AFirePlayerController::OnClickPressed);
			EnhancedInput->BindAction(ClickFireAction, ETriggerEvent::Completed, this, &AFirePlayerController::OnClickReleased);
		}
	}
}

void AFirePlayerController::OnClickPressed(const FInputActionValue& Value)
{
	bClickPressed = true;
	clickPressTime = GetWorld()->GetTimeSeconds(); // record press time
}

void AFirePlayerController::OnClickReleased(const FInputActionValue& Value)
{
	if (!bClickPressed) return;

	float PressDuration = GetWorld()->GetTimeSeconds() - clickPressTime;
	bClickPressed = false;

	if (PressDuration <= maxClickDuration)
	{
		IgniteAtCursor(); // only fire if short press
	}
}

void AFirePlayerController::IgniteAtCursor()
{
	FVector WorldLocation, WorldDirection;

	if (DeprojectMousePositionToWorld(WorldLocation, WorldDirection))
	{
		FVector Start = PlayerCameraManager->GetCameraLocation();
		FVector End = Start + (WorldDirection * 100000.f);

		FHitResult Hit;
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(GetPawn());

		if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params))
		{
			// Check if the hit component is a HISM
			if (UHierarchicalInstancedStaticMeshComponent* HISM = Cast<UHierarchicalInstancedStaticMeshComponent>(Hit.GetComponent()))
			{
				int32 InstanceIndex = Hit.Item; // index of the instance that was hit

				// Retrieve the owning ActorSpawner
				if (AActorSpawner* Spawner = Cast<AActorSpawner>(HISM->GetOwner()))
				{
					if (AFireManager* FM = Spawner->fireManager)
					{
						if(FM->bIsSimulationRunning)
							FM->IgniteInstanceByIndex(Spawner, InstanceIndex);
					}
				}
			}
		}
	}
}
