// Fill out your copyright notice in the Description page of Project Settings.


#include "Bomb.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"

// Sets default values
ABomb::ABomb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("mesh");
}

// Called when the game starts or when spawned
void ABomb::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABomb::EndPlay(const EEndPlayReason::Type EndPlayReason)
{

	TArray<AActor*> Actors;
	Actors.Add(this);
	TArray<FHitResult> HitResult;

	bool bifHited = UKismetSystemLibrary::SphereTraceMulti
	(GetWorld(), Mesh->GetComponentLocation(), Mesh->GetComponentLocation(),
		500, UEngineTypes::ConvertToTraceType(ECC_Visibility), false,
		Actors, EDrawDebugTrace::None, HitResult, 
		true, FLinearColor::Red, FLinearColor::Green
		);

	if (bifHited)
	{
		for (FHitResult Result : HitResult)
		{
			UGameplayStatics::ApplyDamage(Result.GetActor(), 5, nullptr, nullptr, nullptr);
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Particle, Mesh->GetComponentLocation(),
				FRotator::ZeroRotator, FVector(3, 3, 3), true);
		}
	}
}

