// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FailResponse.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CLOUDCOINTEST_API UFailResponse : public UActorComponent
{
	GENERATED_BODY()
private:
	FString bank_server;
	FString time;
	FString status;
	FString message;
	FString account;
	FString receipt;

public:	
	// Sets default values for this component's properties
	UFailResponse();

	UFUNCTION(BlueprintCallable)
		FString GetBankServer() const;
	UFUNCTION(BlueprintCallable)
		void SetBankServer(const FString &value);

	UFUNCTION(BlueprintCallable)
		FString GetTime() const;
	UFUNCTION(BlueprintCallable)
		void SetTime(const FString &value);

	UFUNCTION(BlueprintCallable)
		FString GetStatus() const;
	UFUNCTION(BlueprintCallable)
		void SetStatus(const FString &value);

	UFUNCTION(BlueprintCallable)
		FString GetMessage() const;
	UFUNCTION(BlueprintCallable)
		void SetMessage(const FString &value);

	UFUNCTION(BlueprintCallable)
		FString GetAccount() const;
	UFUNCTION(BlueprintCallable)
		void SetAccount(const FString &value);

	UFUNCTION(BlueprintCallable)
		FString GetReceipt() const;
	UFUNCTION(BlueprintCallable)
		void SetReceipt(const FString &value);
};
