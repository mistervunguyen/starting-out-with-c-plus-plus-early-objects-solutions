// Chapter 2 - Programming Challenge 9, Circuit Board Price 
// This program calculates the selling price of a circuit board.
// Because students have not yet learned to format output, the 
// dollar output will not be rounded to two decimal places.
#include <iostream>
using namespace std;

int main()
{
	double boardCost = 14.95;    // Seller's cost to produce the board
	double profitPct =   .35;    // Desired percent profit
	double boardSellingPrice;    // Board selling price

	// Calculate board selling price
	boardSellingPrice = boardCost * (1 + profitPct);

	// Display result
	cout << "To have a 35% profit, the selling price of a circuit \n"
	     << "board that costs $" << boardCost << " to produce should be $" 
	     << boardSellingPrice << endl;

	return 0;
}
/* CORRECT RESULTS
To have a 35% profit, the selling price of a circuit
board that costs $14.95 to produce should be $20.1825
*/
