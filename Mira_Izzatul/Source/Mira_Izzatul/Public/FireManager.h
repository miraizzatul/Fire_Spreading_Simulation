// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FireManager.generated.h"

class AActorSpawner;
class UDecalComponent;

UENUM(BlueprintType)
enum class EFireState : uint8
{
	Fresh,
	Burning,
	Burnt
};

USTRUCT(BlueprintType)
struct FFireInstanceData
{
	GENERATED_BODY()

	UPROPERTY()
	AActorSpawner* Spawner = nullptr;

	UPROPERTY()
	EFireState FireState = EFireState::Fresh;

	UPROPERTY()
	float ElapsedTime = 0.f;

	// World time when this instance was last updated
	UPROPERTY()
	float LastUpdateTime = 0.f;

	UPROPERTY()
	int32 InstanceIndex = -1;

	// Cached world location (update if the instance moves)
	UPROPERTY()
	FVector CachedLocation = FVector::ZeroVector;

	void StartBurn(float CurrentTime)
	{
		FireState = EFireState::Burning;
		ElapsedTime = 0.f;
		LastUpdateTime = CurrentTime;
	}
};

UCLASS()
class MIRA_IZZATUL_API AFireManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFireManager();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fire Settings")
	bool bIsSimulationRunning = false;

	//in cm(2cm default)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire Settings")
	float spreadRadius = 200.f;

	//40% chance
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire Settings")
	float spreadChance = 0.4f;

	UPROPERTY(BlueprintReadOnly, Category = "Fire Settings")
	FVector windDirection = FVector::ZeroVector;

	// in m/s
	UPROPERTY(BlueprintReadOnly, Category = "Fire Settings")
	float windSpeed = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire Settings")
	float burnDuration = 5.f; // seconds

	UPROPERTY(BlueprintReadOnly, Category = "Fire Settings")
	bool bIsWindFXVisible = true;

	UPROPERTY()
	TArray<FFireInstanceData> fireInstances;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Decals")
	UDecalComponent* WindDecalComponent;

private:
	FTimerHandle spreadTimerHandle;
	FTimerHandle burnUpdateTimerHandle;

	// Spatial hash grid to accelerate spread queries.
	// Key is packed (cellX, cellY) into int64; value is array of indices into fireInstances.
	TMap<int64, TArray<int32>> SpatialHashGrid;

	// Size of each grid cell. Set initially from spreadRadius; call RebuildSpatialIndex if spreadRadius changes.
	float SpatialCellSize = 200.f;

	// Helpers
	int64 ComputeCellKey(int32 CellX, int32 CellY) const;
	void GetCellCoords(const FVector& Pos, int32& OutX, int32& OutY) const;
	void InsertInstanceIntoGrid(int32 FireArrayIndex);
	void RebuildSpatialIndex();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	void SetSimulationRunning(bool bRun);

	UFUNCTION(BlueprintCallable)
	void CalculateWindDirection(float WindAngleDegrees);

	UFUNCTION(BlueprintCallable)
	void UpdateNewWindSpeed(float Speed);

	UFUNCTION(BlueprintCallable)
	void ToggleWindVisual(bool bOn);
	
	//caled when regenerating the scene
	void RegisterFireComponent(int32 InstanceIndex, AActorSpawner* Spawner);

	void IgniteInstanceByIndex(AActorSpawner* Spawner, int32 InstanceIndex);

private:
	void TrySpread();
	void IgniteInstance(FFireInstanceData& Instance);
	void UpdateBurnProgress();
	void UpdateWindDecalFX(FVector Direction, float Speed);
};
