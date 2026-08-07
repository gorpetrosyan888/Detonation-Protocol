// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PauseWidget.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"

void UPauseWidget::NativeConstruct()
{
	Super::NativeConstruct();

	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	PC->SetPause(true);
	PC->SetInputMode(FInputModeGameAndUI());
	PC->SetShowMouseCursor(true);


	ResumeBtn->OnClicked.AddDynamic(this, &ThisClass::ResumeFunc);
	
	MainMenuBtn->OnClicked.AddDynamic(this, &ThisClass::MainMenuFunc);

	TutorialBtn->OnClicked.AddDynamic(this, &ThisClass::TutorialFunc);
}



void UPauseWidget::ResumeFunc()
{
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	PC->SetPause(false);
	PC->SetInputMode(FInputModeGameOnly());
	PC->SetShowMouseCursor(false);
	RemoveFromParent();
}



void UPauseWidget::MainMenuFunc()
{

	if (UGameplayStatics::DoesSaveGameExist("LevelNameSlot", 0))
	{
		CreateWidget<UUserWidget>(GetWorld(), MainMenuWidget)->AddToViewport();

	}
	else
	{

		CreateWidget<UUserWidget>(GetWorld(), AttentionWidget)->AddToViewport();
	}
}

void UPauseWidget::TutorialFunc()
{
	if (TutorialWidget)
	{
		CreateWidget<UUserWidget>(GetWorld(), TutorialWidget)->AddToViewport();


		APlayerController* PC = GetWorld()->GetFirstPlayerController();
		PC->SetInputMode(FInputModeGameOnly());
		PC->SetShowMouseCursor(false);
	}
}
