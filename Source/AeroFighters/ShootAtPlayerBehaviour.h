/* Copyright (C) 2018 Iv�n Garc�a, Juan Jos� Corroto and Javier C�rdoba - All Rights Reserved
* You may use, distribute and modify this code under the
* terms of the GNU GPLv3 license.
*
* You should have received a copy of the GNU GPLv3 license with
* this file. If not, please write to: ivan.garcia16@alu.uclm.es
*/

#pragma once

#include "CoreMinimal.h"
#include "ProjectileBehaviour.h"
#include "UObject/NoExportTypes.h"
#include "ShootAtPlayerBehaviour.generated.h"

/**
 * 
 */
UCLASS()
class AEROFIGHTERS_API UShootAtPlayerBehaviour : public UProjectileBehaviour
{
	GENERATED_BODY()
	
public:
	UShootAtPlayerBehaviour();
	void Shoot(UWorld* World, FVector Location, FRotator Rotation, float DeltaTime) override;
};
