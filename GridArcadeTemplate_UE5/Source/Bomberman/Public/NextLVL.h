// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NextLVL.generated.h"


class UBoxComponent;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMission, int32, UpdatedMission);

UCLASS()
class BOMBERMAN_API ANextLVL : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ANextLVL();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UBoxComponent> Box;

	UFUNCTION()
	void OverlapNextLvl
	(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere)
	FName LvlName;



	UFUNCTION()
	virtual void TeleportToAnotherLVL();




	
};
