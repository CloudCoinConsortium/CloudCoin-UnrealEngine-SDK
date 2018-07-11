// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Receipt.generated.h"

// Holds the elements of the receipt_details array
USTRUCT(BlueprintType)
struct FReceiptDetail
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
		FString nn;
	void Setnn(const FString value)
	{
		nn = value;
	}
	FString Getnn()
	{
		return nn;
	}

	UPROPERTY(BlueprintReadWrite)
		FString sn;
	void Setsn(const FString value)
	{
		sn = value;
	}
	FString Getsn()
	{
		return sn;
	}

	UPROPERTY(BlueprintReadWrite)
		FString status;
	void Setstatus(const FString value)
	{
		status = value;
	}
	FString Getstatus()
	{
		return status;
	}

	UPROPERTY(BlueprintReadWrite)
		FString pown;
	void Setpown(const FString value)
	{
		pown = value;
	}
	FString Getpown()
	{
		return pown;
	}

	UPROPERTY(BlueprintReadWrite)
		FString note;
	void Setnote(const FString value)
	{
		note = value;
	}
	FString Getnote()
	{
		return note;
	}
};

// Holds the attributes of the GetReceipt response
USTRUCT(BlueprintType)
struct FFullReceipt
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
		FString receipt_id;
	void Setreceipt_id(const FString value)
	{
		receipt_id = value;
	}
	FString Getreceipt_id()
	{
		return receipt_id;
	}

	UPROPERTY(BlueprintReadWrite)
		FString time;
	void Settime(const FString value)
	{
		time = value;
	}
	FString Gettime()
	{
		return time;
	}

	UPROPERTY(BlueprintReadWrite)
		FString timezone;
	void Settimezone(const FString value)
	{
		timezone = value;
	}
	FString Gettimezone()
	{
		return timezone;
	}

	UPROPERTY(BlueprintReadWrite)
		FString bank_server;
	void Setbank_server(const FString value)
	{
		bank_server = value;
	}
	FString Getbank_server()
	{
		return bank_server;
	}

	UPROPERTY(BlueprintReadWrite)
		FString total_authentic;
	void Settotal_authentic(const FString value)
	{
		total_authentic = value;
	}
	FString Gettotal_authentic()
	{
		return total_authentic;
	}

	UPROPERTY(BlueprintReadWrite)
		FString total_fracked;
	void Settotal_fracked(const FString value)
	{
		total_fracked = value;
	}
	FString Gettotal_fracked()
	{
		return total_fracked;
	}

	UPROPERTY(BlueprintReadWrite)
		FString total_counterfeit;
	void Settotal_counterfeit(const FString value)
	{
		total_counterfeit = value;
	}
	FString Gettotal_counterfeit()
	{
		return total_counterfeit;
	}

	UPROPERTY(BlueprintReadWrite)
		FString total_lost;
	void Settotal_lost(const FString value)
	{
		total_lost = value;
	}
	FString Gettotal_lost()
	{
		return total_lost;
	}

	UPROPERTY(BlueprintReadWrite)
		TArray<FReceiptDetail> receipt;
	void Setreceipt(const TArray<FReceiptDetail> value)
	{
		receipt = value;
	}
	TArray<FReceiptDetail> Getreceipt()
	{
		return receipt;
	}

};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CLOUDCOINTEST_API UReceipt : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UReceipt();
};