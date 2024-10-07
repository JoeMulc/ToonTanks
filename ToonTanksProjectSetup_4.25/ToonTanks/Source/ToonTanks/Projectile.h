// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true")) UStaticMeshComponent* ProjectileMesh;
	UPROPERTY(VisibleAnywhere) UProjectileMovementComponent* projectileMovement;
	UPROPERTY(VisibleAnywhere) UParticleSystemComponent* ParticleComponent;

	UPROPERTY(EditAnywhere) float damage = 50.f;
	UPROPERTY(EditAnywhere) class UParticleSystem* hitParticles;

	UPROPERTY(EditAnywhere, Category = "Sound") class USoundBase* LaunchSound;

	UPROPERTY(EditAnywhere, Category = "Sound") class USoundBase* HitSound;

	UPROPERTY(EditAnywhere) TSubclassOf<class UCameraShakeBase> HitCameraShake;

private:
	
	UFUNCTION() void OnHit(UPrimitiveComponent* hitComp, AActor* otherActor, UPrimitiveComponent* otherComp, FVector normalImpulse, const FHitResult& hit);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
