// Chapter 7 - Programming Challenge 10, Corporate Sales Data
// This program stores and displays corporate sales data. The data 
// is stored in structures which are passed to a function that 
// displays the data.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct CorpData
{
	string name;     // Division name
	long qtr1;       // Holds a division's sales data for each of 4 quarters
	long qtr2;
	long qtr3;
	long qtr4;

	// Cconstructor with 5 parameters and default values specified
	// for when no arguments, or fewer than 5 arguments, are received
	CorpData(string n = " ", long q1 = 0, long q2 = 0,
		                     long q3 = 0, long q4 = 0)
	{	name = n;
		qtr1 = q1;
		qtr2 = q2;
		qtr3 = q3;
		qtr4 = q4;
	}
};

// Function prototype
void displaySalesInfo(const CorpData &);

int main()
{
	// Define and initialize 4 CorpData structures
	CorpData east ("East ", 621900, 620400, 611900, 634500),
		     west ("West ", 531000, 538000, 549200, 588100),
			 north("North", 482900, 477500, 479200, 489600),
			 south("South", 658900, 644900, 653000, 660100);  

	cout << " Annual Sales Report by Division \n\n";
	cout << "Division     Annual       Avg. Qtr. \n";
	cout << "  Name        Sales         Sales   \n";
	cout << "----------------------------------- \n";

	displaySalesInfo(east);
	displaySalesInfo(west);
	displaySalesInfo(north);
	displaySalesInfo(south);

	return 0;
}// end main function

/**********************************************************
 *                displaySalesInfo                        *
 * This function displays the annual sales and average    *
 * quarterly sales for the CorpData structure variable    *
 * passed to it.                                          *
 *********************************************************/
void displaySalesInfo(const CorpData &div)
{
	double annualSales = div.qtr1 + div.qtr2 + div.qtr3 + div.qtr4;
	double avgQtrSales = annualSales / 4;
	
	cout << div.name << "    $" << setw(9) << annualSales
                     << "    $" << setw(9) << avgQtrSales << endl; 
					 
}// end displaySalesInfo function

/* OUTPUT PRODUCED BY THIS PROGRAM

Annual Sales Report by Division

Division     Annual       Avg. Qtr.
  Name        Sales         Sales
-----------------------------------
East     $2.4887e+006    $   622175
West     $2.2063e+006    $   551575
North    $1.9292e+006    $   482300
South    $2.6169e+006    $   654225
*/
