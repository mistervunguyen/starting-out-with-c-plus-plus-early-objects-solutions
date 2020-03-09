// Chapter 2 - Programming Challenge 3, Sales Tax 
// This program calculates sales tax on a purchase.
// Because students have not yet learned to format output, dollar
// amounts will not be displayed rounded to two decimal places.
#include <iostream>
using namespace std;

int main()
{
	// Define and initialize variables
	double purchasePrice = 95.00,   // Purchase amount
	       stateTaxRate  = .065,    // State sales tax rate
	       countyTaxRate = .02,     // County sales tax rate
	       stateTax,                // State sales tax amount
	       countyTax,               // County sales tax amount
	       totalSalesTax;           // Total sales tax amount

	// Calculate taxes
	stateTax  = purchasePrice * stateTaxRate;
	countyTax = purchasePrice * countyTaxRate;
	totalSalesTax = stateTax + countyTax;

	// Display Results
	cout << "Purchase price   $ " << purchasePrice << endl;
	cout << "State sales tax  $ " << stateTax << endl;
	cout << "County sales tax $ " << countyTax << endl;
	cout << "Total sales tax  $ " << totalSalesTax << endl;

	return 0;
}

/* CORRECT RESULTS
Purchase price   $ 95
State sales tax  $ 6.175
County sales tax $ 1.9
Total sales tax  $ 8.075
*/

