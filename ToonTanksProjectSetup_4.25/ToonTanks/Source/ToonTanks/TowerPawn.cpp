// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerPawn.h"
#include "Kismet/GameplayStatics.h"
#include "TankPawn.h"
#include "TimerManager.h"

void ATowerPawn::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	if (CheckDistance())
	{
		RotateTurret(tankRef->GetActorLocation());
	}
}

void ATowerPawn::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}

void ATowerPawn::BeginPlay() 
{
	Super::BeginPlay();

	tankRef = Cast<ATankPawn>(UGameplayStatics::GetPlayerPawn(this, 0));

	GetWorldTimerManager().SetTimer(fireRateTimerHandle, this, &ATowerPawn::CheckFireCondition, fireRate, true);
}

void ATowerPawn::CheckFireCondition()
{
	if (tankRef == nullptr)
	{
		return;
	}
	if (CheckDistance() && tankRef->bAlive)
	{
		Fire();
	}
}

bool ATowerPawn::CheckDistance()
{
	if (tankRef)
	{
		float distance = FVector::Dist(GetActorLocation(), tankRef->GetActorLocation());

		if (distance <= turretRange)
		{
			return true;
		}
	}
	return false;
}