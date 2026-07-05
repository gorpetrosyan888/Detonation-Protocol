// Fill out your copyright notice in the Description page of Project Settings.


#include "StructuralAssets/SaveLevel.h"
#include "Kismet/GameplayStatics.h"

FName USaveLevel::SaveLvlName(FName newName)
{
	newLvlName = newName;
	UGameplayStatics::SaveGameToSlot(this, "LevelNameSlot", 0);
	return newLvlName;
}

FName USaveLevel::LoadLvlName()
{
	if (UGameplayStatics::DoesSaveGameExist("LevelNameSlot", 0))
	{
		USaveLevel* SaveRef = Cast<USaveLevel>
			(UGameplayStatics::LoadGameFromSlot("LevelNameSlot", 0));
		newLvlName = SaveRef->newLvlName;
	}
	return newLvlName;
}

int32 USaveLevel::SaveLvlNumber(int32 newNumber)
{
	newLvlNumber = newNumber;
	UGameplayStatics::SaveGameToSlot(this, "LevelNumberSlot", 0);

	return newLvlNumber;
}

int32 USaveLevel::LoadLvlNumber()
{
	if (UGameplayStatics::DoesSaveGameExist("LevelNumberSlot", 0))
	{
		USaveLevel* SaveRef = Cast<USaveLevel>
			(UGameplayStatics::LoadGameFromSlot("LevelNumberSlot", 0));
		newLvlNumber = SaveRef->newLvlNumber;

	}
	return newLvlNumber;
}
