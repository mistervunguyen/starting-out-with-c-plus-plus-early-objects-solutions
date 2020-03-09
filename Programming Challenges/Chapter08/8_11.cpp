// Chapter 8 - Programming Challenge 11, Chips and Salsa Version 2
// This program produces a sales report for a salsa maker who markets
// 5 types of salsa. It revises Programming Challenge 4 to use an array 
// of Product objects, instead of two parallel arrays, to hold the names
// and prices of the products.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Products class declaration
class Products
{
public:
   string name;
   int sales;
   
   // Constructor
   Products (string n = "unknown")
   {   name = n; 
   }
   
 };
 
 // Client Program that uses the Products class.

// Function prototypes
int getSalesData(Products []);
int posOfLargest(Products [] );
int posOfSmallest(Products [] );
void displayReport(Products [], int);

const int SIZE = 5;

int main()
{
    // Create and initialize the array of Products
    Products salsas[SIZE] = {string("mild  "), string("medium"), string("sweet "),
                             string("hot   "),  string("zesty ")};  
							 
/*	NOTE: The following lines may also be used in place of the above statement.
	Products salsas[SIZE];
	salsas[0].name = "mild  ";
	salsas[1].name = "medium";
	salsas[2].name = "sweet ";
	salsas[3].name = "hot   ";
	salsas[4].name = "zesty ";
*/
	int totalJarsSold = getSalesData(salsas);
	
	displayReport(salsas, totalJarsSold);

  	return 0;
}

/***************************************************************
 *                      getSalesData                           *
 * Accepts the sales figures for each salsa type and stores    *
 * them in the Products array passed to the function, as well  *
 * as accumulating and returning the total of all salsas sold. *
 ***************************************************************/
int getSalesData(Products salsa[])
{
	int total = 0;
	
	for (int type = 0; type < SIZE; type++)
	{
		cout << "Jars sold last month of " << salsa[type].name << ": ";
		cin  >> salsa[type].sales;
      
		while (salsa[type].sales < 0)
		{	cout << "Jars sold must be 0 or more.  Please re-enter: ";
			cin  >> salsa[type].sales;
		}
		
		total += salsa[type].sales;
	}
	return total;
}


/*******************************************************
 *                    displayReport                    *
 * Displays a sales report using information from the  *
 * arguments passed to it.                             *
 *******************************************************/
void displayReport(Products salsa[], int total) 
{
	int hiSalesProduct = posOfLargest(salsa);
	int loSalesProduct = posOfSmallest(salsa);
	
	cout << "\n\n Salsa Sales Report \n\n";
	cout << "Name       Jars Sold \n";
	cout << "____________________\n";

	for (int type = 0; type < SIZE; type++)
		cout << salsa[type].name << setw(10) << salsa[type].sales << endl;

	cout << "\nTotal Sales: " << total << endl;
	cout << "High Seller: "   << salsa[hiSalesProduct].name << endl;
	cout << "Low Seller : "   << salsa[loSalesProduct].name << endl;
}

/********************************************************
 *                    posOfLargest                      *
 * Finds and returns the subscript of the element with  *
 * the highest sales value in the array passed to it.   *
 ********************************************************/
int posOfLargest(Products salsa[]) 
{
	int indexOfLargest = 0;
   
	for (int pos = 1; pos < SIZE; pos++)
	{
		if (salsa[pos].sales > salsa[indexOfLargest].sales)
			indexOfLargest = pos;
	}   
	return indexOfLargest;
}


/*******************************************************
 *                    posOfSmallest                    *
 * Finds and returns the subscript of the element with *
 * the lowest sales value in the array passed to it.   *
 *******************************************************/
int posOfSmallest(Products salsa[]) 
{
	int indexOfSmallest = 0;
	
	for (int pos = 1; pos < SIZE; pos++)
	{
		if (salsa[pos].sales < salsa[indexOfSmallest].sales)
			indexOfSmallest = pos;
	}		
	return indexOfSmallest;
}

/* SAMPLE RUN RESULT

Jars sold last month of mild  : 316
Jars sold last month of medium: 841
Jars sold last month of sweet : 183
Jars sold last month of hot   : 411
Jars sold last month of zesty : 352

Salsa Sales Report

Name       Jars Sold
____________________
mild          316
medium        841
sweet         183
hot           411
zesty         352

Total Sales: 2103
High Seller: medium
Low Seller : sweet
*/
