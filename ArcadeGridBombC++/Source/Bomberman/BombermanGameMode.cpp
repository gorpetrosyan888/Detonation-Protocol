// Copyright Epic Games, Inc. All Rights Reserved.

#include "BombermanGameMode.h"
#include "StructuralAssets/SaveLevel.h"
#include "Kismet/GameplayStatics.h"

ABombermanGameMode::ABombermanGameMode()
{
	// stub
}

void ABombermanGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	USaveLevel* SaveRef = Cast<USaveLevel>
		(UGameplayStatics::CreateSaveGameObject(USaveLevel::StaticClass()));

	SaveRef->SaveLvlName(FName(UGameplayStatics::GetCurrentLevelName(GetWorld())));
	
}
