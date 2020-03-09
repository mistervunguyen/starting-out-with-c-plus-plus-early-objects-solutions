// Chapter 1 - Programming Challenge 2, Baseball Costs
// This program calculates the amount a baseball team spent on baseball purchases.
// Note: Because students are creating this program by modifying Program 1-1 
// and have not yet learned about different data types, all variables are 
// declared as doubles, as in Program 1-1.
#include <iostream>
using namespace std;

int main()
{
	double ballsPurchased, unitCost, totalCost;

	// Get the number of baseballs purchased.
	cout << "How many baseballs were purchased? ";
	cin  >> ballsPurchased;

	// Get the cost of each ball.
	cout << "How much did each ball cost? ";
	cin  >> unitCost;

	// Calculate the total amount spent.
	totalCost = ballsPurchased * unitCost;

	// Display the total amount spent.
	cout << "The total amount spent on baseballs was $" << totalCost << endl;
	return 0;
}

/* SAMPLE RUN RESULTS
How many baseballs were purchased? 12
How much did each ball cost? 8.95
The total amount spent on baseballs was $107.4
*/
