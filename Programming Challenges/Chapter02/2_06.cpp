// Chapter 2 - Programming Challenge 6, Distance per Tank of Gas
// This program calculates how far a car can travel on a tank of gas.
#include <iostream>
using namespace std;

int main()
{
	double gallonsInTank = 20.0; // Gas tank capacity in gallons
	double mpgTown = 23.5;       // Miles per gallon in town
	double mpgHighway = 28.9;    // Miles per gallon on the highway
	double townDistance;         // Distance car can travel in town
	double highwayDistance;      // Distance car can travel on the highway

	// Compute travel distances
	townDistance = gallonsInTank * mpgTown;
	highwayDistance = gallonsInTank * mpgHighway;
   
	// Display results
	cout << "The car can drive " << townDistance << " miles in town and \n" 
	     << highwayDistance << " miles on the highway on a tank of gas.\n";
	    
	return 0;
}

/* CORRECT RESULTS
The car can drive 470 miles in town and
578 miles on the highway on a tank of gas.
*/
