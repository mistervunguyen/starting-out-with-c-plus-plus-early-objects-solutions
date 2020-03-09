// Chapter 4 - Programming Challenge 10, Bank Charges 
// This program computes a bank customer's checking account fees for a month.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const double MO_FEE = 15.00;  // Base monthly fee charged to all accounts
      
	int    numChecks;             // Number of checks written during the month
	double checkFee,              // Fee based on number of checks written
		   totalFees;             // Total monthly bank fees
	
	// Input number of checks written
	cout << "Number of checks written this month: ";
	cin  >> numChecks;
	
	if (numChecks < 0)
		cout << "Number of checks must be zero or more.\n";
	else
	{  // Calculate checkFee		
		if (numChecks < 20)
			checkFee = numChecks * 0.10;
		else if (numChecks <= 39)
			checkFee = numChecks * 0.08;
		else if (numChecks <= 59)
			checkFee = numChecks * 0.06;
		else // 60 or more checks were written
			checkFee = numChecks * 0.04;

		// Calculate total fees
		totalFees = MO_FEE + checkFee;
		
		// Display the formatted result
		cout << fixed << showpoint << setprecision(2);
		cout << "The bank fee this month is $" << totalFees << endl;
	}
	return 0;
}

/* SAMPLE RUN RESULTS

Number of checks written this month: 22
The bank fee this month is $16.76
*/
