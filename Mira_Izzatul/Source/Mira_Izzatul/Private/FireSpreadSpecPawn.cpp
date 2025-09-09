// Fill out your copyright notice in the Description page of Project Settings.


#include "FireSpreadSpecPawn.h"

void AFireSpreadSpecPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FVector Pos = GetActorLocation();
    Pos.X = FMath::Clamp(Pos.X, MinBounds.X, MaxBounds.X);
    Pos.Y = FMath::Clamp(Pos.Y, MinBounds.Y, MaxBounds.Y);
    Pos.Z = FMath::Clamp(Pos.Z, MinBounds.Z, MaxBounds.Z);

    SetActorLocation(Pos);
}
