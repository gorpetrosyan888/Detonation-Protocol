// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD_MainMenu.h"
#include "Blueprint/UserWidget.h"


void AHUD_MainMenu::BeginPlay()
{
	if (WidgetToOpen)
	{
		CreateWidget<UUserWidget>(GetWorld(), WidgetToOpen)->AddToViewport();
	}
}
