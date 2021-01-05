// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlayableCharMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMANCLONE_API UPlayableCharMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:

	virtual void CalcVelocity(float DeltaTime, float Friction, bool bFluid, float BrakingDeceleration) override;
};
