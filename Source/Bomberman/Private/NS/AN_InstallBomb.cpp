// Fill out your copyright notice in the Description page of Project Settings.


#include "NS/AN_InstallBomb.h"


void UAN_InstallBomb::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	if (!MeshComp || !MeshComp->GetWorld()->IsGameWorld())
	{
		return;
	}
	
	MeshComp->GetWorld()->SpawnActor<AActor>(ActorToSpawn, MeshComp->GetSocketTransform(SocketName));
}
