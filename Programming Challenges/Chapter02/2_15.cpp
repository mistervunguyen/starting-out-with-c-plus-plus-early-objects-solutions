// Chapter 2 - Programming Challenge 15, Stock Loss
// This program calculates the amount of loss on a stock transaction.
// Because students have not yet learned to format output, the dollar
// amount will not be displayed rounded to two decimal places.
#include <iostream>
using namespace std;

int main()
{  
	int numShares = 750;                // Number of shares of stock
	double unitPurchasePrice = 35.00;   // Price paid per share when bought
	double unitSellingPrice  = 31.15;   // Price received per share when sold
	double totalPurchasePrice;          // Total paid for all the stock shares
	double totalSellingPrice;           // Total received for all the stock shares
	double loss;                        // Amount of money lost
	
	// Compute total purchase price, total selling price, and amount lost
	totalPurchasePrice = numShares * unitPurchasePrice;
	totalSellingPrice  = numShares * unitSellingPrice;
	loss = totalPurchasePrice - totalSellingPrice;
	
	// Display the results
	cout << "Amount paid to buy the stock:            $ " << totalPurchasePrice << endl;
	cout << "Amount received from selling the stock:  $ " << totalSellingPrice  << endl;
	cout << "Amount of money lost on the transaction: $ " << loss << endl;
	
	return 0;
}
/* CORRECT RESULTS
Amount paid to buy the stock:            $ 26250
Amount received from selling the stock:  $ 23362.5
Amount of money lost on the transaction: $ 2887.5
*/
