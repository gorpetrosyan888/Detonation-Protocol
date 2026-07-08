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


	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	FOnEnemyDestroyed OnEnemyDestroyed;

	virtual void BeginPlay() override;
};



