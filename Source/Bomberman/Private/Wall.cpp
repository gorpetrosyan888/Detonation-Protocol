// Fill out your copyright notice in the Description page of Project Settings.


#include "Wall.h"
#include "StructuralAssets/UnneededActors.h"
#include "Kismet/GameplayStatics.h"
#include "BombermanGameMode.h"
#include "UnneededComponent.h"
// Sets default values
AWall::AWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	CompRef = CreateDefaultSubobject<UUnneededComponent>("CompSave");
	
}

// Called when the game starts or when spawned
void AWall::BeginPlay()
{
	Super::BeginPlay();
	

	
}

// Called every frame
void AWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AWall::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	ABombermanGameMode* GmRef = GetWorld()->GetAuthGameMode<ABombermanGameMode>();
	GmRef->OnServerDestroyed.Broadcast();
	
	AActor* DestructionActor = GetWorld()->SpawnActor<AActor>(DestructionObject, GetActorTransform());
	UUnneededActors* SaveRef = Cast<UUnneededActors>
		(UGameplayStatics::LoadGameFromSlot("UnneededSlotAdded", 0));
	if (!SaveRef)
	{
		SaveRef = Cast<UUnneededActors>
			(UGameplayStatics::CreateSaveGameObject(UUnneededActors::StaticClass()));
	}
	SaveRef->UnneededActorsArray.Add(GetFName());
	UGameplayStatics::SaveGameToSlot(SaveRef, "UnneededSlotAdded", 0);

	Destroy();
	return 0.0f;
	

}

