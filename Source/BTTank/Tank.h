// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h"
#include "Engine/Classes/Components/InputComponent.h"
#include "Tank.generated.h"

UCLASS()
class BTTANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UTankAimingComponent* TankAimingComponent = nullptr;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelRefrence(UStaticMeshComponent* BarrelToSet);
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void AimAt(FVector HitLocation);

private:


};
