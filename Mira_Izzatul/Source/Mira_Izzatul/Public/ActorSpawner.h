// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FireManager.h"
#include "GameFramework/Actor.h"
#include "ActorSpawner.generated.h"

class UHierarchicalInstancedStaticMeshComponent;

// Candidate struct with per-candidate bounds
USTRUCT()
struct FCandidate
{
	GENERATED_BODY()

	FVector Pos;
	float MinX, MaxX;
	float MinY, MaxY;
};

UCLASS()
class MIRA_IZZATUL_API AActorSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	AActorSpawner();

    // Delegate broadcast when MaxSpawnable is (re)computed
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxSpawnableChanged, int32, MaxSpawnable);

    // Blueprint event to receive MaxSpawnable updates
    UPROPERTY(BlueprintAssignable, Category = "Spawning")
    FOnMaxSpawnableChanged OnMaxSpawnableChanged;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	UStaticMesh* objMesh;

	UPROPERTY()
	AFireManager* fireManager;

	/** HISM component for instancing */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
	UHierarchicalInstancedStaticMeshComponent* HISM;

	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void GenerateScene(int32 NumActors);

    // Recompute cached candidate positions and update MaxSpawnable. Call when level streaming finishes.
    UFUNCTION(BlueprintCallable, Category = "Spawning")
    void RecomputeCachedCandidates();

    // Expose MaxSpawnable to Blueprints via a getter
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Spawning")
    int32 GetMaxSpawnable() const;

protected:
	virtual void BeginPlay() override;

private:
	// Candidate generation helpers
	// If outTotalArea != nullptr, this function will also accumulate the sum of visible landscape proxy XY areas into *outTotalArea.
	TArray<FCandidate> GetCandidatePositions(float objHalf, float maxScatter, float step, double* outTotalArea = nullptr);

	// Cached candidate positions computed on BeginPlay using the minimum allowed gap
	UPROPERTY()
	TArray<FCandidate> CachedCandidates;

	// Maximum spawnable count computed at BeginPlay
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
	int32 MaxSpawnable = 0;

public:
	// Adaptive spawning parameters (exposed so designers can tweak)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float InitialMinGap = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float MinAllowedGap = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	int32 MaxAttempts = 4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float RelaxationFactor = 0.5f;
};
