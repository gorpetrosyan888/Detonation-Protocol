// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AttentionSaveWidget.generated.h"

class UButton;
UCLASS()
class BOMBERMAN_API UAttentionSaveWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> YesBtn;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> NoBtn;

	UFUNCTION()
	void YesBtnFunc();

	UFUNCTION()
	void NoBtnFunc();
};
