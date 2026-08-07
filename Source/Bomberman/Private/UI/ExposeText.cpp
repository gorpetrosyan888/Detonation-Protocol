// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ExposeText.h"
#include "Components/TextBlock.h"

void UExposeText::NativeConstruct()
{
	Super::NativeConstruct();


	ExposeTXT->SetText(text);
}
