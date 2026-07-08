// Fill out your copyright notice in the Description page of Project Settings.


#include "FinalLVL.h"

#include "Blueprint/UserWidget.h"

// Sets default values
AFinalLVL::AFinalLVL()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFinalLVL::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFinalLVL::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void AFinalLVL::TeleportToAnotherLVL()
{
	CreateWidget<UUserWidget>(GetWorld(), WidgetClass)->AddToViewport();

}

