// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SaveLevel.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_API USaveLevel : public USaveGame
{
	GENERATED_BODY()
public:

	UFUNCTION()
	FName SaveLvlName(FName newName);

	UFUNCTION()
	FName LoadLvlName();

	UPROPERTY()
	FName newLvlName;




};
