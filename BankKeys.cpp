/**
 * @file BankKeys.cpp
 *
 * @brief
 *    Getter and setter function definitions for the keys of a CloudService
 *    server. A UBankKeys object needs to be initialized using the SetBankKeys
 *    function in order to initialize that object with the keys for a
 *    CloudService server.
 */

#include "BankKeys.h"

// Sets default values for this component's properties
UBankKeys::UBankKeys()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

/**
* @brief    Constructor for UBankKeys
* @param    publicKey The CloudService server
* @param    privateKey The Private Key for the CloudService server
* @param    account The Account
*/
void UBankKeys::SetBankKeys(const FString publicKey, const FString privateKey, const FString account)
{
	this->publicKey = publicKey;
	this->privateKey = privateKey;
	this->account = account;
}

/**
* @brief     Getter function for Public Key
* @return    publicKey
*/
FString UBankKeys::GetPublicKey() const
{
	return publicKey;
}

/**
* @brief    Setter function for Public Key
* @param    value The Public Key
*/
void UBankKeys::SetPublicKey(const FString &value)
{
	publicKey = value;
}

/**
* @brief    Getter function for Private Key
* @return   privateKey
*/
FString UBankKeys::GetPrivateKey() const
{
	return privateKey;
}

/**
* @brief    Setter function for Private Key
* @param    value The Private Key
*/
void UBankKeys::SetPrivateKey(const FString &value)
{
	privateKey = value;
}

/**
* @brief    Getter function for Account
* @return   account
*/
FString UBankKeys::GetAccount() const
{
	return account;
}

/**
* @brief    Setter function for Account
* @param    value The Account
*/
void UBankKeys::SetAccount(const FString &value)
{
	account = value;
}
