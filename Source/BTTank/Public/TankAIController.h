// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include"Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BTTANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
private:

	ATank* GetPlayerTank()const;
	ATank* GetControlledTank() const;
};
