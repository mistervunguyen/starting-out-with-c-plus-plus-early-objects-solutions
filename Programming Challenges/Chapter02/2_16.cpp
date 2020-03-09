// Chapter 2 - Programming Challenge 16, Energy Drink Consumption
// This program calculates and displays information on energy drink consumption.
// Students have not yet learned to cast floating-point values to int, so results
// are truncated to an int at the time they are assigned to an int variable.
#include <iostream>
using namespace std;

int main()
{  
	int customersSurveyed = 16500;    // Number of soft drink customers surveyed
	double energyDrinkPct = .15;      // % of these customers who buy energy drinks
	int energyDrinkCustomers;         // Number who buy energy drinks
	double citrusPct = .52;           // % of these customers who buy citrus flavors
	int citrusBuyers;                 // Number who buy citrus flavors
	
	// Calculate number of surveyed customers who buy energy drinks
	// and number who buy citrus flavored energy drinks
	energyDrinkCustomers = customersSurveyed * energyDrinkPct;  // Truncate result to an int
	citrusBuyers = energyDrinkCustomers * citrusPct;            // Truncate result to an int
	
	// Display the results
	cout << "Of " << customersSurveyed << " soft drink customers surveyed about " 
		 << energyDrinkCustomers  << "\nbuy at least one energy drink per week. Of these\n"
	     << "approximately " << citrusBuyers << " buy citrus-flavored energy drinks.\n";
		 
	return 0;
}

/* CORRECT RESULTS
Of 16500 soft drink customers surveyed about 2475
buy at least one energy drink per week. Of these
approximately 1287 buy citrus-flavored energy drinks.
*/
