// Chapter 6 - Programming Challenge 1, Markup
// This program uses a function that calculates retail 
// price when given the wholesale cost and markup.
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototype
double calculateRetail(double, double);	

int main()
{
	double wholesale,            // Wholesale price of the item
		   markup,               // Markup percentage
		   sellingPrice;         // Retail selling price of the item

	// Get and validate user inputs
	cout << "Enter the item's wholesale cost: ";
	cin  >> wholesale;
	cout << "Enter the item's markup percentage (e.g. 15.0): ";
	cin  >> markup;
   
	while (wholesale < 0 || markup < 0)
	{	cout << "Re-enter values using positive numbers only please.\n";
		cout << "Enter the item's wholesale cost: ";
		cin  >> wholesale;
		cout << "Enter the item's markup percentage (e.g. 15.0): ";
		cin  >> markup;
	}	
   
	// Call the calculateRetail function, passing it wholesale and markup 
	// as arguments. Store the value it returns in the sellingPrice variable.
	sellingPrice = calculateRetail(wholesale, markup);
	
	// Display the results
	cout << fixed << showpoint << setprecision(2);
	cout << "\nThe retail price is $" << sellingPrice << endl;

	return 0;

}// end of main function

/***************************************************************
 *                       calculateRetail                       *
 *	This function accepts an item's wholesale cost and markup  *
 * percentage as arguments. It uses them to calculate the      *
 * retail price. The retail price of the item is returned.     *
 ***************************************************************/
double calculateRetail(double whole, double pct)
{
	double price = whole + (whole * (pct/100));  // Calculate retail price
	return price;                                // and pass it back to main 
	
}// end of calculateRetail function

/* SAMPLE RUN OUTPUT

Enter the item's wholesale cost: 8.00
Enter the item's markup percentage (e.g. 15.0): 30

The retail price is $10.40
*/
