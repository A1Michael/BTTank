// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

// print controlled tank

ATankPlayerController::ATankPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	AActor* controlledTank = GetControlledTank();//COULD USE AUTO
	UE_LOG(LogTemp, Warning, TEXT(" Tank successfully spawned!! %s"), *controlledTank->GetName());
}

void ATankPlayerController::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
	// aimTowardsCrossHair
	AimToWardsCrossHair();

}

ATank* ATankPlayerController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());// cast the pawn into a tank class
}

void ATankPlayerController::AimToWardsCrossHair()
{
	if (!GetControlledTank())
{
		return;
	}

	FVector HitLocation; // OUT Param
		// getworld location of linetrace though crosshair
	if (GetSightRayHitLocation(HitLocation)) // has "side-effect" is going to line trace
	{
		// call aim at from tank.h
		GetControlledTank()->AimAt(HitLocation);
	}
}
// get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector & OutHitlocation) const
{
	// find the crosshair pos
	int32 ViewPortSizeY, ViewPortSizeX;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);// get viewport size
	
	auto ScreenLocation = FVector2D(ViewPortSizeX * CrossHairXLoc, ViewPortSizeY * CrossHairYLoc);
	UE_LOG(LogTemp, Warning, TEXT("screen locaton : %s"), *ScreenLocation.ToString());
	FVector CameraWorldLocation;
	FVector WorldDirection;
	// deproject screen position of the crosshair to a world direction
	if (DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation, WorldDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look irection locaton : %s"), *WorldDirection.ToString());

	}
	FVector LookDirection;
	if(GetLookDirection(ScreenLocation, LookDirection))
	{
		// Line-trace along that look direction and see what we hit(Up to max range)
		GetLookVectorHitLocation( LookDirection, OutHitlocation);
	}
	return true;
}
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CaneraWorldLocation;// to be discarded

	// deproject screen position of the crosshair to a world direction
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CaneraWorldLocation,
		LookDirection
	);

	
	

	
	
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{

	FHitResult HitResult;
	auto starLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = starLocation + (LookDirection * LineTraceRange);
	FVector Out_HitLocation;

	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		starLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility

	)) {
		// set hit location
		HitLocation =  HitResult.Location;
		return true;
	}
	else
	{
		return false;
	}
	
	

	


}

/*FVector2D ATankPlayerController::ScreenLocation(float x, float y)
{

	return x * y;
}*/





