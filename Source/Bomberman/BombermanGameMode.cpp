// Copyright Epic Games, Inc. All Rights Reserved.

#include "BombermanGameMode.h"
#include "StructuralAssets/SaveLevel.h"
#include "Kismet/GameplayStatics.h"
#include "StructuralAssets/UnneededActors.h"
#include "StructuralAssets/SavePlayerLocation.h"
#include "EngineUtils.h"
#include "UnneededComponent.h"
#include "Kismet/KismetSystemLibrary.h"

ABombermanGameMode::ABombermanGameMode()
{
	// stub
}



void ABombermanGameMode::BeginPlay()
{
	Super::BeginPlay();

	UKismetSystemLibrary::ExecuteConsoleCommand(GetWorld(), "DisableAllScreenMessages");

	DealWithUnneededActors();

	if (GetWorld()->GetFirstPlayerController()->GetPawn())
	{
		

		USavePlayerLocation* SaveLocRef = Cast<USavePlayerLocation>
			(UGameplayStatics::LoadGameFromSlot("LocationSlot", 0));
		if (SaveLocRef)
		{
			GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorLocation
			(SaveLocRef->LoadLocation());
		}
	}
	

}

void ABombermanGameMode::DealWithUnneededActors()
{
	UUnneededActors* SaveRef = Cast<UUnneededActors>
		(UGameplayStatics::LoadGameFromSlot("UnneededSlot", 0));
	if (SaveRef)
	{
		for (AActor* Actor : TActorRange<AActor>(GetWorld()))
		{
			if (UUnneededComponent* CompRef = Actor->FindComponentByClass<UUnneededComponent>())
			{
				if (CompRef)
				{
					if (SaveRef->UnneededActorsArray.Contains(Actor->GetFName()))
					{
						Actor->Destroy();
					}
				}
			}
		}
	}



}
