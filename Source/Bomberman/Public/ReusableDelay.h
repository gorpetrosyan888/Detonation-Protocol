// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/KismetSystemLibrary.h"
/**
 * 
 */
class BOMBERMAN_API ReusableDelay
{
public:
	

	UFUNCTION()
	static void StartDelay(UObject* WorldContextObject, float Duration, UObject* CallbackTarget,
		FName FunctionName)
	{
		FLatentActionInfo LatentActionInfo;
		LatentActionInfo.CallbackTarget = CallbackTarget;
		LatentActionInfo.ExecutionFunction = FunctionName;
		LatentActionInfo.Linkage = 0;
		UKismetSystemLibrary::Delay(WorldContextObject, Duration, LatentActionInfo);
	};
};
