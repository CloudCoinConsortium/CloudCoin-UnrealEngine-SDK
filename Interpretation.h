// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Receipt.h"
#include "Components/ActorComponent.h"
#include "Interpretation.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CLOUDCOINTEST_API UInterpretation : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInterpretation();
	
	FFullReceipt receipt;
	FString interpretation;
	int32 totalAuthenticNotes;
	int32 totalAuthenticCoins;
};
