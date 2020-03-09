// Chapter 3 - Programming Challenge 21, Monthly Payments 
// This program performs loan calculations.  Note: Results may vary
// by a penny from those shown in the text due to roundoff error.
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std; 

int main()
{
	double loanAmt,		   // Amount of the loan
		   intRate,		   // Annual interest rate of the loan
		   monIntRate,	   // Monthly interest rate
		   monPayment,	   // Monthly payment 
		   totIntPaid,	   // Total interest paid over life of loan
		   totAmtPaid;	   // Total amount paid over life of loan

	int	numPayments;	   // Number of payments

	// Get input from user
	cout << "Loan amount: $";
	cin  >> loanAmt;
	cout << "Annual interest rate (in the format .12 (for 12%): ";
	cin  >> intRate;
	cout << "Number of monthly payments to be made: ";
	cin  >> numPayments;

	// Calculate monthly interest rate, amount of the monthly payment, 
	// total amount paid, and total interest paid
	monIntRate = intRate / 12;
	monPayment = (monIntRate * pow((1 + monIntRate), numPayments) /
				 (pow((1 + monIntRate), numPayments) - 1)) * loanAmt;
	totAmtPaid = monPayment * numPayments;
	totIntPaid = totAmtPaid - loanAmt;
   
   // Display results
	cout << "\n - - Loan Report - -\n\n";
	cout << fixed << showpoint << setprecision(2);
	cout << "Loan Amount:            $"	<< setw(9) << loanAmt << endl;
	cout << "Monthly Interest Rate:   " << setw(8) << (monIntRate * 100)
		 << "%"   <<  endl;
	cout << "Number of Payments:      " << setw(9) << numPayments << endl;
	cout << "Monthly Payment:        $" << setw(9) << monPayment << endl;
	cout << "Amount Paid Back:       $" << setw(9) << totAmtPaid << endl;
	cout << "Interest Paid:          $" << setw(9) << totIntPaid << endl;

	return 0;
}
