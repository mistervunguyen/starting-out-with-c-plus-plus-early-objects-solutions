// Chapter 3 - Programming Challenge 22, Pizza Slices 

//	This program calculates the number of slices in a pizza.
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;			

int main()
{
	const double PI = 3.14,
		         SLICE_SIZE = 14.125;   // Sq. inches in each slice

	double pizzaDiameter,       // Diameter of the pizza (in inches)
		   pizzaRadius,         // Radius of the pizza (in inches)
		   pizzaArea,           // Area of the pizza (in sq. inches)
		   slicesPerPizza;      // Number of slice to cut pizza into

	// Input pizza diameter
	cout << "Enter the pizza diameter (in inches): ";
	cin  >> pizzaDiameter;

	// Perform calculations
	pizzaRadius = pizzaDiameter / 2;
	pizzaArea = PI * pow(pizzaRadius, 2);
	slicesPerPizza = pizzaArea / SLICE_SIZE;

	// Display results
	cout << fixed << setprecision(0);  // Display result to nearest whole number
	cout << "Cut this pizza into " << slicesPerPizza << " slices." << endl;

	return 0;
}

/* SAMPLE RUN RESULTS

Enter the pizza diameter (in inches): 14
Cut this pizza into 11 slices.
*/
