// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "../Public/TankAIController.h"

 
ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn(); // get the player controller (Player playing)
	if (!PlayerPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT(" PlayerTank  cannot be found!! "));

		return NULL;
	}
	return Cast<ATank>(PlayerPawn);
}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn()); // cast it to a tank and get the pawn
}

void ATankAIController::BeginPlay()
{                                             
	// get the tank
	// so we can get the ai controller working
	Super::BeginPlay();
	auto PlayerPawn = GetPlayerTank();

	if (PlayerPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("	AI controller found! %s"), *( PlayerPawn->GetName()));
	}
	// print the namne
	else
	{
		UE_LOG(LogTemp, Warning, TEXT(" Ai controller  cannot find player!! "));

	}
	// get the player controller
	

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// get playerTank
	if (GetPlayerTank())
	{
		// aim at player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		//UE_LOG(LogTemp, Warning, TEXT(" AI tank aiming at: %s! ***"));
	}
	
}
