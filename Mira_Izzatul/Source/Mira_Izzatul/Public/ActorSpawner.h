// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FireManager.h"
#include "GameFramework/Actor.h"
#include "ActorSpawner.generated.h"

class UHierarchicalInstancedStaticMeshComponent;

UCLASS()
class MIRA_IZZATUL_API AActorSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	AActorSpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	UStaticMesh* objMesh;

	UPROPERTY()
	AFireManager* fireManager;

	/** HISM component for instancing */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
	UHierarchicalInstancedStaticMeshComponent* HISM;

	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void GenerateScene(int32 NumActors);

};
