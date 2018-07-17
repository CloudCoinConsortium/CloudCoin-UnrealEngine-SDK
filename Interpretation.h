/**
 * @file Interpretation.h
 *
 * @brief
 *    Declaration of a class used to parse information from a receipt.
 */

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
	UPROPERTY(BlueprintReadOnly)
		FFullReceipt receipt;
	UPROPERTY(BlueprintReadOnly)
		FString interpretation;
	UPROPERTY(BlueprintReadOnly)
		int32 totalAuthenticNotes;
	UPROPERTY(BlueprintReadOnly)
		int32 totalAuthenticCoins;
};
