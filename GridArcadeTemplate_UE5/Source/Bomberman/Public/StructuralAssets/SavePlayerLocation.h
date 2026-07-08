// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SavePlayerLocation.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_API USavePlayerLocation : public USaveGame
{
	GENERATED_BODY()
public:

	UFUNCTION()
	FVector SaveLocation(FVector location);

	UFUNCTION()
	FVector LoadLocation();

	UPROPERTY()
	FVector NewLocation = FVector(-3568.687029,  -3487.987403,  91.999895);


	UFUNCTION()
	int32 SaveSeconds(int32 value);

	UFUNCTION()
	int32 LoadSeconds();

	UPROPERTY()
	int32 newSeconds = 180;
};
