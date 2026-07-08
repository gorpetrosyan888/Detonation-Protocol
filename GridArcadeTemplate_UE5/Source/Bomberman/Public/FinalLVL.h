// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NextLVL.h"
#include "FinalLVL.generated.h"


class UBoxComponent;
class UUserWidget;
UCLASS()
class BOMBERMAN_API AFinalLVL : public ANextLVL
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFinalLVL();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

	

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> WidgetClass;

	virtual void TeleportToAnotherLVL() override;
};
