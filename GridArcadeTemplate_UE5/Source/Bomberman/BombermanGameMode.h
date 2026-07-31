// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BombermanGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEnemyDestroyed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnServerDestroyed);

UCLASS(abstract)
class ABombermanGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	/** Constructor */
	ABombermanGameMode();


	

	FOnEnemyDestroyed OnEnemyDestroyed;

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	int32 timerSeconds = 5;


	FOnServerDestroyed OnServerDestroyed;


	UPROPERTY(EditAnywhere)
	int32 currentTaskNum = 20;
};



