// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MainGameInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLevelUpdated, int32, UpdatedLvl);
UCLASS()
class BOMBERMAN_API UMainGameInstance : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	

	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;

	FOnLevelUpdated OnLevelUpdated;

	UFUNCTION()
	void ShowLvlNumber(int32 value);

	UPROPERTY()
	int32 currentLvlNumber = 1;
};
