// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/AttentionSaveWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"

void UAttentionSaveWidget::NativeConstruct()
{
	Super::NativeConstruct();

	YesBtn->OnClicked.AddDynamic(this, &ThisClass::YesBtnFunc);
	NoBtn->OnClicked.AddDynamic(this, &ThisClass::NoBtnFunc);
}

void UAttentionSaveWidget::YesBtnFunc()
{

	UGameplayStatics::OpenLevel(GetWorld(), "MainMenuLVL");

}

void UAttentionSaveWidget::NoBtnFunc()
{
	RemoveFromParent();

}
