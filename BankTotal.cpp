// Fill out your copyright notice in the Description page of Project Settings.

#include "BankTotal.h"


// Sets default values for this component's properties
UBankTotal::UBankTotal()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UBankTotal::SetBankTotal(int ones, int fives, int twentyFives, int hundreds, int twoHundredFifties)
{
	this->SetOnes(ones);
	this->SetFives(fives);
	this->SetTwentyFives(twentyFives);
	this->SetHundreds(hundreds);
	this->SetTwoHundredFifties(twoHundredFifties);
}

int UBankTotal::GetOnes() const
{
	return privateOnes;
}

void UBankTotal::SetOnes(const int &value)
{
	privateOnes = value;
}

int UBankTotal::GetFives() const
{
	return privateFives;
}

void UBankTotal::SetFives(const int &value)
{
	privateFives = value;
}

int UBankTotal::GetTwentyFives() const
{
	return privateTwentyFives;
}

void UBankTotal::SetTwentyFives(const int &value)
{
	privateTwentyFives = value;
}

int UBankTotal::GetHundreds() const
{
	return privateHundreds;
}

void UBankTotal::SetHundreds(const int &value)
{
	privateHundreds = value;
}

int UBankTotal::GetTwoHundredFifties() const
{
	return privateTwoHundredFifties;
}

void UBankTotal::SetTwoHundredFifties(const int &value)
{
	privateTwoHundredFifties = value;
}
