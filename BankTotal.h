// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BankTotal.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CLOUDCOINTEST_API UBankTotal : public UActorComponent
{
	GENERATED_BODY()
private:
	int privateOnes = 0;
	int privateFives = 0;
	int privateTwentyFives = 0;
	int privateHundreds = 0;
	int privateTwoHundredFifties = 0;

public:	
	// Sets default values for this component's properties
	UBankTotal();
	UFUNCTION(BlueprintCallable)
		UBankTotal* SetBankTotal(int ones, int fives, int twentyFives, int hundreds, int twoHundredFifties);

	UFUNCTION(BlueprintCallable)
		int GetOnes() const;
	UFUNCTION(BlueprintCallable)
		void SetOnes(const int &value);

	UFUNCTION(BlueprintCallable)
		int GetFives() const;
	UFUNCTION(BlueprintCallable)
		void SetFives(const int &value);

	UFUNCTION(BlueprintCallable)
		int GetTwentyFives() const;
	UFUNCTION(BlueprintCallable)
		void SetTwentyFives(const int &value);

	UFUNCTION(BlueprintCallable)
		int GetHundreds() const;
	UFUNCTION(BlueprintCallable)
		void SetHundreds(const int &value);

	UFUNCTION(BlueprintCallable)
		int GetTwoHundredFifties() const;
	UFUNCTION(BlueprintCallable)
		void SetTwoHundredFifties(const int &value);
};
