// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include"Tank.h"
#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Runtime/Engine/Public/DrawDebugHelpers.h"
#include "Camera/PlayerCameraManager.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BTTANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:

	ATankPlayerController();
		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;

		
private:
	// Aims the barrel towards the cossHair
	void AimToWardsCrossHair();
	ATank* GetControlledTank() const;
	bool GetSightRayHitLocation(FVector& OutHitlocation) const;  // return true if hit landscape
	//FVector2D ScreenLocation(float x, float y);
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;


	UPROPERTY(EditAnyWhere)
	float CrossHairXLoc = 0.5;
	UPROPERTY(EditAnyWhere)
	float CrossHairYLoc = 0.3333;
	UPROPERTY(EditAnyWhere)
		float LineTraceRange = 1000000;

	
};
