// Fill out your copyright notice in the Description page of Project Settings.


#include "StructuralAssets/SavePlayerLocation.h"
#include "Kismet/GameplayStatics.h"

FVector USavePlayerLocation::SaveLocation(FVector location)
{
	
	NewLocation = location;
	UGameplayStatics::SaveGameToSlot(this, "LocationSlot", 0);
	return NewLocation;
}

FVector USavePlayerLocation::LoadLocation()
{
	if (UGameplayStatics::DoesSaveGameExist("LocationSlot", 0))
	{
		USavePlayerLocation* SaveRef = Cast<USavePlayerLocation>
			(UGameplayStatics::LoadGameFromSlot("LocationSlot", 0));
		NewLocation = SaveRef->NewLocation;
	}
	return NewLocation;
}

int32 USavePlayerLocation::SaveSeconds(int32 value)
{
	newSeconds = value;
	UGameplayStatics::SaveGameToSlot(this, "TimerSlot", 0);

	
	return newSeconds;
}

int32 USavePlayerLocation::LoadSeconds()
{
	if (UGameplayStatics::DoesSaveGameExist("TimerSlot", 0))
	{
		USavePlayerLocation* SaveRef = Cast<USavePlayerLocation>
			(UGameplayStatics::LoadGameFromSlot("TimerSlot", 0));
		newSeconds = SaveRef->newSeconds;
	}

	return newSeconds;
}
