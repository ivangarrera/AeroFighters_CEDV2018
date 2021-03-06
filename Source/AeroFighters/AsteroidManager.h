/* Copyright (C) 2018 Iv�n Garc�a, Juan Jos� Corroto and Javier C�rdoba - All Rights Reserved
* You may use, distribute and modify this code under the
* terms of the GNU GPLv3 license.
*
* You should have received a copy of the GNU GPLv3 license with
* this file. If not, please write to: ivan.garcia16@alu.uclm.es
*/

#pragma once

#include "CoreMinimal.h"
#include "Asteroid.h"
#include "EnemyAsteroid.h"
#include "GameFramework/Actor.h"
#include "AsteroidManager.generated.h"

UCLASS()
class AEROFIGHTERS_API AAsteroidManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAsteroidManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere, Category = "Decorative Asteroids")
		int AsteroidCount;

	UPROPERTY(EditAnywhere, Category = "Decorative Asteroids")
		float XInfLimit;

	UPROPERTY(EditAnywhere, Category = "Decorative Asteroids")
		float XSupLimit;

	UPROPERTY(EditAnywhere, Category = "Decorative Asteroids")
		float YInfLimit;

	UPROPERTY(EditAnywhere, Category = "Decorative Asteroids")
		float YSupLimit;

	UPROPERTY(EditAnywhere, Category = "Decorative Asteroids")
		float ZInfLimit;

	UPROPERTY(EditAnywhere, Category = "Decorative Asteroids")
		float ZSupLimit;

	UPROPERTY(EditAnywhere, Category = "Decorative Asteroids")
		float InfScale;

	UPROPERTY(EditAnywhere, Category = "Decorative Asteroids")
		float SupScale;

	UPROPERTY(EditAnywhere, Category = "Decorative Asteroids")
		float RotDriftSup;

	UPROPERTY(EditAnywhere, Category = "Decorative Asteroids")
		float RotDriftSpeed;

	UPROPERTY(EditAnywhere, Category = "Basic")
		TSubclassOf<class AAsteroid> AsteroidType;

	UPROPERTY(EditAnywhere, Category = "Basic")
		float RefreshFrequency;

	UPROPERTY(EditAnywhere, Category = "Basic")
		float LookaheadSpawnDistance;

private:
	float RandomFloat(float a, float b);
	void GenerateRandomPositions();
	bool IsPositionOnScreen(FVector position);
	AAsteroid* SpawnRandomAsteroid(FVector position);
	void SpawnVisibleAsteroids();
	void DespawnInvisibleAsteroids();

	AAsteroid* Prototype;
	TArray<FVector> AsteroidPositions;
	TArray<AAsteroid*> SpawnedAsteroids;
	FVector ClosestAsteroid;
	FVector2D ViewportSize;
	float AccumulatedDeltaTime;
};
