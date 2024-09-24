// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "TankPawn.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATankPawn : public ABasePawn
{
	GENERATED_BODY()

public:
	ATankPawn();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Tick(float DeltaTime) override;

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true")) class USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true")) class UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere, Category = "TankStats", meta = (AllowPrivateAccess = "true")) float speed;

	UPROPERTY(EditAnywhere, Category = "TankStats", meta = (AllowPrivateAccess = "true")) float turnSpeed;

	void Move(float value);

	void Turn(float value);

	APlayerController* playerControllerRef;

};
