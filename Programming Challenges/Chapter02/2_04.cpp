// Chapter 2 - Programming Challenge 4, Restaurant Bill 
// This program calculates the tax and tip on a restaurant bill.
// Because students have not yet learned to format output, dollar
// amounts will not be displayed rounded to two decimal places.
#include <iostream>
using namespace std;

int main()
{
	// Define and initialize variables
	double mealCost = 44.50,       // Meal cost
	       taxRate  = .0675,       // Tax rate
	       tipRate  = .15,         // Tip percentage
	       taxAmt,                 // Tax amount
	       tipAmt,                 // Tip amount
	       totalBill;              // Total amount to pay

	// Calculate tax, tip, and total
	taxAmt = taxRate * mealCost;
	tipAmt = tipRate * (mealCost + taxAmt);
	totalBill = mealCost + taxAmt + tipAmt;

	// Display Results
	cout << "Meal Cost $"  << mealCost << endl;
	cout << "Tax       $ " << taxAmt << endl;
	cout << "Tip       $ " << tipAmt << endl;
	cout << "Total     $"  << totalBill << endl;

	return 0;
}
/* CORRECT RESULTS
Meal Cost $44.5
Tax       $ 3.00375
Tip       $ 7.12556
Total     $54.6293
*/
