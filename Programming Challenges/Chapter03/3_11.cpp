// Chapter 3 - Programming Challenge 11, How Many Widgets? 
// This program calculates the number of widgets on a pallet.
// It uses a type cast.
#include <iostream>
using namespace std;

int main()
{
	const double WIDGET_WT = 12.5;  // Weight of one widget (in pounds)

	double emptyPalletWt,           // Weight of empty pallet (in pounds)
		   fullPalletWt;            // Weight of full pallet (in pounds)

	int numWidgets;                 // Number of widgets on pallet

	// Prompt user for input
	cout << "Weight of the empty pallet in pounds: ";
	cin  >> emptyPalletWt;
	cout << "Weight of the loaded pallet in pounds: ";
	cin  >> fullPalletWt;

	// Calculate the number of widgets
	numWidgets = static_cast<int>((fullPalletWt - emptyPalletWt) / WIDGET_WT);
	
	// Display result
	cout << "\nThere are " << numWidgets << " widgets on the pallet." << endl;

	return 0;
}

/* SAMPLE RUN RESULTS

Weight of the empty pallet in pounds: 16
Weight of the loaded pallet in pounds: 1641

There are 130 widgets on the pallet.
*/
