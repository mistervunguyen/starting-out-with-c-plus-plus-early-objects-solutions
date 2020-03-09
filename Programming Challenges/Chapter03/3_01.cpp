// Chapter 3 - Programming Challenge 1, Miles per Gallon
// This program calculates the number of miles per gallon a car gets.
#include <iostream>
using namespace std;

int main()
{
	double gallonsInTank,   // Gas tank capacity (in gallons)
		   milesPerTank,    // Miles car can go on one tank of gas
		   mpg;             // Calculated miles per gallon car gets
          
	// Prompt user for gas tank capacity and number of miles
	cout << "This program calculates how many miles per gallon a vehicle gets. \n\n";
	cout << "How many gallons of gas does the car's tank hold? ";
	cin  >> gallonsInTank;

	cout << "How many miles can the car travel on one tank of gas? ";
	cin  >> milesPerTank;

	// Calculate and display the miles per gallon
	mpg = milesPerTank / gallonsInTank;
	cout << "\nThis car gets " << mpg << " miles per gallon. \n";

	return 0;
}

/* SAMPLE RUN RESULTS

This program calculates how many miles per gallon a vehicle gets.

How many gallons of gas does the car's tank hold? 20
How many miles can the car travel on one tank of gas? 450

This car gets 22.5 miles per gallon.
*/
