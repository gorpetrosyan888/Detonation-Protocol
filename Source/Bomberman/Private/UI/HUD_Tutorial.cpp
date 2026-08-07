// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD_Tutorial.h"
#include "Blueprint/UserWidget.h"

void AHUD_Tutorial::BeginPlay()
{
	Super::BeginPlay();

	if (WidgetClass)
	{
		CreateWidget<UUserWidget>(GetWorld(), WidgetClass)->AddToViewport();
	}
}
