// Fill out your copyright notice in the Description page of Project Settings.

#include "FailResponse.h"


// Sets default values for this component's properties
UFailResponse::UFailResponse()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

FString UFailResponse::GetBankServer() const
{
	return bank_server;
}

void UFailResponse::SetBankServer(const FString &value)
{
	bank_server = value;
}

FString UFailResponse::GetTime() const
{
	return time;
}

void UFailResponse::SetTime(const FString &value)
{
	time = value;
}
FString UFailResponse::GetStatus() const
{
	return status;
}

void UFailResponse::SetStatus(const FString &value)
{
	status = value;
}
FString UFailResponse::GetMessage() const
{
	return message;
}

void UFailResponse::SetMessage(const FString &value)
{
	message = value;
}

FString UFailResponse::GetAccount() const
{
	return account;
}

void UFailResponse::SetAccount(const FString &value)
{
	account = value;
}

FString UFailResponse::GetReceipt() const
{
	return receipt;
}

void UFailResponse::SetReceipt(const FString &value)
{
	receipt = value;
}