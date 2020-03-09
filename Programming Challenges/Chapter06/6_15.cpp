// Chapter 6 - Programming Challenge 15, Order Status
// This program displays the status of an order for copper wire.
// It uses one function to input and validate order information
// and a second one to display the order status report.
#include <iostream>
#include <iomanip>
using namespace std;

const double UNIT_SPOOL_COST = 100.00, 
	         SHIPPING_CHARGE  = 10.00;

// Function prototypes
void getOrderInfo (int &, int &, double &);
void displayStatus(int, int, double = SHIPPING_CHARGE);

int main()
{
	int numOrdered = 0,          // Number of spools ordered
		inStock = 0;             // Number of spools in stock
	double specialChgs = 0.0;    // Special charges (if any) to ship the spools

	getOrderInfo(numOrdered, inStock, specialChgs);

	if (specialChgs >= .01)
		displayStatus(numOrdered, inStock, SHIPPING_CHARGE + specialChgs);
  	else
		displayStatus(numOrdered, inStock);

	return 0;
}// end of main function

/*************************************************************
 *                        getOrderInfo                       *
 * This function is called by main to input and validate     *
 * the number of spools ordered, the number in stock, and    *
 * any special shipping charges. These values are stored in  *
 * reference parameters.                                     *
 *************************************************************/
void getOrderInfo(int &ord, int &stock, double &specChg)
{
	cout << "How many spools were ordered? ";
	cin  >> ord;
	while (ord < 1)
	{	cout << "The number of spools ordered must be one or more. "
			 << "Please re-enter: ";
		cin  >> ord;
	} 
   
	cout << "How many spools are in stock? ";
	cin  >> stock;
	while (stock < 0)
	{	cout << "The number of spools in stock must be zero or more. "
			 << "Please re-enter: ";
		cin  >> stock;
	}
   
	cout << fixed << showpoint << setprecision(2);
	cout << "\nAmount of any special shipping charges (per spool)\n"
		 << "above the regular $" << SHIPPING_CHARGE 
		 << " per spool rate (0 for none): ";
	cin  >> specChg;
	
	while (specChg < 0.0)
	{	cout << "The extra shipping charges must be zero or more. "
			 << "Please re-enter: ";
		cin  >> specChg;
	}
}// end of function getStockInfo

/***************************************************************
 *                       displayStatus                         *
 * This function is called by main and passed as arguments the *
 * number of spools ordered, the number in stock, and the      *
 * shipping charge per spool. The default value for shipping   *
 * charge is $10.00. This information is used to display an    *
 * order status report.                                        *
 ***************************************************************/
void displayStatus(int numOrdered, int inStock, double unitShipChg)
{
	int shipNow = numOrdered,   // Number of spools available to ship now
		backOrder = 0;          // Number of spools that must be
	                            // back ordered to fill the order
	        
	double totalSpoolCost,      // Amount customer is being billed for
		                        // the spools being shipped now
		   shipCharges,         // Shipping charges for this shipment
		   totalCharges;        // Cost of shipped spools + shipping chgs 
			
	if (numOrdered > inStock)
	{
		shipNow   = inStock;
		backOrder = numOrdered - inStock;
	}
	totalSpoolCost = shipNow * UNIT_SPOOL_COST;
	shipCharges    = shipNow * unitShipChg;
	totalCharges   = totalSpoolCost + shipCharges;

	cout << fixed << showpoint <<setprecision(2);
	cout << "\n     *** Order Summary *** \n\n";
	cout << "Spools ordered :          " << setw(5) << numOrdered << endl;
	cout << "Spools in this shipment:  " << setw(5) << shipNow << endl;
   
	if (shipNow < numOrdered)
		cout << "Spools back ordered:      " << setw(5) << backOrder << endl;

	cout << "\n   Charges for this shipment\n"
		 <<   "   -------------------------\n";
	cout << "Spool charges:        $" << setw(8) << totalSpoolCost << endl;
	cout << "Shipping charges:     $" << setw(8) << shipCharges << endl;
	cout << "Total this shipment:  $" << setw(8) << totalCharges << endl;
	
}// end of function displayStatus

/* SAMPLE RUN RESULTS 

How many spools were ordered? 5
How many spools are in stock? 3

Amount of any special shipping charges (per spool)
above the regular $10.00 per spool rate (0 for none): 0

*** Order Summary ***

Spools ordered :              5
Spools in this shipment:      3
Spools back ordered:          2

Charges for this shipment
-------------------------
Spool charges:        $  300.00
Shipping charges:     $   30.00
Total this shipment:  $  330.00
*/
