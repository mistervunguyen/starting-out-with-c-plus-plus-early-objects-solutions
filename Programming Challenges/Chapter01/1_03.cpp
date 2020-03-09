// Chapter 1 - Programming Challenge 3, Flower Garden
// This program calculates the total amount spent to
// to make a flower garden.
#include <iostream>
using namespace std;

int main()
{
	double soilCost, seedsCost, fenceCost, totalCost;

	// Describe the program
	cout << "This program computes the total amount "
		 << "spent to create a flower garden." << endl << endl;;
	
	// Get the costs
	cout << "How much was spent for soil? $";
	cin  >> soilCost;

	cout << "How much was spent for seeds? $";
	cin  >> seedsCost;

	cout << "How much was spent for the fence? $";
	cin  >> fenceCost;

	// Calculate and display the total amount spent
	totalCost = soilCost + seedsCost + fenceCost;

	cout << "The total amount spent to make the "
		 << "flower garden was $" << totalCost << endl;
	return 0;
}

/* SAMPLE RUN RESULTS

This program computes the total amount spent to create a flower garden.

How much was spent for soil? $25
How much was spent for seeds? $10.50
How much was spent for the fence? $21
The total amount spent to make the flower garden was $56.5
*/