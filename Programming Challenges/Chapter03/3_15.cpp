// Chapter 3 - Programming Challenge 15, Currency
// This program converts U.S. dollars into foreign currency.
// Note: More current conversion rates can be found on the Internet.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const double YEN_PER_DOLLAR = 120.005,  // Dollars to yen conversion factor 
		         EUROS_PER_DOLLAR =  .881;  // Dollars to euros conversion factor 

	double dollars,                         // Dollar amount to convert
		   yen,                             // Equivalent in Japanese yen
		   euros;                           // Equivalent in euros

	// Get dollar amount to convert
	cout << "Amount of U.S. currency to convert: $";
	cin  >> dollars;

	// Perform conversions
	yen   = dollars * YEN_PER_DOLLAR;
	euros = dollars * EUROS_PER_DOLLAR;
	
	// Display results
	cout << fixed << showpoint << setprecision(2);
	cout << "$" << dollars << " = " << yen << " yen and " 
		 << euros << " euros.\n";
  
	return 0;
}

/* SAMPLE RUN RESULTS

Amount of U.S. currency to convert: $200
$200.00 = 24001.00 yen and 176.20 euros.
*/
