// Chapter 3 - Programming Challenge 25, Stock Transaction Program
// This program keeps track of expenditures and earnings for stock
// that was bought and later sold.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const int NUM_SHARES = 100;            // Number of shares of stock
	const double BUY_PRICE = 45.50,        // Price per share when bought
		         SELL_PRICE = 47.92,       // Price per share when sold
				 COMMISSION_PCT = .02;     // % of buy or sell total paid to broker

	double buyTotal,                       // Total paid for stock
		   buyCommission,                  // Commission paid to buy the stock
		   totalPaid,                      // Stock cost + buy commission
		   sellTotal,                      // Total received for stock
		   sellCommission,                 // Commission paid to sell the stock
		   totalReceived,                  // Stock earnings less sell commission

		   profitOrLoss;                   // Amount gained or lost on the transactions

	// Perform calculations for the purchase
	buyTotal = NUM_SHARES * BUY_PRICE;
	buyCommission = buyTotal * COMMISSION_PCT;
	totalPaid = buyTotal + buyCommission;

	// Perform calculations for the sale
	sellTotal = NUM_SHARES * SELL_PRICE;
	sellCommission = sellTotal * COMMISSION_PCT;
	totalReceived = sellTotal - sellCommission;

	// Calculate profit or loss
	profitOrLoss = totalReceived - totalPaid;

	// Display results
	cout << fixed << setprecision(2);
	cout << "Total paid for stock    :  $" << setw(8) << buyTotal << endl;
	cout << "Purchase commission     :  $" << setw(8) << buyCommission << endl << endl;
	cout << "Total received for stock:  $" << setw(8) << sellTotal << endl;
	cout << "Sales commission        :  $" << setw(8) << sellCommission << endl << endl;
	cout << "Amount of profit or loss:  $" << setw(8) << profitOrLoss << endl;

	return 0;
}

/* CORRECT RESULTS

Total paid for stock    :  $ 4550.00
Purchase commission     :  $   91.00

Total received for stock:  $ 4792.00
Sales commission        :  $   95.84

Amount of profit or loss:  $   55.16
*/
