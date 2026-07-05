// Fill out your copyright notice in the Description page of Project Settings.


#include "UpdateLvlNumber.h"
#include "StructuralAssets/MainGameInstance.h"
#include "StructuralAssets/SaveLevel.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
AUpdateLvlNumber::AUpdateLvlNumber()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUpdateLvlNumber::BeginPlay()
{
	Super::BeginPlay();
	GetGameInstance()->GetSubsystem<UMainGameInstance>()->ShowLvlNumber(LvlNumber);
	USaveLevel* SaveRef = Cast<USaveLevel>
		(UGameplayStatics::CreateSaveGameObject(USaveLevel::StaticClass()));
	SaveRef->SaveLvlNumber(LvlNumber);
}

// Called every frame
void AUpdateLvlNumber::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

