// Fill out your copyright notice in the Description page of Project Settings.


#include "WallDestruction.h"
#include "GeometryCollection/GeometryCollectionComponent.h"
// Sets default values
AWallDestruction::AWallDestruction()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GC = CreateDefaultSubobject<UGeometryCollection>("Geometry");
}

// Called when the game starts or when spawned
void AWallDestruction::BeginPlay()
{
	Super::BeginPlay();
	
	

}

// Called every frame
void AWallDestruction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

