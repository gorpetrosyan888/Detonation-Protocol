// Fill out your copyright notice in the Description page of Project Settings.


#include "NS/NS_Movement.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BombermanCharacter.h"

void UNS_Movement::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	if (GetWorld())
	{
		if (ABombermanCharacter* CharRef = Cast<ABombermanCharacter>
			(GetWorld()->GetFirstPlayerController()->GetPawn()))
		{
			CharRef->GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_None);
		}
	}

}

void UNS_Movement::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	if (GetWorld())
	{
		if (ABombermanCharacter* CharRef = Cast<ABombermanCharacter>
			(GetWorld()->GetFirstPlayerController()->GetPawn()))
		{
			CharRef->GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking);
		}
	}
}
