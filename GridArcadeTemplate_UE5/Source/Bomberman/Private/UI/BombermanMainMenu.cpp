// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BombermanMainMenu.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "StructuralAssets/SaveLevel.h"

void UBombermanMainMenu::NativeConstruct()
{
	Super::NativeConstruct();
	NewGameBTN->OnPressed.AddDynamic(this, &ThisClass::NewGameFunc);
	QuitBtn->OnPressed.AddDynamic(this, &ThisClass::QuitGameFunc);
	ResetBtn->OnPressed.AddDynamic(this, &ThisClass::ResetBtnFunc);
	ContinueBtn->OnPressed.AddDynamic(this, &ThisClass::ContinueBtnFunc);


	USaveLevel* SaveRef = Cast<USaveLevel>
		(UGameplayStatics::CreateSaveGameObject(USaveLevel::StaticClass()));
	GEngine->AddOnScreenDebugMessage
	(-1, 2, FColor::Red, FString::FromInt(SaveRef->LoadLvlNumber()));
	




	if (UGameplayStatics::DoesSaveGameExist("LevelNameSlot", 0) && 
		UGameplayStatics::DoesSaveGameExist("LevelNumberSlot", 0))
	{
		int32 lvlNum = SaveRef->LoadLvlNumber();
		
		switch (lvlNum)
		{
		case 1:
			Level1TXT->SetVisibility(ESlateVisibility::Visible);

			break;
		case 2:
			Level1TXT->SetVisibility(ESlateVisibility::Visible);
			Level2TXT->SetVisibility(ESlateVisibility::Visible);
			break;
		case 3:
			Level1TXT->SetVisibility(ESlateVisibility::Visible);
			Level2TXT->SetVisibility(ESlateVisibility::Visible);
			Level3TXT->SetVisibility(ESlateVisibility::Visible);
			break;
		default:
			break;
		}

		

		ContinueBtn->SetVisibility(ESlateVisibility::Visible);
		ResetBtn->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		Level1TXT->SetVisibility(ESlateVisibility::Collapsed);
		Level2TXT->SetVisibility(ESlateVisibility::Collapsed);
		Level3TXT->SetVisibility(ESlateVisibility::Collapsed);

		ContinueBtn->SetVisibility(ESlateVisibility::Collapsed);
		ResetBtn->SetVisibility(ESlateVisibility::Collapsed);

	}
}

void UBombermanMainMenu::NewGameFunc()
{
	ResetBtnFunc();
	UGameplayStatics::OpenLevel(GetWorld(), "LVL1");
}

void UBombermanMainMenu::ResetBtnFunc()
{
	UGameplayStatics::DeleteGameInSlot("LevelNameSlot", 0);
	UGameplayStatics::DeleteGameInSlot("LevelNumberSlot", 0);
	UGameplayStatics::DeleteGameInSlot("UnneededSlot", 0);
	UGameplayStatics::DeleteGameInSlot("TimerSlot", 0);
	UGameplayStatics::DeleteGameInSlot("LocationSlot", 0);


	Level1TXT->SetVisibility(ESlateVisibility::Collapsed);
	Level2TXT->SetVisibility(ESlateVisibility::Collapsed);
	Level3TXT->SetVisibility(ESlateVisibility::Collapsed);

	ContinueBtn->SetVisibility(ESlateVisibility::Collapsed);
	ResetBtn->SetVisibility(ESlateVisibility::Collapsed);
}

void UBombermanMainMenu::ContinueBtnFunc()
{
	USaveLevel* SaveRef = Cast<USaveLevel>
		(UGameplayStatics::CreateSaveGameObject(USaveLevel::StaticClass()));
	UGameplayStatics::OpenLevel(GetWorld(), SaveRef->LoadLvlName());
}



void UBombermanMainMenu::QuitGameFunc()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), 
		GetWorld()->GetFirstPlayerController(), EQuitPreference::Quit, false);
}
