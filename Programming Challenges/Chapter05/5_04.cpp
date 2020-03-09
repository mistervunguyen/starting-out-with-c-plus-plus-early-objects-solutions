// Chapter 5 - Programming Challenge 4, Celsius to Fahrenheit Table
// This program uses a for loop to display a Celsius to Fahrenheit 
// temperature conversion table. Students may choose to use a different
// type of loop.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double fahrenheit;		       // temperature in Fahrenheit

	// Output table headings
	cout << "Temperature Conversion Table\n\n";
	cout << "Celsius   Fahrenheit\n"
		 << "____________________\n";

	// Set output format
	cout << fixed << showpoint << setprecision(1);

	for (int celsius = 0; celsius <= 30; celsius++)
	{
		// Perform conversion
		fahrenheit = ((9.0/5.0) * celsius) + 32;

		// Display results
		cout << setw(4) << celsius << setw(12)  << fahrenheit << endl;
	}
	return 0;
}

/* CORRECT RESULTS 

Temperature Conversion Table

Celsius   Fahrenheit
____________________
   0        32.0
   1        33.8
   2        35.6
   3        37.4
   4        39.2
   5        41.0
   6        42.8
   7        44.6
   8        46.4
   9        48.2
  10        50.0
  11        51.8
  12        53.6
  13        55.4
  14        57.2
  15        59.0
  16        60.8
  17        62.6
  18        64.4
  19        66.2
  20        68.0
  21        69.8
  22        71.6
  23        73.4
  24        75.2
  25        77.0
  26        78.8
  27        80.6
  28        82.4
  29        84.2
  30        86.0
*/
