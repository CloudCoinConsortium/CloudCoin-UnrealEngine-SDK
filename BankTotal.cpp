/**
 * @file BankTotal.cpp
 *
 * @brief
 *    Getter and setter function definitions for CloudBank notes.
 */

#include "BankTotal.h"

// Sets default values for this component's properties
UBankTotal::UBankTotal()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

/**
 * @brief    Used to inizialize the values in a UBankTotal object
 */
void UBankTotal::SetBankTotal(int ones, int fives, int twentyFives, int hundreds, int twoHundredFifties)
{
	this->SetOnes(ones);
	this->SetFives(fives);
	this->SetTwentyFives(twentyFives);
	this->SetHundreds(hundreds);
	this->SetTwoHundredFifties(twoHundredFifties);
}

/**
 * @brief    Getter function for ones
 * @return   The number of ones in bank
 */
int UBankTotal::GetOnes() const
{
	return privateOnes;
}

/**
 * @brief    Setter function for ones
 * @param    value The number of ones in bank
 */
void UBankTotal::SetOnes(const int &value)
{
	privateOnes = value;
}

/**
 * @brief    Getter function for fives
 * @return   The number of fives in bank
 */
int UBankTotal::GetFives() const
{
	return privateFives;
}

/**
 * @brief    Setter function for fives
 * @param    value The number of fives in bank
 */
void UBankTotal::SetFives(const int &value)
{
	privateFives = value;
}

/**
 * @brief    Getter function for twenty fives
 * @return   The number of twenty fives in bank
 */
int UBankTotal::GetTwentyFives() const
{
	return privateTwentyFives;
}

/**
 * @brief    Setter function for twenty fives
 * @param    value The number of twenty fives in bank
 */
void UBankTotal::SetTwentyFives(const int &value)
{
	privateTwentyFives = value;
}

/**
 * @brief    Getter function for hundreds
 * @return   The number of hundreds in bank
 */
int UBankTotal::GetHundreds() const
{
	return privateHundreds;
}

/**
 * @brief    Setter function for hundreds
 * @param    value The number of hundreds in bank
 */
void UBankTotal::SetHundreds(const int &value)
{
	privateHundreds = value;
}

/**
 * @brief    Getter function for two hundred fifties
 * @return   The number of twho hundred fifties in bank
 */
int UBankTotal::GetTwoHundredFifties() const
{
	return privateTwoHundredFifties;
}

/**
 * @brief    Setter function for two hundred fifties
 * @param    value The number of two hundred fifties in bank
 */
void UBankTotal::SetTwoHundredFifties(const int &value)
{
	privateTwoHundredFifties = value;
}
