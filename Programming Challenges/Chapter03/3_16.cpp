// Chapter 3 - Programming Challege 16, Monthly Sales Tax
// This program creates a monthly report on sales and taxes.
// Note: Results may be "off" by a penny since students have 
// not yet learned how to handle roundoff error.
#include <iostream>
#include <iomanip>
#include <string>                     // Needed by most compilers to use strings
using namespace std;

int main()
{
	const double ST_TAX_RATE = .04,   // State sales tax rate
		         CO_TAX_RATE = .02;   // County sales tax rate

	double totalCollected,            // Total money collected
		   sales,                     // Product sales
		   coTaxAmt,                  // County sales tax collected
		   stTaxAmt,                  // State sales tax collected
		   totalTaxAmt;               // Total amount of sales tax collected

	string month;                     // Month of the report
	int    year;                      // Year of the report

	// Get user input
	cout << "Please enter the month for this report: ";
	cin  >> month;
	cout << "Please enter the year for this report: ";
	cin  >> year;
	cout << "Please enter the total dollar amount collected this month: ";
	cin  >> totalCollected;

	// Perform calculations
	sales = totalCollected / (1 + (ST_TAX_RATE + CO_TAX_RATE));
	stTaxAmt  = sales * ST_TAX_RATE;
	coTaxAmt  = sales * CO_TAX_RATE;
	totalTaxAmt = coTaxAmt + stTaxAmt;

	// Display results
	cout << "\nMonth:  " << setw(9) << month << ", " << year << endl;
	cout << "-----------------------\n";
	cout << fixed << showpoint << setprecision(2);
	cout << "Total Collected:       $" << setw(9) << totalCollected << endl;
	cout << "Sales:                 $" << setw(9) << sales << endl;
	cout << "County Sales Tax:      $" << setw(9) << coTaxAmt  << endl;
	cout << "State Sales Tax:       $" << setw(9) << stTaxAmt  << endl;
	cout << "Total Sales Tax:       $" << setw(9) << totalTaxAmt << endl;
	cout << "-----------------------\n";

	return 0;
}
