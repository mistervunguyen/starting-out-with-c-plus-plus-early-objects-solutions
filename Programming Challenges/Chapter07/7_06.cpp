// Chapter 7 - Programming Challenge 6, Gratuity Calculator
// This program utilizes a Tips class to calculate the gratuity on
// a restaurant meal, using whatever tip percent the patron desires.
#include <iostream>
#include <iomanip>
using namespace std;

class Tips
{
  private:
	double taxRate;

  public:
	Tips(double rate = .065)    // Constructor that accepts a tax rate
	{                           // or uses a default value of 6.5%
		if (rate >= 0)
			taxRate = rate;
		else
			taxRate = .065;
	}
	double computeTip(double, double);
};

/***********************************************************
 *                  Tips::computeTip                       *
 * This public class member function computes and returns  *
 * the correct tip amount based on a restaurant bill and   *
 * the percentage a patron wishes to tip.                  *
 ***********************************************************/
double Tips::computeTip(double totalBill, double tipRate)
{
	double mealCost = totalBill / (1 + taxRate);
	double tipAmount = mealCost * tipRate;

	return tipAmount;
}
   
//********************** Client program *********************
	
int main()
{
	double totalBill,         // Total bill for food and tax
		   taxRate,           // Tax rate
		   tipRate,           // % the patron wishes to tip
		   tipAmt;            // Dollar amount of the tip
	char   doAgain;           // Compute another tip (Y/N)?

	cout << fixed << showpoint << setprecision(2);
	cout << "This program will compute a restaurant tip based on a\n"
		 << "total bill amount and % the patron wishes to tip the server.\n";

	// Input and validate the tax rate
	cout << "\nTax % for this location: ";
	cin  >> taxRate;
	while (taxRate < 0)
	{	cout << "Tip % cannot be less than 0. "
			 << "Please re-enter tip %: ";
		cin >> taxRate;
	}
	taxRate = taxRate / 100;       // Convert from % to decimal

	// **** Create a Tips object with the correct tax rate ****
	Tips tipHelper(taxRate);

	// Begin main processing loop
	do
	{
		cout << "\n************* Tip Helper *********** \n";

		// Input and validate the total bill amount
		cout << "\nEnter total bill amount: ";
		cin  >> totalBill;
		while (totalBill < 0)
		{
			cout << "Total cannot be less than 0. "
				 << "Please re-enter total bill amount: ";
			cin  >> totalBill;
		}

		// Input and validate the desired tip percentage
		cout << "Enter desired tip % ";
		cin  >> tipRate;
		while (tipRate < 0)
		{
			cout << "Tip % cannot be less than 0. "
				 << "Please re-enter tip %: ";
			cin  >> tipRate;
		}

		tipRate = tipRate / 100;    // Convert from percentage to decimal

		// Call the Tips class computeTip function to compute the tip amount
		tipAmt = tipHelper.computeTip(totalBill, tipRate);

		// Display the result
		cout << "\nThe tip should be $ " << tipAmt << endl << endl;

		// Does the user want to calculate another tip?
		cout << "Compute another tip (y/n)? ";
		cin  >> doAgain;
	} while (toupper(doAgain) == 'Y');

	return 0;
}

/* SAMPLE RUN RESULTS

This program will compute a restaurant tip based on a
total bill amount and % the patron wishes to tip the server.

Tax % for this location: 6.25

************* Tip Helper ***********

Enter total bill amount: 42.19
Enter desired tip % 18

The tip should be $ 7.15

Compute another tip (y/n)? n
*/