// Chapter 5 - Programming Challenge 16, Rate of Inflation
// Given the rate of inflation, this program creates a table illustrating
// how much $1000 today will be worth each year over the next 10 years.
// Values may be "off" by a penny due to round-off error.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const double 
		STARTING_VALUE = 1000.00,     // Starting amount of money
		MIN_INFLATION_RATE = .01,     // Minimum annual inflation rate = 1%
		MAX_INFLATION_RATE = .10;     // Maximum annual inflation rate = 10%

	double inflationRate,             // User input annual inflation rate
		                              // converted from % to decimal
		   value = STARTING_VALUE;    // Value of the money after a period of years
	                                  // (Initially = STARTING_VALUE)
	// Set the output format
	cout << fixed << setprecision(2);

	// Input and validate the inflation rate
	cout << "Enter the annual rate of inflation (between " 
		 << MIN_INFLATION_RATE << " and " <<  MAX_INFLATION_RATE << "): ";
	cin  >> inflationRate;
	while (inflationRate < MIN_INFLATION_RATE || inflationRate > MAX_INFLATION_RATE)
	{
		cout << "Inflation rate must be between " << MIN_INFLATION_RATE << " and "
			 << MAX_INFLATION_RATE << " -- Re-enter rate: ";  
		cin  >> inflationRate;
	}

	// Display table heading and starting amount of money
	cout << "\n Year       Worth    \n"
		 << "-------------------- \n";
	cout << "Current" << setw(11) << value <<  endl;   // Students may omit these 2 lines
	cout << "-------------------- \n\n";

	// Create and display the table
	for (int year = 1; year <= 10; year++)
	{
		value = value / (1 + inflationRate); 
		cout << setw(4) << year << setw(14) << value << endl;
	}
	return 0;
}

/* SAMPLE RUN RESULTS

Enter the annual rate of inflation (between 0.01 and 0.10): 5
Inflation rate must be between 0.01 and 0.10 -- Re-enter rate: .05

 Year       Worth
--------------------
Current    1000.00
--------------------
   1        952.38
   2        907.03
   3        863.84
   4        822.70
   5        783.53
   6        746.22
   7        710.68
   8        676.84
   9        644.61
  10        613.91
*/
