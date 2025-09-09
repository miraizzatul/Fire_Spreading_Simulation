// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "GameFramework/PlayerController.h"
#include "FirePlayerController.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MIRA_IZZATUL_API AFirePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* PlayerMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* ClickFireAction;

private:
	bool bClickPressed = false;
	float clickPressTime = 0.f;
	float maxClickDuration = 0.2f; // max time (seconds) considered a click

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	void OnClickPressed(const FInputActionValue& Value);
	void OnClickReleased(const FInputActionValue& Value);

	void IgniteAtCursor();
};
