#pragma once
#ifndef DISPLAYANDCALCULATEINTEREST_H
#define DISPLAYANDCALCULATEINTEREST_H
#include <iostream> // Declare all libraries here instead of in the .cpp
#include <iomanip>  // for this class.
#include <string>

using namespace std;

class DisplayAndCalculateInterest {
public:
	void StoreData();
	void CalculateInterestWithoutMonthly();
	void CalculateInterestWithMonthly();
private:
	void SectionHeader(); // The user does not need to be able to use this function.
	double initialInvestment = 0; // Variables are initialized to prevent errors.
	double monthlyDeposit = 0;
	double annualInterest = 0;
	int numYears = 0;
};

#endif