// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveMachine.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"
#include "StructuralAssets/SavePlayerLocation.h"
#include "StructuralAssets/UnneededActors.h"
#include "Components/BoxComponent.h"

// Sets default values
ASaveMachine::ASaveMachine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("mesh");
	RootComponent = Mesh;

	Box = CreateDefaultSubobject<UBoxComponent>("Box");
}

// Called when the game starts or when spawned
void ASaveMachine::BeginPlay()
{
	Super::BeginPlay();
	
	APlayerController* PC = GetWorld()->GetFirstPlayerController();

	if (PC)
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = 
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>
			(PC->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(MappingContext, 0);
		}
	}

	Box->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OverlapSaveMachine);
	Box->OnComponentEndOverlap.AddDynamic(this, &ThisClass::EndOverlapSaveMachine);+

}

// Called every frame
void ASaveMachine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASaveMachine::OverlapSaveMachine(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	EnableInput(GetWorld()->GetFirstPlayerController());

	if (UEnhancedInputComponent* EhComp = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EhComp->BindAction(InteractAction, ETriggerEvent::Started, this, &ThisClass::InteractSaveMachine);
	}

}

void ASaveMachine::EndOverlapSaveMachine(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	DisableInput(GetWorld()->GetFirstPlayerController());

	if (UEnhancedInputComponent* EhComp = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EhComp->ClearActionBindings();
	}
}

void ASaveMachine::InteractSaveMachine()
{
	USavePlayerLocation* SaveRefLoc = Cast<USavePlayerLocation>
		(UGameplayStatics::CreateSaveGameObject
		(USavePlayerLocation::StaticClass()));

	UUnneededActors* SaveRef = Cast<UUnneededActors>
		(UGameplayStatics::CreateSaveGameObject
		(USavePlayerLocation::StaticClass()));

	SaveRefLoc->SaveLocation(GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation());


	UGameplayStatics::SaveGameToSlot(SaveRefLoc, "UnneededSlot", 0);
	UGameplayStatics::SaveGameToSlot(SaveRef, "TimerSlot", 0);


}

