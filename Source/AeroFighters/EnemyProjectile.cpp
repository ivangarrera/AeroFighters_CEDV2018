// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyProjectile.h"
#include "Engine.h"
#include "PlayerMissile.h"
#include "PlayerLaser.h"
#include "Components/CapsuleComponent.h"
#include "PlayerCharacter.h"

// Sets default values
AEnemyProjectile::AEnemyProjectile() : Super()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	auto BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));

	BoxCollision->SetCollisionProfileName(TEXT("OverlapAll"));
	BoxCollision->SetupAttachment(RootComponent);
	BoxCollision->bGenerateOverlapEvents = true;
	BoxCollision->SetWorldScale3D(FVector(0.1f, 0.1f, 0.1f));
	BoxCollision->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));
	StaticMesh->SetupAttachment(RootComponent);

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AEnemyProjectile::OnOverlap);
}

// Called when the game starts or when spawned
void AEnemyProjectile::BeginPlay()
{
	Super::BeginPlay();

	// Bind an action to destroy the projectile if the character spawns a bomb
	// The action is a lambda function that destroys the projectile
	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetCharacter());
	if (PlayerCharacter != nullptr)
	{
		PlayerCharacter->myDiscardEnemyShootsDelegate.AddDynamic(this, &AEnemyProjectile::OnBomb);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, FString(TEXT("[EnemyProjectile.cpp] - PlayerCharacter is nullptr")));
	}
}

void AEnemyProjectile::OnBomb()
{
	this->Destroy();
}

// Called every frame
void AEnemyProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Check if the projectile has to be destroyed
	if (StaticMesh->GetComponentLocation().X < BottomMovableArea->GetActorLocation().X)
	{
		this->Destroy();
	}

	// The basic movement (falling) is the same for all enemy projectile types
	FVector NewLocation = StaticMesh->GetComponentLocation() + (StaticMesh->GetForwardVector() * GetSpeed() * DeltaTime);
	StaticMesh->SetWorldLocation(NewLocation);
	//StaticMesh->SetWorldRotation(FRotator(90.f, 0.f, 0.f));
}

void AEnemyProjectile::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, FString(TEXT("[EnemyProjectile.cpp] - OnHit")));
		if (OtherActor->GetClass()->IsChildOf(APlayerLaser::StaticClass()))
		{
			this->Destroy();
		}
	}
}

