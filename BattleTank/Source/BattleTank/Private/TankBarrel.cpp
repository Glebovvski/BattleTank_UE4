// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	auto RelativeSpeedClamped = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevationChange = RelativeSpeedClamped * MaxDeegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	SetRelativeRotation(FRotator(FMath::Clamp(RawNewElevation, MinDeegreesElevation, MaxDeegreesElevation), 0, 0));
}
