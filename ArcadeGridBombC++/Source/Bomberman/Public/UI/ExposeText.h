// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ExposeText.generated.h"

class UTextBlock;

UCLASS()
class BOMBERMAN_API UExposeText : public UUserWidget
{
	GENERATED_BODY()
public:

	virtual void NativeConstruct() override;


	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	TObjectPtr<UTextBlock> ExposeTXT;

	UPROPERTY()
	FText text;

};
