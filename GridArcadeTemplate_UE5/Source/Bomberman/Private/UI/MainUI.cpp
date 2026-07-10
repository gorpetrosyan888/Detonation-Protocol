// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainUI.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"
#include "StructuralAssets/MainGameInstance.h"
#include "BombermanGameMode.h"
#include "StructuralAssets/SavePlayerLocation.h"

void UMainUI::NativeConstruct()
{
	Super::NativeConstruct();
	
	ShowEnemyCount();

	UMainGameInstance* GiRef = GetGameInstance()->GetSubsystem<UMainGameInstance>();
	GiRef->OnLevelUpdated.AddDynamic(this, &ThisClass::ShowCurrentLvl);
		
	GiRef->OnLevelUpdated.Broadcast(GiRef->currentLvlNumber);

	GetWorld()->GetAuthGameMode<ABombermanGameMode>()
		->OnEnemyDestroyed.AddDynamic(this, &ThisClass::DecreaseEnemyCount);

	TimerTXT->SetText(FText::AsNumber(timerSeconds));


	GetWorld()->GetTimerManager().SetTimer
	(timer, this, &ThisClass::DecreaseTimer, 1, true);


	USavePlayerLocation* SaveRef = Cast<USavePlayerLocation>
		(UGameplayStatics::LoadGameFromSlot("TimerSlot", 0));

	if (SaveRef)
	{
		timerSeconds = SaveRef->LoadSeconds();
		TimerTXT->SetText(FText::AsNumber(timerSeconds));

	}
}

void UMainUI::NativeDestruct()
{
	Super::NativeDestruct();

	USavePlayerLocation* SaveRef = Cast<USavePlayerLocation>
		(UGameplayStatics::CreateSaveGameObject(USavePlayerLocation::StaticClass()));

	if (SaveRef)
	{
		SaveRef->SaveSeconds(timerSeconds);
	}


}

void UMainUI::DecreaseTimer()
{
	timerSeconds--;
	TimerTXT->SetText(FText::AsNumber(timerSeconds));
	if (timerSeconds<=0)
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

void UMainUI::ShowCurrentLvl(int32 value)
{
	CurrentLvlNumber->SetText(FText::AsNumber(value));
}
