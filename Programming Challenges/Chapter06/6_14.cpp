// Chapter 6 - Programming Challenge 14, Multiple Stock Sales
// This program modifies Programming Challenge 13 to handle
// multiple stock transactions.
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototype
double stockProfit (int, double, double, double, double);

int main()
{
	int transaction = 0,  // Transaction number for a stock buy/sell transaction
		numShares;        // Number of stock shares purchased and later sold 
	                      //   in a buy/sell transaction

	double buyPrice,      // Price per share when bought
		   sellPrice,     // Price per share when sold
		   buyComm,       // Broker commission to buy the stock
		   sellComm,      // Broker commission to sell the stock
		   profit = 0.0;  // A negative number indicates a loss

	char doAnother;       // Enter another transaction? (Y/N)

	cout << "This program determines the total profit or loss \n"
		 << "from a set of stock transactions.\n";
	// Loop once for each stock buy/sell transaction
	do
	{   // Input the data
		// Program specs do not request data validation tho' the instructor may
		// ask students to include this.
		cout << "\n*****************************\n"
			 << "Buy/Sell transaction number " << ++transaction
			 << "\n*****************************\n";
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
		// Add the result to the cumulative profit variable
		profit += stockProfit(numShares, buyPrice, buyComm, sellPrice, sellComm);

		// Does the user want to enter another transaction?
		cin.get();          // Flush the \n from the input buffer
		cout << "\nIs there another buy/sell transaction (Y/N)? ";
		cin  >> doAnother;
	} while (doAnother == 'y' || doAnother == 'Y');

	// Display the cumulative profit or loss from all the transactions
	cout << fixed << setprecision(2);

	cout << "\n*************************************************************";
	if (profit > 0.0)
		cout << "\nYou made a profit of $" << profit << " on the " 
		     << transaction << " buy/sell transactions. \n";
	else if (profit < 0.0)
		cout << "\nYou had a loss of $" << -profit << " on the " 
		     << transaction << " buy/sell transactions. \n";
	else
		cout << "\nYou broke even on your " << transaction 
		     << " stock transactions. \n";   

	cout << "*************************************************************\n";

	return 0;
}// end of main function

/*********************************************************************
 *                           stockProfit                             *
 * This function uses the 5 pieces of data passed to it to calculate *
 * and return the profit or loss made on the sale of a previously    *
 * purchased stock. If the result is negative, there was a loss.     *
 *********************************************************************/
double stockProfit (int numShares, double purchasePrice, double purchaseComm, 
                    double salePrice, double saleComm)
{
	double profit = (numShares * salePrice - saleComm) - 
                    (numShares * purchasePrice + purchaseComm);
	return profit;
	
}// end of stockProfit function

/* SAMPLE RUN RESULTS

Number of shares sold: 100
Price per share when sold: $44.12
Broker commission paid on the sale: $10

Price per share when bought: $38.19
Broker commission paid on the purchase: $10

Is there another buy/sell transaction (Y/N)? Y

*****************************
Buy/Sell transaction number 2
*****************************
Number of shares sold: 50
Price per share when sold: $28.30
Broker commission paid on the sale: $10

Price per share when bought: $28.83
Broker commission paid on the purchase: $10

Is there another buy/sell transaction (Y/N)? N

*************************************************************
You made a profit of $526.50 on the 2 buy/sell transactions.
*************************************************************
*/
