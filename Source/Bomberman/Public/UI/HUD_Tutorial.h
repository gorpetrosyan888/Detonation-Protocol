// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HUD_Tutorial.generated.h"


UCLASS()
class BOMBERMAN_API AHUD_Tutorial : public AHUD
{
	GENERATED_BODY()
public:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> WidgetClass;
};
