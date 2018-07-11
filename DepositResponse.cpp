// Fill out your copyright notice in the Description page of Project Settings.

#include "DepositResponse.h"


// Sets default values for this component's properties
UDepositResponse::UDepositResponse()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

FString UDepositResponse::GetBankServer() const
{
	return bank_server;
}

void UDepositResponse::SetBankServer(const FString &value)
{
	bank_server = value;
}

FString UDepositResponse::GetTime() const
{
	return time;
}

void UDepositResponse::SetTime(const FString &value)
{
	time = value;
}
FString UDepositResponse::GetStatus() const
{
	return status;
}

void UDepositResponse::SetStatus(const FString &value)
{
	status = value;
}
FString UDepositResponse::GetMessage() const
{
	return message;
}

void UDepositResponse::SetMessage(const FString &value)
{
	message = value;
}

FString UDepositResponse::GetAccount() const
{
	return account;
}

void UDepositResponse::SetAccount(const FString &value)
{
	account = value;
}

FString UDepositResponse::GetReceipt() const
{
	return receipt;
}

void UDepositResponse::SetReceipt(const FString &value)
{
	receipt = value;
}