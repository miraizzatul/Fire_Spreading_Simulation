// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpectatorPawn.h"
#include "FireSpreadSpecPawn.generated.h"

/**
 * 
 */
UCLASS()
class MIRA_IZZATUL_API AFireSpreadSpecPawn : public ASpectatorPawn
{
	GENERATED_BODY()

public:
	// Movement bounds
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bounds")
	FVector MinBounds = FVector(-5000.f, -5000.f, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bounds")
	FVector MaxBounds = FVector(5000.f, 5000.f, 5000.f);

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
