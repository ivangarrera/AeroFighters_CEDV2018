// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MoveBehaviour.h"
#include "MoveRight.generated.h"

/**
 * 
 */
UCLASS()
class AEROFIGHTERS_API UMoveRight : public UMoveBehaviour
{
	GENERATED_BODY()
	
public:
	UMoveRight();

	void Move(FVector& CurrentPosition, float DeltaTime) override;

	void SetUp(float MoveSpeed, UWorld* World, float MaxTimeWaiting);
	
private:
	bool KeepMoving;
	float TimeWaiting;
	float MaxTimeWaiting;

};