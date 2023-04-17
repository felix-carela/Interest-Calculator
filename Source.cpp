/* Felix A. Carela
   4/9/2023
   This program displays and calculates an investment given inital value, 
   monthly deposit, interest rate, and number of years. */
#include <iostream>
#include <string>
#include "DisplayAndCalculateInterest.h" // Loads the header file.

using namespace std;

int main() {
	string continueLoop = "c"; // This string is used within the while loops description.
	DisplayAndCalculateInterest interestScenario; // Makes an object of type DisplayAndCalculateInterest.
	
	cout << "Data Input" << endl << endl;

	while (continueLoop == "c") { // Does not exit the loop if the user types "c".
		interestScenario.StoreData();
		interestScenario.CalculateInterestWithoutMonthly();
		interestScenario.CalculateInterestWithMonthly(); // Three functions are called which are 
		                                                 // used to store and display data.
		cout <<  "Type \"c\" to continue or \"s\" to stop : ";
		cin >> continueLoop;  // Uses this variable to allow the user to choose whether 
		cout << endl << endl; // the program continues or stops.
	}

	cout << "Goodbye" << endl << endl;

	return 0;
}