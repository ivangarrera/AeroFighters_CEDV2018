// Fill out your copyright notice in the Description page of Project Settings.

#include "ShootStraightBehaviour.h"
#include "EnemyLaser.h"
#include "Engine.h"

UShootStraightBehaviour::UShootStraightBehaviour()
{
	this->Timer = 0.f;
}

void UShootStraightBehaviour::Shoot(FVector Location, FRotator Rotation, float DeltaTime)
{
	Timer += DeltaTime;
	if (Timer > ShootTimer)
	{
		FActorSpawnParameters SpawnInfo;
		this->World->SpawnActor <AEnemyLaser>(Location, Rotation, SpawnInfo);
		Timer = 0.f;
	}
}

