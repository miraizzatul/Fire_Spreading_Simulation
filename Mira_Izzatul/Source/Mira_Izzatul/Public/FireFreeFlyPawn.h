// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "FireFreeFlyPawn.generated.h"

class UCameraComponent;

UCLASS()
class MIRA_IZZATUL_API AFireFreeFlyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AFireFreeFlyPawn();

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere)
	class UFloatingPawnMovement* Movement;

	// Movement bounds
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bounds")
	FVector MinBounds = FVector(-5000.f, -5000.f, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bounds")
	FVector MaxBounds = FVector(5000.f, 5000.f, 10000.f);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    
};
