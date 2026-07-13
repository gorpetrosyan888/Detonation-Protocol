// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainUI.generated.h"

class UTextBlock;
class ABombermanGameMode;

UCLASS()
class BOMBERMAN_API UMainUI : public UUserWidget
{
	GENERATED_BODY()
public:

	virtual void NativeConstruct() override;



	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	TObjectPtr<UTextBlock> TimerTXT;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	TObjectPtr<UTextBlock> EnemyCounterTXT;

	


	UPROPERTY()
	int32 enemyCounts = 0;

	UFUNCTION()
	void DecreaseTimer();

	UFUNCTION()
	void DecreaseEnemyCount();

	UFUNCTION()
	void ShowEnemyCount();



	FTimerHandle timer;



	UPROPERTY()
	TObjectPtr<ABombermanGameMode> GmRef;

	UFUNCTION()
	void StartDecrease();


	UFUNCTION()
	void ShowMission(int32 count);

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> MissionText;

};
