// Chapter 5 - Programming Challenge 29, 
//             Using Files--Savings Account Balance Modification
// This program creates a quarterly savings account statement. It 
// modifies Programming Challenge 23 to write the statement to a file.
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	ofstream report;           // Output stream variable to access the output file
	double
		yrInterestRate,         // Annual interest rate
		moInterestRate,         // Monthly interest rate
		startBal,               // Balance at start of the 3-mo. period
		moBegBal,               // Balance at the beginning of a month
		currentBal,             // Balance at intermediate point in a month
		moEndBal,               // Balance at the end of a month
		avgMoBal,               // Average monthly balance
		deposited,              // Amount deposited in a single month
		withdrawn,              // Amount withdrawn in a single month
		moIntPaid,              // Interest paid in a single month
		totalDeposits = 0.0,    // Total of all deposits
		totalWithdrawals = 0.0, // Total of all withdrawals
		totalInterest = 0.0;    // Total interest earned

	// Set the output format
	cout << fixed << showpoint << setprecision(2);

	// Input initial account information
	cout << "Enter the starting balance on the account: $";
	cin  >> startBal;
	moEndBal = startBal;        // Set previous month's ending balance
	                            // equal to starting balance
	cout << "Enter the annual interest rate on the account (e.g. .04): ";
	cin  >> yrInterestRate;
	moInterestRate = yrInterestRate / 12;

	// Loop to get and process data for each month during the quarter
	for (int month = 1; month <= 3; month++)
	{
		// Set this month's staring balance = previous month's ending balance
		moBegBal = moEndBal;   

		// Input & validate amount deposited this month
		cout << "\nMonth " << month << endl;
		cout << "Total deposits for this month:    $";
		cin  >> deposited;
		while (deposited < 0)
		{	cout << "Deposits must be zero or greater. Please re-enter: $";
			cin  >> deposited;
		} 

		// Add deposits to current balance and keep running total of all deposits
		currentBal = moBegBal + deposited;
		totalDeposits += deposited;         

		// Input & validate amount withdrawn this month
		cout << "Total withdrawals for this month: $";
		cin  >> withdrawn;
		while (withdrawn < 0 || withdrawn > currentBal)
		{
			cout << "Withdrawals must be zero or greater and cannot be\n"
				 << "greater than the current monthly balance of " << currentBal
				 << ".\nPlease re-enter this month's withdrawals: $";
			cin  >> withdrawn;
		}

		// Subtract WDs from current balance and keep running total of all WDs
		currentBal -= withdrawn;             
		totalWithdrawals += withdrawn;

		// Compute average monthly balance and monthly interests
		avgMoBal = (moBegBal + currentBal) / 2;
		moIntPaid = avgMoBal * moInterestRate;
		
		// Keep running total of all interest paid & add interest to current
		// balance to get month's ending balance
		totalInterest += moIntPaid;
		moEndBal = currentBal + moIntPaid;
	}
 
	// Open the file and write the quarterly report to it
	report.open("SaveStmt");
	report << fixed << showpoint << setprecision(2);
	report << "Quarterly Savings Account Statement\n\n";
	report << "Starting balance:    $" << setw(10) << startBal << endl;
	report << "Total deposits:    + $" << setw(10) << totalDeposits << endl; 
	report << "Total withdrawals: - $" << setw(10) << totalWithdrawals << endl;
	report << "Total interest:    + $" << setw(10) << totalInterest << endl;
	report << "                      __________\n";
	report << "Ending balance:      $" << setw(10) << moEndBal;

	// Close the file and print a message to the screen
	report.close();
	cout << "\nQuarterly report has been written to the SaveStmt file.\n";

	return 0;
}

/* SAMPLE RUN RESULTS

Enter the starting balance on the account: $1000
Enter the annual interest rate on the account (e.g. .04): .015

Month 1
Total deposits for this month:    $300
Total withdrawals for this month: $0

Month 2
Total deposits for this month:    $250
Total withdrawals for this month: $100

Month 3
Total deposits for this month:    $300
Total withdrawals for this month: $0

Quarterly report has been written to the SaveStmt file.

CONTENTS OF THE OUTPUT FILE

Quarterly Savings Account Statement

Starting balance:    $   1000.00
Total deposits:    + $    850.00
Total withdrawals: - $    100.00
Total interest:    + $      5.16
                      __________
Ending balance:      $   1755.16
*/
