// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainUI.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"
#include "StructuralAssets/MainGameInstance.h"
#include "BombermanGameMode.h"
#include "StructuralAssets/SavePlayerLocation.h"
#include "NextLVL.h"
#include "ReusableDelay.h"

void UMainUI::NativeConstruct()
{
	Super::NativeConstruct();
	
	GmRef = GetWorld()->GetAuthGameMode<ABombermanGameMode>();

	GetWorld()->GetAuthGameMode<ABombermanGameMode>()
		->OnEnemyDestroyed.AddDynamic(this, &ThisClass::DecreaseEnemyCount);
	GetWorld()->GetAuthGameMode<ABombermanGameMode>()
		->OnServerDestroyed.AddDynamic(this, &ThisClass::DecreaseServerCount);
	

	ShowEnemyCount();
	ShowServerCount();


	if (GmRef)
	{
		TimerTXT->SetText(FText::AsNumber(GmRef->timerSeconds));

		TArray<FText> MissionWord =
		{
			FText::FromString("Your mission is: Destroy"),
			FText::AsNumber(GmRef->currentTaskNum),
			FText::FromString("servers and destroy all enemys")
		};

		MissionText->SetText(FText::Join(FText::FromString(" "), MissionWord));

	}

	
	
	ReusableDelay::StartDelay(GetWorld(), 2, this, "StartDecrease");


	USavePlayerLocation* SaveRef = Cast<USavePlayerLocation>
		(UGameplayStatics::LoadGameFromSlot("TimerSlot", 0));

	if (SaveRef)
	{
		GmRef->timerSeconds = SaveRef->LoadSeconds();
		TimerTXT->SetText(FText::AsNumber(GmRef->timerSeconds));

	}



}



void UMainUI::DecreaseTimer()
{
	GmRef->timerSeconds--;
	TimerTXT->SetText(FText::AsNumber(GmRef->timerSeconds));
	if (GmRef->timerSeconds<=0)
	{
		UGameplayStatics::OpenLevel(GetWorld(),
			FName(UGameplayStatics::GetCurrentLevelName(GetWorld())));
	}
}

void UMainUI::DecreaseEnemyCount()
{
	enemyCounts--;
	EnemyCounterTXT->SetText(FText::AsNumber(enemyCounts));

}

void UMainUI::DecreaseServerCount()
{
	serverCounter--;
	ServerCounterTXT->SetText(FText::AsNumber(serverCounter));

}

void UMainUI::ShowEnemyCount()
{
	for (AActor* Actor : TActorRange<AActor>(GetWorld()))
	{
		if (Actor->ActorHasTag("Enemy"))
		{
			enemyCounts++;
			
		}
	}
	EnemyCounterTXT->SetText(FText::AsNumber(enemyCounts));
}

void UMainUI::ShowServerCount()
{
	for(AActor* Actor : TActorRange<AActor>(GetWorld()))
	{
		if (Actor->ActorHasTag("Server"))
		{
			serverCounter++;
		}
	}
	ServerCounterTXT->SetText(FText::AsNumber(serverCounter));

}

void UMainUI::StartDecrease()
{
	GetWorld()->GetTimerManager().SetTimer
	(timer, this, &ThisClass::DecreaseTimer, 1, true);
}

void UMainUI::ShowMission(int32 count)
{
	MissionText->SetText(FText::AsNumber(count));
}


