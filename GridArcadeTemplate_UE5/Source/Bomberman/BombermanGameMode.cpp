// Copyright Epic Games, Inc. All Rights Reserved.

#include "BombermanGameMode.h"
#include "StructuralAssets/SaveLevel.h"
#include "Kismet/GameplayStatics.h"
#include "StructuralAssets/UnneededActors.h"
#include "StructuralAssets/SavePlayerLocation.h"
#include "EngineUtils.h"

ABombermanGameMode::ABombermanGameMode()
{
	// stub
}



void ABombermanGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (GetWorld()->GetFirstPlayerController()->GetPawn())
	{
		UUnneededActors* SaveRef = Cast<UUnneededActors>
			(UGameplayStatics::LoadGameFromSlot("UnneededSlot", 0));
		if (SaveRef)
		{
			for (AActor* Actor : TActorRange<AActor>(GetWorld()))
			{
				if (SaveRef->UnneededActorsArray.Contains(Actor->GetActorGuid()))
				{
					Actor->Destroy();
				}
			}
		}

		USavePlayerLocation* SaveLocRef = Cast<USavePlayerLocation>
			(UGameplayStatics::LoadGameFromSlot("LocationSlot", 0));
		if (SaveLocRef)
		{
			GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorLocation
			(SaveLocRef->LoadLocation());
		}
	}
	

}
