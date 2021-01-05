// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayableCharMovementComponent.h"

void UPlayableCharMovementComponent::CalcVelocity(float DeltaTime, float Friction, bool bFluid, float BrakingDeceleration)
{
	// There may/may-not be some times you want to call super.
	// have a look through CalcVelocity to find out. We'll call super here just in case.
	Super::CalcVelocity(DeltaTime, Friction, bFluid, BrakingDeceleration);

	if (Acceleration.IsZero())
	{
		// Stop movement
		Velocity = FVector::ZeroVector;
	}
	else
	{
		// Set velocity to max speed in the direction of acceleration (ignoring magnitude)
		Velocity = GetMaxSpeed() * Acceleration.GetSafeNormal();
	}
}