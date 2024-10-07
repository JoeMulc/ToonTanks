// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "Projectile.h"

// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(CapsuleComp);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	projectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	projectileSpawnPoint->SetupAttachment(TurretMesh);

}

void  ABasePawn::RotateTurret(FVector target)
{
	FVector targetVector = target - TurretMesh->GetComponentLocation();
	FRotator targetRotation = FRotator(0.f, targetVector.Rotation().Yaw, 0.f);

	TurretMesh->SetWorldRotation(
		FMath::RInterpTo(
			TurretMesh->GetComponentRotation(), 
			targetRotation, 
			UGameplayStatics::GetWorldDeltaSeconds(this), 
			25.f));
}

void  ABasePawn::Fire()
{
	FVector projectileSpawnPointLocation = projectileSpawnPoint->GetComponentLocation();
	FRotator projectileRotation = projectileSpawnPoint->GetComponentRotation();

	AProjectile* projectile = GetWorld()->SpawnActor<AProjectile>(projectileClass, projectileSpawnPointLocation, projectileRotation);
	projectile->SetOwner(this);
}

void ABasePawn::HandleDestruction()
{
	if (deathParticles)
	{
		UGameplayStatics::SpawnEmitterAtLocation(this, deathParticles, GetActorLocation(), GetActorRotation());
	}

	if (deathSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, deathSound, GetActorLocation());
	}

	if (deathCameraShake)
	{
		GetWorld()->GetFirstPlayerController()->ClientStartCameraShake(deathCameraShake);
	}
}