// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnTutorial.h"
#include "Kismet/GameplayStatics.h"
#include "StructuralAssets/UnneededActors.h"
#include "Blueprint/UserWidget.h"
#include "UnneededComponent.h"
// Sets default values
ASpawnTutorial::ASpawnTutorial()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnTutorial::BeginPlay()
{
	Super::BeginPlay();

	CreateWidget<UUserWidget>(GetWorld(), WidgetClass)->AddToViewport();

	
	UUnneededActors* SaveRef = Cast<UUnneededActors>
		(UGameplayStatics::LoadGameFromSlot("UnneededSlotAdded", 0));
	if (!SaveRef)
	{
		SaveRef = Cast<UUnneededActors>
			(UGameplayStatics::CreateSaveGameObject(UUnneededActors::StaticClass()));
	}
	SaveRef->UnneededActorsArray.Add(CompRef->ActorID);
	UGameplayStatics::SaveGameToSlot(SaveRef, "UnneededSlotAdded", 0);
	
}

// Called every frame
void ASpawnTutorial::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

