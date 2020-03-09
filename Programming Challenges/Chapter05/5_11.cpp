// Chapter 5 - Programming Challenge 11, Membership Fee Increase
// This program creates a table of projected annual country club
// membership fees over the next six years.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const double CURRENT_FEE = 3000.00,    // Current annual membership fee
		         ANNUAL_INCREASE = .03;    // Annual % fee increase

	double fee = CURRENT_FEE;              // Set the starting annual fee

	// Set the output format
	cout << fixed << setprecision(2);

	// Display table heading and current year's fee
	cout << "        Country Club \n"
	     << "         Membership  \n"
		 << " Year       Fee      \n"
		 << "-------------------- \n";
	cout << "Current" << setw(11) << fee <<  endl;   // Students may omit these 2 lines
	cout << "-------------------- \n";

	// Create and display the table
	for (int year = 1; year <= 5; year++)
	{
		fee = fee * (1 + ANNUAL_INCREASE);
		cout << setw(4) << year << setw(14) << fee << endl;
	}
	return 0;
}

/* CORRECT RESULTS

        Country Club
         Membership
 Year       Fee
--------------------
Current    3000.00
--------------------
   1       3090.00
   2       3182.70
   3       3278.18
   4       3376.53
   5       3477.82
*/