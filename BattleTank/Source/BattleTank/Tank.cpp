// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "Public/TankTurret.h"
#include "Components/SceneComponent.h"
#include "Public/TankBarrel.h"
#include "Public/Projectile.h"

// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	UE_LOG(LogTemp, Warning, TEXT("TANK LOG: CONSTRUCTOR WORKED ON %s"), *GetName());
}

void ATank::Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
	//TankAimingComponent->Initialize(BarrelToSet, TurretToSet);
	Barrel = BarrelToSet;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	//UE_LOG(LogTemp, Warning, TEXT("TANK LOG: BEGIN PLAY WORKED ON %s"), *GetName());
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::Fire()
{
	if(!ensure(Barrel)) return;

	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (isReloaded)
	{

		FVector Location = Barrel->GetSocketLocation(FName("Projectile"));
		FRotator Rotation = Barrel->GetSocketRotation(FName("Projectile"));

		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Location, Rotation);
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}

