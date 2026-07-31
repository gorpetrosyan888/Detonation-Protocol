// Fill out your copyright notice in the Description page of Project Settings.


#include "NextLVL.h"
#include "Components/BoxComponent.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"


#include "ReusableDelay.h"

#include "StructuralAssets/UnneededActors.h"
#include "BombermanGameMode.h"

// Sets default values
ANextLVL::ANextLVL()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Box = CreateDefaultSubobject<UBoxComponent>("Box");
	

}

// Called when the game starts or when spawned
void ANextLVL::BeginPlay()
{
	Super::BeginPlay();
	Box->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OverlapNextLvl);

	ABombermanGameMode* GmRef = GetWorld()->GetAuthGameMode<ABombermanGameMode>();
	GmRef->currentTaskNum = CurrentServersNum;
	
	
}

// Called every frame
void ANextLVL::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANextLVL::OverlapNextLvl(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{


	ABombermanGameMode* GmRef = GetWorld()->GetAuthGameMode<ABombermanGameMode>();


	UUnneededActors* SaveRef = Cast<UUnneededActors>
		(UGameplayStatics::LoadGameFromSlot("UnneededSlotAdded", 0));
	if (SaveRef)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString::FromInt(
			SaveRef->UnneededActorsArray.Num()));
	}
	


	if (OtherActor->ActorHasTag("Player"))
	{
		TArray<AActor*> Enemys;
		for (AActor* Actor : TActorRange<AActor>(GetWorld()))
		{
			if (Actor->ActorHasTag("Enemy"))
			{
				Enemys.Add(Actor);
			}
		}
		if (/*Enemys.IsEmpty() && */SaveRef->UnneededActorsArray.Num() >= GmRef->currentTaskNum)
		{
			OpenDoors();
			GetWorld()->GetFirstPlayerController()->PlayerCameraManager
				->StartCameraFade(0, 1, 4.5
					, FLinearColor::Black);
			ReusableDelay::StartDelay(GetWorld(), 4.4, this, "TeleportToAnotherLVL");
			

		}
	}

	
}

void ANextLVL::TeleportToAnotherLVL()
{
	UGameplayStatics::OpenLevel(GetWorld(), LvlName);

}


