// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayableCharMovementComponent.h"
#include "PlayableCharacter.generated.h"

UCLASS()
class BOMBERMANCLONE_API APlayableCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	// Sets default values for this character's properties
	APlayableCharacter(const FObjectInitializer& ObjectInitializer);
	
	UFUNCTION(BlueprintCallable, Category = "Movement")
		FORCEINLINE class UPlayableCharMovementComponent* GetMyMovementComponent() const { return CustomCharacterMovementComp; };

	void MoveUp(float Value);

	void MoveSideways(float Value);

	void DropBomb();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
		int32 BombCounter;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY()
		UPlayableCharMovementComponent* CustomCharacterMovementComp;
};
