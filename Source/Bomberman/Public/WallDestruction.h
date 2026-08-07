// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WallDestruction.generated.h"


class UPartcileSystem;
class UGeometryCollection;
UCLASS()
class BOMBERMAN_API AWallDestruction : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWallDestruction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere)
	TObjectPtr<UParticleSystem> Particle;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UGeometryCollection> GC;
};
