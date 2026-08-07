// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BombermanMainMenu.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "StructuralAssets/SaveLevel.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Blueprint/UserWidget.h"
#include "BombermanCharacter.h"

void UBombermanMainMenu::NativeConstruct()
{
	Super::NativeConstruct();
	NewGameBTN->OnPressed.AddDynamic(this, &ThisClass::NewGameFunc);
	QuitBtn->OnPressed.AddDynamic(this, &ThisClass::QuitGameFunc);
	ResetBtn->OnPressed.AddDynamic(this, &ThisClass::ResetBtnFunc);
	ContinueBtn->OnPressed.AddDynamic(this, &ThisClass::ContinueBtnFunc);



	
	

	if (UGameplayStatics::DoesSaveGameExist("LevelNameSlot", 0))
	{
		
		ContinueBtn->SetVisibility(ESlateVisibility::Visible);
		ResetBtn->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		
		ContinueBtn->SetVisibility(ESlateVisibility::Collapsed);
		ResetBtn->SetVisibility(ESlateVisibility::Collapsed);

	}
}

void UBombermanMainMenu::NewGameFunc()
{
	UGameplayStatics::OpenLevel(GetWorld(), "LVL1");
	ResetBtnFunc();

	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	PC->SetInputMode(FInputModeGameOnly());
	PC->SetShowMouseCursor(false);
	PC->SetPause(false);

}

void UBombermanMainMenu::ResetBtnFunc()
{
	
	
	for(FString SlotElem : SlotsArray)
	{
		if (UGameplayStatics::DoesSaveGameExist(SlotElem, 0))
		{
			UGameplayStatics::DeleteGameInSlot(SlotElem, 0);
		}

	}

	

	ContinueBtn->SetVisibility(ESlateVisibility::Collapsed);
	ResetBtn->SetVisibility(ESlateVisibility::Collapsed);
}

void UBombermanMainMenu::ContinueBtnFunc()
{
	if (UGameplayStatics::GetCurrentLevelName(GetWorld()) != FString("MainMenuLVL"))
	{
		UWidgetLayoutLibrary::RemoveAllWidgets(this);
		APlayerController* PC = GetWorld()->GetFirstPlayerController();
		PC->SetInputMode(FInputModeGameOnly());
		PC->SetShowMouseCursor(false);
		PC->SetPause(false);
		
	}
	else
	{
		USaveLevel* SaveRef = Cast<USaveLevel>
			(UGameplayStatics::CreateSaveGameObject(USaveLevel::StaticClass()));
		UGameplayStatics::OpenLevel(GetWorld(), SaveRef->LoadLvlName());

	}
}



void UBombermanMainMenu::QuitGameFunc()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), 
		GetWorld()->GetFirstPlayerController(), EQuitPreference::Quit, false);
}
