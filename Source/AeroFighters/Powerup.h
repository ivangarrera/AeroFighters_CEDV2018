// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Powerup.generated.h"

UCLASS()
class AEROFIGHTERS_API APowerup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APowerup();
	void SetUp(float MoveSpeed, UWorld* World);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

	float MoveSpeed;
	//Variables for controlling the areas where the player can move to
	UPROPERTY()
		TWeakObjectPtr<AActor> TopMovableArea;
	UPROPERTY()
		TWeakObjectPtr<AActor> BottomMovableArea;
	UPROPERTY()
		TWeakObjectPtr<AActor> RightMovableArea;
	UPROPERTY()
		TWeakObjectPtr<AActor> LeftMovableArea;

	virtual void SetStaticMeshAsset(UStaticMesh* StaticMeshAsset);
	UPROPERTY()
		UStaticMeshComponent* StaticMeshComponent;

	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	virtual void Move(float DeltaTime);
	FVector CameraSpeed;
	FVector Direction;
	float RandomFloat(float a, float b);
};