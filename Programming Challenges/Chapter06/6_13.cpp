// Chapter 6 - Programming Challenge 13, Stock Profit
// This program uses a function to return the profit, or loss,
// from the sale of a previously purchased stock.
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototype
double stockProfit (int, double, double, double, double);

int main()
{
	int numShares;         // Number of stock shares purchased and later sold
	double buyPrice,       // Price per share when bought
		   sellPrice,      // Price per share when sold
		   buyComm,        // Broker commission to buy the stock
		   sellComm,       // Broker commission to sell the stock
		   profit;         // A negative number indicates a loss

	// Input the data
	// The program specs do not request data validation, 
	// though the instructor may ask students to include this.
	cout << "This program determines the profit or loss from stock transactions.\n\n";
	cout << "Number of shares sold: ";
	cin  >> numShares;

	cout << "Price per share when sold: $";
	cin  >> sellPrice; 

	cout << "Broker commission paid on the sale: $";
	cin  >> sellComm;

	cout << "\nPrice per share when bought: $";
	cin  >> buyPrice;

	cout << "Broker commission paid on the purchase: $";
	cin  >> buyComm;

	// Call the stockProfit function to determine the amount of profit or loss
	profit = stockProfit(numShares, buyPrice, buyComm, sellPrice, sellComm);

	// Display the results
	cout << fixed << setprecision(2);

	if (profit > 0.0)
		cout << "\nYou made a profit of $" << profit << endl;
	else if (profit < 0.0)
		cout << "\nYou had a loss of $" << -profit << endl;
	else
		cout << "\nYou broke even on your stock transactions.\n";   

	return 0;
}

/*********************************************************************
 *                           stockProfit                             *
 * This function uses the 5 pieces of data passed to it to calculate *
 * and return the profit or loss made on the sale of a previously    *
 * purchased stock.                                                  *
 *********************************************************************/
double stockProfit (int numShares, double purchasePrice, double purchaseComm,
					double salePrice, double saleComm)
{
	double profit = (numShares * salePrice - saleComm) - 
		            (numShares * purchasePrice + purchaseComm);
	return profit;
}

/* SAMPLE RUN RESULTS

This program determines the profit or loss from stock transactions.

Number of shares sold: 100
Price per share when sold: $32.20
Broker commission paid on the sale: $10

Price per share when bought: $28.44
Broker commission paid on the purchase: $10

You made a profit of $356.00
*/