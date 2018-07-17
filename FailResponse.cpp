/**
 * @file FailResponse.cpp
 *
 * @brief
 *    Getter and setter function definitions for failed deposit response
 *    attributes.
 */

#include "FailResponse.h"


// Sets default values for this component's properties
UFailResponse::UFailResponse()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


/**
 * @brief    Getter function for bank server
 * @return   The bank server
 */
FString UFailResponse::GetBankServer() const
{
	return bank_server;
}

/**
 * @brief    Setter function for bank server
 * @param    value The bank server
 */
void UFailResponse::SetBankServer(const FString &value)
{
	bank_server = value;
}

/**
 * @brief    Getter function for time
 * @return   The fail time
 */
FString UFailResponse::GetTime() const
{
	return time;
}

/**
 * @brief    Setter function for time
 * @param    value The fail time
 */
void UFailResponse::SetTime(const FString &value)
{
	time = value;
}

/**
 * @brief    Getter function for status
 * @return   The fail status
 */
FString UFailResponse::GetStatus() const
{
	return status;
}

/**
 * @brief    Setter function for status
 * @param    value The fail status
 */
void UFailResponse::SetStatus(const FString &value)
{
	status = value;
}

/**
 * @brief    Getter function for message
 * @return   The fail message
 */
FString UFailResponse::GetMessage() const
{
	return message;
}

/**
 * @brief    Setter function for message
 * @param    value The fail message
 */
void UFailResponse::SetMessage(const FString &value)
{
	message = value;
}

/**
 * @brief    Getter function for account
 * @return   The account
 */
FString UFailResponse::GetAccount() const
{
	return account;
}

/**
 * @brief    Setter function for account
 * @param    value the account
 */
void UFailResponse::SetAccount(const FString &value)
{
	account = value;
}

/**
 * @brief    Getter functino for receipt
 * @return   The fail receipt
 */
FString UFailResponse::GetReceipt() const
{
	return receipt;
}

/**
 * @brief    Setter function for receipt
 * @param    value The fail receipt
 */
void UFailResponse::SetReceipt(const FString &value)
{
	receipt = value;
}
