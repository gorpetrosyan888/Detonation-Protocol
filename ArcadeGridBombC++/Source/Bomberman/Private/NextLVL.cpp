// Fill out your copyright notice in the Description page of Project Settings.


#include "NextLVL.h"
#include "Components/BoxComponent.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "UI/ExposeText.h"
#include "Blueprint/UserWidget.h"
#include "ReusableDelay.h"
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
}

// Called every frame
void ANextLVL::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANextLVL::OverlapNextLvl(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	TArray<AActor*> Enemys;
	for (AActor* Actor : TActorRange<AActor>(GetWorld()))
	{
		if (Actor->ActorHasTag("Enemy"))
		{
			Enemys.Add(Actor);
		}
	}
	if (Enemys.IsEmpty())
	{
		UUserWidget* WidgetRef = CreateWidget<UUserWidget>(GetWorld(), ExposeWidget);
		UExposeText* ExposeRef = Cast<UExposeText>(WidgetRef);
		if (ExposeRef)
		{
			ExposeRef->text = FText::FromString("Victory");
			ExposeRef->AddToViewport();
		}
		ReusableDelay::StartDelay(GetWorld(), 2, this, "TeleportToAnotherLVL");

	}
}

void ANextLVL::TeleportToAnotherLVL()
{
		UGameplayStatics::OpenLevel(GetWorld(), LvlName);

}

