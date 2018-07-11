// Fill out your copyright notice in the Description page of Project Settings.

#include "CloudBankUtils.h"


// Sets default values for this component's properties
UCloudBankUtils::UCloudBankUtils()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

/**
 * @brief    CloudBankUtils Constructor
 */
void UCloudBankUtils::SetCloudBankUtils(UBankKeys *startKeys)
{
	this->keys = startKeys;
	this->totalCoinsWithdrawn = 0;
	this->onesInBank = 0;
	this->fivesInBank = 0;
	this->twentyFivesInBank = 0;
	this->hundredsInBank = 0;
	this->twoHundredFiftiesInBank = 0;
}

/**
 * @brief    Calls the show_coins Service
 */
 void UCloudBankUtils::ShowCoins()
{
	FString publicKey = keys->GetPublicKey();
	FString privateKey = keys->GetPrivateKey();
	FString service = "/service/show_coins";
	FString account = keys->GetAccount();

	Http = &FHttpModule::Get();
	TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UCloudBankUtils::ShowCoinsResponse);
	Request->SetURL(TEXT("https://" + publicKey + service + "?pk=" + privateKey + "&account=" + account));
	Request->SetVerb(TEXT("GET"));
	SetHeaders(Request);
	Request->ProcessRequest();
}

 /**
  * @brief   Stores the results of the show_coins Service in this class' public properties
  */
void UCloudBankUtils::ShowCoinsResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (!bWasSuccessful)
	{
		UE_LOG(LogTemp, Error, TEXT("Error! Check your connection, or your public key"));
		return;
	}
	// A pointer holding the json serialized data
	TSharedPtr<FJsonObject> JsonObject;

	// Read the json data
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

	// Deserialize the json data
	if (FJsonSerializer::Deserialize(Reader, JsonObject))
	{
		FString status = JsonObject->GetStringField("status");
		if (status == "coins_shown")
		{
			onesInBank = JsonObject->GetIntegerField("ones");
			fivesInBank = JsonObject->GetIntegerField("fives");
			twentyFivesInBank = JsonObject->GetIntegerField("twentyfives");
			hundredsInBank = JsonObject->GetIntegerField("hundreds");
			twoHundredFiftiesInBank = JsonObject->GetIntegerField("twohundredfifties");
			UE_LOG(LogTemp, Display, TEXT("%s"), *Response->GetContentAsString());
//			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, Response->GetContentAsString());
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, JsonObject->GetStringField("message"));
		}
	}
	else
		UE_LOG(LogTemp, Error, TEXT("Deserialization error!"));
}

/**
 * @brief    Sets rawStackForDeposit to a CloudCoin stack read from a file
 * @param    filepath The full filepath and filename of the CloudCoin stack that is being loaded
 */
void UCloudBankUtils::LoadStackFromFile(FString filepath)
{
	FFileHelper::LoadFileToString(rawStackForDeposit, *filepath);
}

/**
 * @brief    Sends the CloudCoin in rawStackForDeposit to the CloudService server that this object holds the keys for
 *
 * loadStackFromFile needs to be called first
 */
void UCloudBankUtils::DepositStack()
{
	FString publicKey = keys->GetPublicKey();
	FString service = "/service/deposit_one_stack";
	FString account = keys->GetAccount();

	Http = &FHttpModule::Get();
	TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UCloudBankUtils::DepositResponse);
	Request->SetURL(TEXT("https://" + publicKey + service + "?account=" + account + "&"));
	Request->SetVerb(TEXT("POST"));
	Request->SetContentAsString("stack=" + rawStackForDeposit);
	SetHeaders(Request);
	Request->ProcessRequest();
}

/**
* @brief    Sends the CloudCoin in rawStackForDeposit to a CloudService server specified by toPublicURL
* @oaran    toPublicURL The url of the CloudService server the CLoudCoins are being sent to. Do not include "https://"
*
* loadStackFromFile needs to be called first
*/
void UCloudBankUtils::DepositStackTo(FString toPublicURL)
{
	FString service = "/service/deposit_one_stack";
	FString account = keys->GetAccount();

	Http = &FHttpModule::Get();
	TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UCloudBankUtils::DepositResponse);
	Request->SetURL(TEXT("https://" + toPublicURL + service + "?account=" + account + "&"));
	Request->SetVerb(TEXT("POST"));
	Request->SetContentAsString("stack=" + rawStackForDeposit);
	SetHeaders(Request);
	Request->ProcessRequest();
}

/**
 * @brief    Stores the receipt from the deposit_one_stack Service requested in DepositStack or DepositStackTo
 */
void UCloudBankUtils::DepositResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (!bWasSuccessful)
	{
		UE_LOG(LogTemp, Error, TEXT("Error! Check your connection, or your public key"));
		return;
	}

	// A pointer holding the json serialized data
	TSharedPtr<FJsonObject> JsonObject;

	// Read the json data
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

	// Deserialize the json data
	if (FJsonSerializer::Deserialize(Reader, JsonObject))
	{
		FString receivedMessage = JsonObject->GetStringField("message");
		receiptNumber = JsonObject->GetStringField("receipt");
		UE_LOG(LogTemp, Display, TEXT("%s"), *receivedMessage);
//		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, recievedMessage);
	}
	else
		UE_LOG(LogTemp, Error, TEXT("Deserialization error!"));
}

/**
 * @brief    Retrieve the receipt generated by the CloudService for the last DepositStack call
 * 
 * Requires DepositStack to have been previously called. The retrieved receipt will be saved in rawReceipt
 */
void UCloudBankUtils::GetReceipt()
{
	FString publicKey = keys->GetPublicKey();
	FString service = "/service/get_receipt";
	FString account = keys->GetAccount();

	Http = &FHttpModule::Get();
	TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UCloudBankUtils::ReceiptResponse);
	Request->SetURL(TEXT("https://" + publicKey + service + "?rn=" + receiptNumber + "&account=" + account));
	Request->SetVerb(TEXT("GET"));
	SetHeaders(Request);
	Request->ProcessRequest();
}

/**
 * @brief    Saves the retrieved receipt into rawReceipt
 */
void UCloudBankUtils::ReceiptResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (!bWasSuccessful)
	{
		UE_LOG(LogTemp, Error, TEXT("Error! Check your connection, or your public key"));
		return;
	}

	UE_LOG(LogTemp, Display, TEXT("%s"), *Response->GetContentAsString());
//	GEngine->AddOnScreenDebugMessage(-1, 500.0f, FColor::Green, Response->GetContentAsString());

	rawReceipt = Response->GetContentAsString();
}

/**
 * @brief    Retrieves CloudCoins from CloudService server that this object holds the keys for.
 * @param    amountToWithraw The amount of CloudCoins to withdraw
 *
 * The resulting stack that is retrieved is saved in rawStackFromWithdrawal
 */
void UCloudBankUtils::WithdrawStack(int32 amountToWithdraw)
{
	totalCoinsWithdrawn = amountToWithdraw;
	FString publicKey = keys->GetPublicKey();
	FString privateKey = keys->GetPrivateKey();
	FString service = "/service/withdraw_one_stack";
	FString account = keys->GetAccount();

	Http = &FHttpModule::Get();
	TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UCloudBankUtils::WithdrawResponse);
	Request->SetURL(TEXT("https://" + publicKey + service + "?amount=" + FString::FromInt(amountToWithdraw) + "&pk=" + privateKey + "&account=" + account));
	Request->SetVerb(TEXT("GET"));
	SetHeaders(Request);
	Request->ProcessRequest();
}

/**
 * @brief    Saves the retrieved CloudCoin stack into rawStackFromWithdrawal
 */
void UCloudBankUtils::WithdrawResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (!bWasSuccessful)
	{
		UE_LOG(LogTemp, Error, TEXT("Error! Check your connection, or your public key"));
		return;
	}

	rawStackFromWithdrawal = Response->GetContentAsString();
}

/**
 * @brief    Calculate a CloudCoin note's denomination using its serial number
 * @param    sn The serial number
 */
int32 UCloudBankUtils::GetDenomination(int sn)
{
	int nom = 0;
	if (sn < 1)
		nom = 0;
	else if (sn < 2097153)
		nom = 1;
	else if (sn < 4194305)
		nom = 5;
	else if (sn < 6291457)
		nom = 25;
	else if (sn < 14680065)
		nom = 100;
	else if (sn < 16777217)
		nom = 250;
	else
		nom = '0';
	return nom;
}

/**
 * @brief    Retrieve the receipt generated by the CloudService for the last DepositStack call
 *
 * The amount withdrawn is the same as the amount last deposited with DepositStack.
 */
void UCloudBankUtils::GetReceiptFromCloudBank()
{
	FString publicKey = keys->GetPublicKey();
	FString service = "/service/get_receipt";
	FString account = keys->GetAccount();

	Http = &FHttpModule::Get();
	TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UCloudBankUtils::ReceiptFromCloudBankResponse);
	Request->SetURL(TEXT("https://" + publicKey + service + "?rn=" + receiptNumber + "&account=" + account));
	Request->SetVerb(TEXT("GET"));
	SetHeaders(Request);
	Request->ProcessRequest();
}

/**
 * @brief    Sets the amount withdrawn equal to totalCoinsWithdraw
 */
void UCloudBankUtils::ReceiptFromCloudBankResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (!bWasSuccessful)
	{
		UE_LOG(LogTemp, Error, TEXT("Error! Check your connection, or your public key"));
		return;
	}

	UE_LOG(LogTemp, Display, TEXT("%s"), *Response->GetContentAsString());
//	GEngine->AddOnScreenDebugMessage(-1, 500.0f, FColor::Green, Response->GetContentAsString());

	rawReceipt = Response->GetContentAsString();

	// FReceipt is the USTRUCT containing the response attributes
	FFullReceipt ReceiptData;

	// Converts the response into a USTRUCT
	if (FJsonObjectConverter::JsonObjectStringToUStruct(Response->GetContentAsString(), &ReceiptData, 0, 0))
	{
		for (int i = 0; i < ReceiptData.receipt.Num(); i++)
		{
			if (ReceiptData.receipt[i].Getstatus() == "authentic")
				totalCoinsWithdrawn += GetDenomination(FCString::Atoi(*ReceiptData.receipt[i].Getsn()));
		}

		WithdrawStack(totalCoinsWithdrawn);
	}
	else
		UE_LOG(LogTemp, Error, TEXT("Error!"));
		
}

/**
 * @brief    Parses pertinent information from the receipt last gather by GetReceipt
 *			 and returns it in the form of a UInterpretation object.
 */
UInterpretation* UCloudBankUtils::InterpretReceipt()
{
	UInterpretation* inter = NewObject<UInterpretation>();
	FString interpretation = "";
	FFullReceipt ReceiptData;
	FJsonObjectConverter::JsonObjectStringToUStruct(rawReceipt, &ReceiptData, 0, 0);
	int32 totalNotes = FCString::Atoi(*ReceiptData.Gettotal_authentic()) + FCString::Atoi(*ReceiptData.Gettotal_fracked());
	int32 totalCoins = 0;
	for (int i = 0; i < ReceiptData.receipt.Num(); i++)
	{
		if (ReceiptData.receipt[i].Getstatus() == "authentic")
			totalCoins += GetDenomination(FCString::Atoi(*ReceiptData.receipt[i].Getsn()));
	}
	interpretation = "receipt number: " + ReceiptData.Getreceipt_id() + " total authentic notes: " + FString::FromInt(totalNotes) + " total authentic coins: " + FString::FromInt(totalCoins);
	inter->interpretation = interpretation;
	inter->receipt = ReceiptData;
	inter->totalAuthenticCoins = totalCoins;
	inter->totalAuthenticNotes = totalNotes;

	return inter;
}

/**
 * @brief    Writes a CloudCoin stack file for the CloudCoin retrieved the last call
 *           of either GetStackFromCloudBank or GetReceiptFromCloudBank.
 * @param    path The full file path where the new file will be written.
 */
void UCloudBankUtils::SaveStackToFile(FString path)
{
	FString filepath = path + GetStackName();
	FFileHelper::SaveStringToFile(rawStackFromWithdrawal, *filepath);
}

/**
 * @brief    Generate a filename for the CloudCoin stack file being written by SaveStackToFile
 */
FString UCloudBankUtils::GetStackName()
{
	if (receiptNumber.IsEmpty())
	{
		FDateTime currentDate = FDateTime::Now();
		FString month = FString::FromInt(currentDate.GetMonth());
		FString day = FString::FromInt(currentDate.GetDay());
		FString year = FString::FromInt(currentDate.GetYear());
		FString hour = FString::FromInt(currentDate.GetHour12());
		FString minute = FString::FromInt(currentDate.GetMinute());
		FString second = FString::FromInt(currentDate.GetSecond());
		FString millisecond = FString::FromInt(currentDate.GetMillisecond());

		if (FCString::Atoi(*month) < 10)
			month = "0" + month;
		if (FCString::Atoi(*day) < 10)
			day = "0" + day;
		if (FCString::Atoi(*hour) < 10)
			hour = "0" + hour;
		if (FCString::Atoi(*minute) < 10)
			minute = "0" + minute;
		if (FCString::Atoi(*second) < 10)
			hour = "0" + second;
		if (FCString::Atoi(*millisecond) < 10)
			millisecond = "0" + millisecond;

		FString tag = "Withdrawal" + month + day + year + hour + minute + second + millisecond;
		return FString::FromInt(totalCoinsWithdrawn) + ".CloudCoin." + tag + ".stack";
	}
	return FString::FromInt(totalCoinsWithdrawn) + ".CloudCoin." + receiptNumber + ".stack";
}

/**
 * @brief    Calls WithdrawStack and DepositStack in order to transfer CloudCoins from on CloudService to another
 * @param    toPublicKey The public url of the CloudService that is receiving the CloudCoins
 * @param    coinsToSend The amount of CloudCoins to be transfered
 */
void UCloudBankUtils::TransferCloudCoins(FString toPublicKey, int32 coinsToSend)
{
	FString publicKey = keys->GetPublicKey();
	FString privateKey = keys->GetPrivateKey();
	FString service = "/service/withdraw_one_stack";
	FString account = keys->GetAccount();
	this->toPublicKey = toPublicKey;

	Http = &FHttpModule::Get();
	TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UCloudBankUtils::TransferCloudCoinsResponse);
	Request->SetURL(TEXT("https://" + publicKey + service + "?amount=" + FString::FromInt(coinsToSend) + "&pk=" + privateKey + "&account=" + account));
	Request->SetVerb(TEXT("GET"));
	SetHeaders(Request);
	Request->ProcessRequest();
}

/**
 * @brief    Saves the retrieved CloudCoin stack into rawStackFromWithdrawal which
 *           is then saved to rawStackForDeposit in order to deposit it
 */
void UCloudBankUtils::TransferCloudCoinsResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (!bWasSuccessful)
	{
		UE_LOG(LogTemp, Error, TEXT("Error! Check your connection, or your public key"));
		return;
	}

	rawStackFromWithdrawal = Response->GetContentAsString();
	rawStackForDeposit = rawStackFromWithdrawal;

	DepositStackTo(toPublicKey);
}

// Set the headers for the requests
void UCloudBankUtils::SetHeaders(TSharedRef<IHttpRequest>& Request)
{
	Request->SetHeader(TEXT("User-Agent"), TEXT("X-UnrealEngine-Agent"));
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/x-www-form-urlencoded"));
	Request->SetHeader(TEXT("Accepts"), TEXT("application/x-www-form-urlencoded"));
}
