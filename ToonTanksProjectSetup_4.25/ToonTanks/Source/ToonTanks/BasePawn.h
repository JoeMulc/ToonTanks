// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	void HandleDestruction();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true")) class UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true")) UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true")) UStaticMeshComponent* TurretMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true")) USceneComponent* projectileSpawnPoint;


	UPROPERTY(EditAnywhere, Category = "Components") TSubclassOf<class AProjectile> projectileClass;

	UPROPERTY(EditAnywhere) UParticleSystem* deathParticles;

	UPROPERTY(EditAnywhere, Category = "Sound") class USoundBase* deathSound;

	UPROPERTY(EditAnywhere) TSubclassOf<class UCameraShakeBase> deathCameraShake;

protected:

	void RotateTurret(FVector target);
	void Fire();


public:	


	// Called to bind functionality to input

};
