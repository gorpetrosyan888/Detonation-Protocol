// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BombermanGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEnemyDestroyed);

UCLASS(abstract)
class ABombermanGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	/** Constructor */
	ABombermanGameMode();


	

	FOnEnemyDestroyed OnEnemyDestroyed;

	virtual void BeginPlay() override;

	UPROPERTY()
	int32 timerSeconds = 180;



	UPROPERTY(EditAnywhere)
	int32 currentTaskNum = 20;
};



