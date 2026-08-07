// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD_Main.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "StructuralAssets/SaveLevel.h"

void AHUD_Main::BeginPlay()
{
	Super::BeginPlay();

	if (MainWidgetClass)
	{
		CreateWidget<UUserWidget>(GetWorld(), MainWidgetClass)->AddToViewport();
	}

	if (!UGameplayStatics::DoesSaveGameExist("TutorialSlot", 0))
	{
		

		CreateWidget<UUserWidget>(GetWorld(), TutorialWidgetClass)->AddToViewport(10);

		
	}
}
