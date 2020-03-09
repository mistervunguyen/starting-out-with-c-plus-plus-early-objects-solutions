// Chapter 2 - Programming Challenge 5, Miles per Gallon 
// This program calculates how many miles per gallon a vehicle gets.
#include <iostream>
using namespace std;

int main()
{
	// Define and initialize variables
	double gallonsInTank = 16.0;   // Gas tank capacity in gallons
	double milesPerTank = 312.0;   // Miles driven on one tank
	double milesPerGallon;         // Miles per gallon

	// Calculate miles per gallon
   milesPerGallon = milesPerTank / gallonsInTank;
   
   // Display result
	cout << "The car gets " << milesPerGallon << " miles per gallon.\n";  

	return 0;
}

/* CORRECT RESULTS 
The car gets 19.5 miles per gallon.
*/
