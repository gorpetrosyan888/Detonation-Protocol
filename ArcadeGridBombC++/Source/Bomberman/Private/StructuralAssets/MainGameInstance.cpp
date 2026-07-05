// Fill out your copyright notice in the Description page of Project Settings.


#include "StructuralAssets/MainGameInstance.h"

void UMainGameInstance::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

bool UMainGameInstance::ShouldCreateSubsystem(UObject* Outer) const
{
	return true;
}

void UMainGameInstance::ShowLvlNumber(int32 value)
{
	currentLvlNumber = value;
	OnLevelUpdated.Broadcast(currentLvlNumber);
}
