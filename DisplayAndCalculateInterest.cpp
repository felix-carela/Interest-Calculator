#include "DisplayAndCalculateInterest.h" // Includes the header file.

void DisplayAndCalculateInterest::SectionHeader() { // This function is a private function that is not usable by main.
	cout << setw(12) << left << "Year";
	cout << setw(27) << left << "Year End Balance";          // This function eliminates redundancy since
	cout << setw(20) << left << "Year End Interest" << endl; // it is called twice from two other functions.
}

void DisplayAndCalculateInterest::StoreData() { // This function prompts the user for the required data.
	cout << "Initial Investment Amount: ";
	cin >> initialInvestment;
	cout << "Monthly Deposit: ";
	cin >> monthlyDeposit;
	cout << "Annual Interest: ";
	cin >> annualInterest;
	cout << "Number of Years: ";
	cin >> numYears;
	cout << endl << endl;
}

/* This function calculates and displays most information within it. It also uses several local 
   variables to help calculate information. */
void DisplayAndCalculateInterest::CalculateInterestWithoutMonthly() {
	double endingInvestment = initialInvestment;
	double tempInvestment;
	double endingDifference;

	cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
	
	SectionHeader();
	
	for (int i = 1; i <= numYears; i++) { // This for loop repeats up to the total
		cout << setw(12) << i;            // number of years inputted.
		
		tempInvestment = endingInvestment; // This variable holds information for a later calculations.
		endingInvestment = endingInvestment + (endingInvestment * (annualInterest / 100));
		
		cout << "$" << setw(26) << setprecision(2) << fixed << endingInvestment;

		endingDifference = endingInvestment - tempInvestment;

		cout << "$" << endingDifference << endl;
	}
	
	cout << endl;
}

/* This function has more calculations than the previous function since it has to calculate
   the interest using the monthlyDeposit variable. */
void DisplayAndCalculateInterest::CalculateInterestWithMonthly() {
	double endingInvestment = initialInvestment;
	double tempInvestment = initialInvestment;
	double endingDifference;
	double monthlyGain = initialInvestment;
	double calculatedInterest;
	double totalInterest = 0;

	cout << "Balance and Interest With Additional Monthly Deposits" << endl;

	SectionHeader();

	for (int i = 1; i <= numYears; i++) {
		cout << setw(12) << i;

		for (int j = 1; j <= 12; j++) { // This for loop calculates and retains the total interest.
			calculatedInterest = (tempInvestment + monthlyDeposit) * ((annualInterest / 100) / 12);
			totalInterest += calculatedInterest;
			monthlyGain = tempInvestment + monthlyDeposit + calculatedInterest;
			tempInvestment = monthlyGain; // tempInvestment holds the data from monthlyGain for the 
		}                                 // next iteratio and for after the for loop ends.
		
		endingInvestment = tempInvestment;

		cout << "$" << setw(26) << setprecision(2) << fixed << endingInvestment;
		cout << "$" << totalInterest << endl;

		totalInterest = 0; // totalInterest is reset to 0 for the next iteration.
	}

	cout << endl << endl;
}