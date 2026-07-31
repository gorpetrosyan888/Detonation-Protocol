// Fill out your copyright notice in the Description page of Project Settings.


#include "UpdateTimer.h"
#include "BombermanGameMode.h"

// Sets default values
AUpdateTimer::AUpdateTimer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUpdateTimer::BeginPlay()
{
	Super::BeginPlay();
	
	ABombermanGameMode* GmRef = GetWorld()->GetAuthGameMode<ABombermanGameMode>();

	GmRef->timerSeconds = seconds;
}

// Called every frame
void AUpdateTimer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

