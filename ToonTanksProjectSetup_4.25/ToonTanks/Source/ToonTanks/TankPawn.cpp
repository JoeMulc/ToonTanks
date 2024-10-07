// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

ATankPawn::ATankPawn()
{
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);
}

void ATankPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATankPawn::Move);

	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATankPawn::Turn);

	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ATankPawn::Fire);
}

void ATankPawn::BeginPlay()
{
	Super::BeginPlay();

	playerControllerRef = Cast<APlayerController>(GetController());
}


void ATankPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (playerControllerRef)
	{
		FHitResult hitResult;
		playerControllerRef->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, hitResult);

		DrawDebugSphere(GetWorld(), hitResult.ImpactPoint, 50.f, 4, FColor::Blue);
		RotateTurret(hitResult.ImpactPoint);
	}

}

void ATankPawn::HandleDestruction()
{
	Super::HandleDestruction();
	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);

	bAlive = false;
}


void  ATankPawn::Move(float value)
{
	FVector  deltaLocation = FVector::ZeroVector;
	deltaLocation.X = value * speed * UGameplayStatics::GetWorldDeltaSeconds(this);

	AddActorLocalOffset(deltaLocation, true);
}

void ATankPawn::Turn(float value)
{
	FRotator deltaRotation = FRotator::ZeroRotator;

	deltaRotation.Yaw = value * turnSpeed * UGameplayStatics::GetWorldDeltaSeconds(this);

	AddActorLocalRotation(deltaRotation, true);

}
