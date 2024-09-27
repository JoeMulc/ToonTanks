// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "TowerPawn.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATowerPawn : public ABasePawn
{
	GENERATED_BODY()

public:
	virtual  void  Tick(float  deltaTime);

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

	class ATankPawn* tankRef;

	UPROPERTY(EditAnywhere, Category = "TurretStats", meta = (AllowPrivateAccess = "true")) float turretRange = 1000.f;
	UPROPERTY(EditAnywhere, Category = "TurretStats", meta = (AllowPrivateAccess = "true"))  float  fireRate =  2.f;

	FTimerHandle fireRateTimerHandle;
	
	void CheckFireCondition();

	bool CheckDistance();
};
