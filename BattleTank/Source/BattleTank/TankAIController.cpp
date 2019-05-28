// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Public/TankAimingComponent.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto Tank = GetPawn();

	if (!ensure(PlayerTank && Tank)) return;

	MoveToActor(PlayerTank, AcceptanceRadius);

	FVector HitLocation = PlayerTank->GetActorLocation();
	//Tank->AimAt(HitLocation);
	auto AimingComponent = Tank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(HitLocation);
	//Tank->Fire();
}


