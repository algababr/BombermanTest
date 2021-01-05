// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayableCharacter.h"

// Sets default values
APlayableCharacter::APlayableCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UPlayableCharMovementComponent>(ACharacter::CharacterMovementComponentName))
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BombCounter = 1;
}

// Called when the game starts or when spawned
void APlayableCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayableCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayableCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("MoveUp"), this, &APlayableCharacter::MoveUp);
	PlayerInputComponent->BindAxis(FName("MoveSideways"), this, &APlayableCharacter::MoveSideways);
	PlayerInputComponent->BindAction(FName("DropBomb"), EInputEvent::IE_Pressed, this, &APlayableCharacter::DropBomb);
}

void APlayableCharacter::MoveUp(float Value) {

	this->AddMovementInput(FVector(1.0f, 0.0f, 0.0f), Value);
}

void APlayableCharacter::MoveSideways(float Value) {

	this->AddMovementInput(FVector(0.0f, 1.0f, 0.0f), Value);
}

void APlayableCharacter::DropBomb() {

	//Drops the bomb
}

