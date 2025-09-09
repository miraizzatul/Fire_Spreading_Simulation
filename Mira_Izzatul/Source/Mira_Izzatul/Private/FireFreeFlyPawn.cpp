// Fill out your copyright notice in the Description page of Project Settings.


#include "FireFreeFlyPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "LandscapeStreamingProxy.h"
#include "EngineUtils.h"

// Sets default values
AFireFreeFlyPawn::AFireFreeFlyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	RootComponent = Camera;

    Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));
    Movement->MaxSpeed = 1200.f; // adjust as needed

    // Set default camera rotation (bird-eye view)
    Camera->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f)); // pitch down 60 degrees
}

// Called when the game starts or when spawned
void AFireFreeFlyPawn::BeginPlay()
{
	Super::BeginPlay();

    for (TActorIterator<ALandscapeStreamingProxy> It(GetWorld()); It; ++It)
    {
        ALandscapeStreamingProxy* Proxy = *It;
        if (!Proxy) continue;

        ULevel* ProxyLevel = Proxy->GetLevel();
        if (!ProxyLevel || !ProxyLevel->bIsVisible) continue; // skip unloaded proxies

        MinBounds = Proxy->GetComponentsBoundingBox().Min;
        MaxBounds = Proxy->GetComponentsBoundingBox().Max;

    }
}

// Called every frame
void AFireFreeFlyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    FVector Pos = GetActorLocation();
    Pos.X = FMath::Clamp(Pos.X, MinBounds.X, MaxBounds.X);
    Pos.Y = FMath::Clamp(Pos.Y, MinBounds.Y, MaxBounds.Y);
    Pos.Z = FMath::Clamp(Pos.Z, MinBounds.Z, MaxBounds.Z);

    SetActorLocation(Pos);
}

