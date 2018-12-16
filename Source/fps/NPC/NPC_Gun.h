// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NPC_Gun.generated.h"

/**
 * 
 */
UCLASS()
class FPS_API UNPC_Gun : public UActorComponent
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USkeletalMeshComponent* NPC_Gun;
	
	
};
