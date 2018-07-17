/**
 * @file CloudBankUtils.h
 *
 * @brief
 *    Declaration of a class implementing functions needed to communicate with
 *    a server that has CloudCoinConsortium's Cloudservice web API.
 */

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BankKeys.h"
#include "Receipt.h"
#include "Interpretation.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "Runtime/Online/HTTP/Public/HttpManager.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "CloudBankUtils.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CLOUDCOINTEST_API UCloudBankUtils : public UActorComponent
{
	GENERATED_BODY()

private:
	UBankKeys* keys;
	FString rawStackForDeposit;
	FString rawStackFromWithdrawal;
	FString rawReceipt;
	FString receiptNumber;
	FString toPublicKey;
	int32 totalCoinsWithdrawn;
	FHttpModule* Http;

	int32 GetDenomination(int sn);

	void SetHeaders(TSharedRef<IHttpRequest>& Request);
public:	
	UCloudBankUtils();
	UFUNCTION(BlueprintCallable)
		void SetCloudBankUtils(UBankKeys *startKeys);
	
	UPROPERTY(BlueprintReadOnly)
		int onesInBank;

	UPROPERTY(BlueprintReadOnly)
		int fivesInBank;

	UPROPERTY(BlueprintReadOnly)
		int twentyFivesInBank;

	UPROPERTY(BlueprintReadOnly)
		int hundredsInBank;

	UPROPERTY(BlueprintReadOnly)
		int twoHundredFiftiesInBank;

	UFUNCTION(BlueprintCallable)
		void ShowCoins();
	void ShowCoinsResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	UFUNCTION(BlueprintCallable)
		void LoadStackFromFile(FString filepath);

	UFUNCTION(BlueprintCallable)
		void DepositStack();
	UFUNCTION(BlueprintCallable)
		void DepositStackTo(FString toPublicURL);
	void DepositResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	UFUNCTION(BlueprintCallable)
		void GetReceipt();
	void ReceiptResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	UFUNCTION(BlueprintCallable)
		void WithdrawStack(int32 amountToWithdraw);
	void WithdrawResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	UFUNCTION(BlueprintCallable)
		void GetReceiptFromCloudBank();
	void ReceiptFromCloudBankResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	
	UFUNCTION(BlueprintCallable)
		UInterpretation* InterpretReceipt();
	
	UFUNCTION(BlueprintCallable)
		void SaveStackToFile(FString path);
	UFUNCTION(BlueprintCallable)
		FString GetStackName();
	
	UFUNCTION(BlueprintCallable)
		void TransferCloudCoins(FString toPublicKey, int32 coinsToSend);
	void TransferCloudCoinsResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
};
