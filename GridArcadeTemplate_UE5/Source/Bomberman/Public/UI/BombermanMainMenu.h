// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BombermanMainMenu.generated.h"

class UButton;
class UTextBlock;
UCLASS()
class BOMBERMAN_API UBombermanMainMenu : public UUserWidget
{
	GENERATED_BODY()
public:

	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	TObjectPtr<UButton> NewGameBTN;


	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	TObjectPtr<UButton> QuitBtn;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	TObjectPtr<UButton> ResetBtn;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	TObjectPtr<UButton> ContinueBtn;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	TObjectPtr<UTextBlock> Level1TXT;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	TObjectPtr<UTextBlock> Level2TXT;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	TObjectPtr<UTextBlock> Level3TXT;

	UFUNCTION()
	void NewGameFunc();

	UFUNCTION()
	void ResetBtnFunc();

	UFUNCTION()
	void ContinueBtnFunc();



	UFUNCTION()
	void QuitGameFunc();
};
