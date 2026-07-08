// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PauseWidget.h"
#include "StructuralAssets/SavePlayerLocation.h"
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
	SaveBtn->OnClicked.AddDynamic(this, &ThisClass::SaveFunc);
	MainMenuBtn->OnClicked.AddDynamic(this, &ThisClass::MainMenuFunc);
}

void UPauseWidget::ResumeFunc()
{
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	PC->SetPause(false);
	PC->SetInputMode(FInputModeGameOnly());
	PC->SetShowMouseCursor(false);
	RemoveFromParent();
}

void UPauseWidget::SaveFunc()
{
	USavePlayerLocation* SaveRef = Cast<USavePlayerLocation>
		(UGameplayStatics::CreateSaveGameObject(USavePlayerLocation::StaticClass()));

	SaveRef->SaveLocation(GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation());
}

void UPauseWidget::MainMenuFunc()
{
	UGameplayStatics::OpenLevel(GetWorld(), "MainMenuLVL");
}
