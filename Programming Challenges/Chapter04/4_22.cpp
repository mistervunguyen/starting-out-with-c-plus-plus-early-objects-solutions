// Chapter 4 - Programming Challenge 22, Mobile Service Provider
// This program creates a monthly bill for mobile phone customer 
// based on their package plan and the amount of usage. 
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	const double
		A_BASE_COST = 39.95,      // Base charge for plans A & B
		B_BASE_COST = 59.95,
		A_EXTRA_MIN_CHG = .45,    // Extra min.charge for plans A  & B
		B_EXTRA_MIN_CHG = .40,
		C_COST = 69.95;           // Total cost for plan C (unlimited mins)

	const int A_FREE_MINUTES = 450,    
		      B_FREE_MINUTES = 900;

	string  custName;
	char    package;                // User's plan: A, B, or C
	int     minutes;                // Monthly minutes used
	double  aCost, bCost;           // Monthly charges under plans A & B
	bool    validInput = true;

	// Input and validate package information
	cout << "Customer name: ";
	getline(cin, custName);
	cout << "Which mobile service package is used (A, B, or C)? ";
	cin  >> package;
   
	if (package != 'A' && package != 'a' &&
		package != 'B' && package != 'b' &&
		package != 'C' && package != 'c')
	{
		cout << "Enter only A, B, or C for the package.\n";
		validInput = false;
	}
	else // Package is OK, so input and validate hours used
	{
		cout << "How many minutes were used last month? ";
		cin  >> minutes;
	}

	if (validInput)
	{
		//Set output format and display statement heading
		cout << fixed << showpoint << setprecision(2);
		cout << "\nMonthly Statement for " << custName << endl;
		cout << "Plan " << package << " -- minutes used: " << minutes << endl;

		// Compute and display charges
		aCost = A_BASE_COST;
		if (minutes > A_FREE_MINUTES)
			aCost += (minutes - A_FREE_MINUTES) * A_EXTRA_MIN_CHG;

		bCost = B_BASE_COST;
		if (minutes > B_FREE_MINUTES)
			bCost += (minutes - B_FREE_MINUTES) * B_EXTRA_MIN_CHG;

		switch (package)
		{
		case 'A':
		case 'a':	cout << "The charges are $" << aCost << endl << endl;
			if (aCost > bCost)
				cout << "By switching to Package B you would save $"
				<< (aCost - bCost) << endl;

			if (aCost > C_COST)
				cout << "By switching to Package C you would save $"
				<< (aCost - C_COST) << endl;
			break;
		case 'B':
		case 'b':  cout << "The charges are $" << bCost << endl;
			if (bCost > C_COST)
				cout << "\nBy switching to Package C you would save $"
				<< (bCost - C_COST) << endl;
			break;
		case 'C':
		case 'c': 	cout << "The charges are $" << C_COST << endl;
		}
	}
  	return 0;
}

/* SAMPLE RUN RESULT

Customer name: George washington
Which mobile service package is used (A, B, or C)? A
How many minutes were used last month? 540

Monthly Statement for George washington
Plan A -- minutes used: 540
The charges are $80.45

By switching to Package B you would save $20.50
By switching to Package C you would save $10.50
*/
