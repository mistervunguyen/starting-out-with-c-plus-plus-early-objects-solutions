// Chapter 3 - Programming Challenge 23, How Many Pizzas? 
// This program calculates the number of pizzas needed for a party.
// It displays the result rounded to the nearest whole number.
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;			

int main()
{
	const double PI = 3.14,
	             SLICE_SIZE = 14.125;	 // Sq. inches in each slice
	const int    SLICES_PER_PERSON = 4;  // Pizza slices per person
               
  	double pizzaDiameter,		 // Diameter of the pizza (in inches)
		   pizzaRadius,          // Radius of the pizza (in inches)
		   pizzaArea,	         // Area of the pizza (in sq. inches)
		   slicesPerPizza,       // Number of slice to cut pizza into
		   pizzasNeeded;         // Number of pizzas needed 

	int    numGuests,            // Number of people at the party
		   slicesNeeded;         // Total number of sliced needed
       
	// Request input from user
	cout << "Enter the number of people expected at the party: ";
	cin  >> numGuests;
	cout << "Enter the diameter of the pizzas (in inches): ";
	cin  >> pizzaDiameter;

	// Perform calculations
	slicesNeeded = numGuests * SLICES_PER_PERSON; 
	pizzaRadius = pizzaDiameter / 2;
	pizzaArea = PI * pow(pizzaRadius, 2);
	slicesPerPizza = pizzaArea / SLICE_SIZE; 
	pizzasNeeded = slicesNeeded / slicesPerPizza;
   
	// Display results
	cout << fixed << setprecision(0) << endl;
	cout << pizzasNeeded << " " << pizzaDiameter 
		 << "-inch pizzas should be ordered." << endl;

	return 0;
}

/* SAMPLE RUN RESULTS

Enter the number of people expected at the party: 12
Enter the diameter of the pizzas (in inches): 14

4 14-inch pizzas should be ordered.
*/
