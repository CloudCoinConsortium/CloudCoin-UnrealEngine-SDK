// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BankKeys.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CLOUDCOINTEST_API UBankKeys : public UActorComponent
{
	GENERATED_BODY()
private:
	UPROPERTY()
		FString publicKey;

	UPROPERTY()
		FString privateKey;

	UPROPERTY()
		FString account;

public:
	UBankKeys();
	UFUNCTION(BlueprintCallable)
		void SetBankKeys(const FString public_key, const FString private_key, const FString _account);

	UFUNCTION(BlueprintCallable)
		FString GetPublicKey() const;
	UFUNCTION(BlueprintCallable)
		void SetPublicKey(const FString &value);

	UFUNCTION(BlueprintCallable)
		FString GetPrivateKey() const;
	UFUNCTION(BlueprintCallable)
		void SetPrivateKey(const FString &value);

	UFUNCTION(BlueprintCallable)
		FString GetAccount() const;
	UFUNCTION(BlueprintCallable)
		void SetAccount(const FString &value);
};
