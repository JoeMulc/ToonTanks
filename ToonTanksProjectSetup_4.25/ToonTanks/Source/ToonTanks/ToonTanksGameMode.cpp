// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "TankPawn.h"
#include "TowerPawn.h"
#include "ToonTanksPlayerController.h"

void AToonTanksGameMode::ActorDied(AActor* deadActor)
{
	if (deadActor == tankRef)
	{
		tankRef->HandleDestruction();

		if (toonTanksPlayerController)
		{
			toonTanksPlayerController->SetPlayerEnabledState(false);
		}
		GameOver(false);
	}
	else if (ATowerPawn* destroyedTower = Cast<ATowerPawn>(deadActor))
	{
		destroyedTower->HandleDestruction();

		targetTowers--;

		if (targetTowers == 0)
		{
			GameOver(true);
		}
	}
}

void AToonTanksGameMode::BeginPlay()
{
	Super::BeginPlay();

	HandleGameStart();

}

void AToonTanksGameMode::HandleGameStart()
{
	targetTowers = GetTotalTowers();

	tankRef = Cast<ATankPawn>(UGameplayStatics::GetPlayerPawn(this, 0));
	toonTanksPlayerController = Cast<AToonTanksPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

	StartGame();

	if (toonTanksPlayerController)
	{
		toonTanksPlayerController->SetPlayerEnabledState(false);

		FTimerHandle PlayerEnableTimerHandle;
		FTimerDelegate PlayerEnableTimerDelegate = FTimerDelegate::CreateUObject( toonTanksPlayerController,
			&AToonTanksPlayerController::SetPlayerEnabledState,
			true);

		GetWorldTimerManager().SetTimer(PlayerEnableTimerHandle, 
			PlayerEnableTimerDelegate, 
			startDelay, 
			false);
	}
}

int32 AToonTanksGameMode::GetTotalTowers()
{
	TArray<AActor*> towerArray;
	UGameplayStatics::GetAllActorsOfClass(this, ATowerPawn::StaticClass(), towerArray);

	return towerArray.Num();
}