// Fill out your copyright notice in the Description page of Project Settings.


#include "Wall.h"
#include "StructuralAssets/UnneededActors.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
AWall::AWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
}

// Called when the game starts or when spawned
void AWall::BeginPlay()
{
	Super::BeginPlay();
	UUnneededActors* SaveRef = Cast<UUnneededActors>
		(UGameplayStatics::LoadGameFromSlot("UnneededSlot", 0));

	
}

// Called every frame
void AWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AWall::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	UUnneededActors* SaveRef = Cast<UUnneededActors>
		(UGameplayStatics::LoadGameFromSlot("UnneededSlot", 0));
	if (!SaveRef)
	{
		SaveRef = Cast<UUnneededActors>
			(UGameplayStatics::CreateSaveGameObject(UUnneededActors::StaticClass()));
	}
	SaveRef->UnneededActorsArray.Add(GetActorGuid());
	UGameplayStatics::SaveGameToSlot(SaveRef, "UnneededSlot", 0);

	Destroy();
	return 0.0f;
}

