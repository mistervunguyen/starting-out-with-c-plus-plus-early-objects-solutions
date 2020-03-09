// Chapter 8 - Programming Challenge 4, Chips and Salsa
// This program produces a sales report for a salsa maker who markets
// 5 types of salsa. It includes total sales for all products and 
// identifies the highest and lowest selling product. Two parallel 
// arrays are used to store the salsa names and quantities sold of each.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes
int getSalesData(string [], int []);
int posOfLargest(int []);
int posOfSmallest(int []);
void displayReport(string [], int [], int);

const int SIZE = 5;

int main()
{

	string name[SIZE] = {"mild  ", "medium", "sweet ", "hot   ", "zesty "}; 
	int sales[SIZE];   // Holds jars sold for each salsa type

	int totalJarsSold = getSalesData(name, sales);
	
	displayReport(name, sales, totalJarsSold);

  	return 0;
}

/************************************************************
 *                    getSalesData                          *
 * Accepts the sales figures for each salsa type and stores *
 * them in the array passed to the function, as well as     *
 * accumulating and returning the total of all salsas sold. *
 ************************************************************/
int getSalesData(string name[], int sales[])
{
	int total = 0;
	
	for (int type = 0; type < SIZE; type++)
	{
		cout << "Jars sold last month of " << name[type] << ": ";
		cin  >> sales[type];
      
		while (sales[type] < 0)
		{	cout << "Jars sold must be 0 or more.  Please re-enter: ";
			cin  >> sales[type];
		}
		
		total += sales[type];
	}
	return total;
}


/************************************************************
 *                    displayReport                         *
 * Displays the sales report using information from the     *
 * arrays passed to it.
 ************************************************************/
void displayReport(string name[], int sales[], int total)
{
	int hiSalesProduct = posOfLargest(sales);
	int loSalesProduct = posOfSmallest(sales);
	
	cout << "\n Salsa Sales Report \n\n";
	cout << "Name       Jars Sold \n";
	cout << "____________________\n";

	for (int type = 0; type < SIZE; type++)
		cout << name[type] << setw(11) << sales[type] << endl;

	cout << "\nTotal Sales: " << total << endl;
	cout << "High Seller: "   << name[hiSalesProduct] << endl;
	cout << "Low Seller : "   << name[loSalesProduct] << endl;
}

/************************************************************
 *                    posOfLargest                          *
 * Finds and returns the subscript of the array position    *
 * holding the largest value in the array passed to the     *
 * function.                                                *
 ************************************************************/
int posOfLargest(int array[])
{
	int indexOfLargest = 0;
   
	for (int pos = 1; pos < SIZE; pos++)
	{
		if (array[pos] > array[indexOfLargest])
			indexOfLargest = pos;
	}   
	return indexOfLargest;
}


/************************************************************
 *                    posOfSmallest                         *
 * Finds and returns the subscript of the array position    *
 * holding the smallest value in the array passed to the    *
 * function.                                                *
 ************************************************************/
int posOfSmallest(int array[])
{
	int indexOfSmallest = 0;
	
	for (int pos = 1; pos < SIZE; pos++)
	{
		if (array[pos] < array[indexOfSmallest])
			indexOfSmallest = pos;
	}		
	return indexOfSmallest;
}

/* SAMPLE RUN RESULTS

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
