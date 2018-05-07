// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "MoveBehaviour.h"
#include "MoveRight.h"
#include "GameFramework/Actor.h"
#include "EnemyManager.generated.h"

UCLASS()
class AEROFIGHTERS_API AEnemyManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	void SpawnEnemy(FVector location, FRotator rotation) const;

	UPROPERTY()
		UStaticMesh* BugShipMesh;

	TSharedPtr<MoveRight> MoveRightObject;

	void Wave0() const;

};
