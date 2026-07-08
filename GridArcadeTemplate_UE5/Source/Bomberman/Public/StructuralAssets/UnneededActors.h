// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "UnneededActors.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_API UUnneededActors : public USaveGame
{
	GENERATED_BODY()
public:

	UPROPERTY()
	TArray<FGuid> UnneededActorsArray;

	UPROPERTY()
	TArray<FGuid> AlreadyNextLvl;
};
