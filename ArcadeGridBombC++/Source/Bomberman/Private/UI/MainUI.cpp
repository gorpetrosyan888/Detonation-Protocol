// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainUI.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"
#include "StructuralAssets/MainGameInstance.h"
#include "BombermanGameMode.h"


void UMainUI::NativeConstruct()
{
	Super::NativeConstruct();
	
	ShowEnemyCount();

	UMainGameInstance* GiRef = GetGameInstance()->GetSubsystem<UMainGameInstance>();
	GiRef->OnLevelUpdated.AddDynamic(this, &ThisClass::ShowCurrentLvl);
		
	GiRef->OnLevelUpdated.Broadcast(GiRef->currentLvlNumber);

	GetWorld()->GetAuthGameMode<ABombermanGameMode>()
		->OnEnemyDestroyed.AddDynamic(this, &ThisClass::DecreaseEnemyCount);

	GetWorld()->GetTimerManager().SetTimer
	(timer, this, &ThisClass::DecreaseTimer, 1, true);



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
