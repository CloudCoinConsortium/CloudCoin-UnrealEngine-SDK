/**
 * @file DepositResponse.cpp
 *
 * @brief
 *    Getter and setter function definitions for deposit response attributes.
 */

#include "DepositResponse.h"


// Sets default values for this component's properties
UDepositResponse::UDepositResponse()
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
FString UDepositResponse::GetBankServer() const
{
	return bank_server;
}

/**
 * @brief    Setter function for bank server
 * @param    value The bank server
 */
void UDepositResponse::SetBankServer(const FString &value)
{
	bank_server = value;
}

/**
 * @brief    Getter function for time
 * @return   The deposit time
 */
FString UDepositResponse::GetTime() const
{
	return time;
}

/**
 * @brief    Setter function for time
 * @param    value The deposit time
 */
void UDepositResponse::SetTime(const FString &value)
{
	time = value;
}

/**
 * @brief    Getter function for status
 * @return   The deposit status
 */
FString UDepositResponse::GetStatus() const
{
	return status;
}

/**
 * @brief    Setter function for status
 * @param    value The deposit status
 */
void UDepositResponse::SetStatus(const FString &value)
{
	status = value;
}

/**
 * @brief    Getter fucntion for message
 * @return   The deposit message
 */
FString UDepositResponse::GetMessage() const
{
	return message;
}

/**
 * @brief    Setter function for message
 * @param    value The deposit message
 */
void UDepositResponse::SetMessage(const FString &value)
{
	message = value;
}

/**
* @brief    Getter function for account
* @return   The account
*/
FString UDepositResponse::GetAccount() const
{
	return account;
}

/**
 * @brief    Setter function for account
 * @param    value The account
 */
void UDepositResponse::SetAccount(const FString &value)
{
	account = value;
}

/**
 * @brief    Getter function for receipt
 * @return   The deposit receipt
 */
FString UDepositResponse::GetReceipt() const
{
	return receipt;
}

/**
 * @brief    Setter function for receipt
 * @param    value The deposit receipt
 */
void UDepositResponse::SetReceipt(const FString &value)
{
	receipt = value;
}
