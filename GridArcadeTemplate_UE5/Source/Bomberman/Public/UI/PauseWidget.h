// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseWidget.generated.h"

class UButton;
UCLASS()
class BOMBERMAN_API UPauseWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	virtual void NativeConstruct() override;

	

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ResumeBtn;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> MainMenuBtn;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> TutorialBtn;

	UFUNCTION()
	void ResumeFunc();

	UFUNCTION()
	void MainMenuFunc();

	UFUNCTION()
	void TutorialFunc();
	

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> MainMenuWidget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> AttentionWidget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> TutorialWidget;




};
