// Chapter 6 - Programming Challenge 5, Winning Division
// Given quarterly sales figures for 4 divisions of a company, this program
// finds the division with the highest sales. It uses one function to get 
// and return the sales for a division and another to determine and display
// the name and sales of the highest selling division.
#include <iostream>
#include <iomanip>
#include <string>	
using namespace std;

// Function prototypes
double getSales (string);
void findHighest(double, double, double, double);

int main()
{
	// Quarterly sales figures for each division
	double salesNE, salesSE, salesNW, salesSW;

	// Call the getSales function once for each division
	// to get and return its quarterly sales figure
	salesNE = getSales("Northeast");	
	salesSE = getSales("Southeast");	
	salesNW = getSales("Northwest");	
	salesSW = getSales("Southwest");	

	// Call the findHighest function to determine and print the 
	// name and sales total of the division with the highest sales 
	findHighest(salesNE, salesSE, salesNW, salesSW);

	return 0;

}// end of main function

/********************************************************************
 *                           getSales                               *
 * This function is called by main to input, validate, and return   *
 * the sales for the division whose name was passed to the function.*
 ********************************************************************/
double getSales(string divName)
{
	double sales;

	cout << "Enter the quarterly sales for the " << divName 
		 << " division: ";
	cin  >> sales;

	while (sales < 0.0)	                
	{	cout << "Sales figures cannot be negative. Please re-enter.\n";
		cout << "Enter the quarterly sales for the " << divName 
		     << " division: ";
		cin  >> sales;
	} 
	return sales;
}// end of function getSales

/**********************************************************************
 *                         findHighest                                *
 * This function is called by main and passed, as arguments, the 4    *
 * divisional sales figures. It displays the name of the division     *
 * with the highest sales. Note -- If two or more divisions are tied, *
 * only the first of the two names is displayed.                      *
 **********************************************************************/
void findHighest(double nEast, double sEast, double nWest, double sWest)
{
	string divName = "Northeast";
	double  highest = nEast;

	if (sEast > highest)
	{	highest = sEast;
		divName = "Southeast";
	}
	if (nWest > highest)
	{	highest = nWest;
		divName = "Northwest";
	}
	if (sWest > highest)
	{	highest = sWest;
		divName = "Southwest";
	}
	cout << fixed << showpoint << setprecision(2);
	cout << "\nThe " << divName
		 << " division had the highest sales this quarter.\n";
	cout << "Their sales were $" << highest << endl;

}// end of function findHighest

/* SAMPLE RUN RESULTS

Enter the quarterly sales for the Northeast division: 124900
Enter the quarterly sales for the Southeast division: 67250
Enter the quarterly sales for the Northwest division: 88215
Enter the quarterly sales for the Southwest division: 108030

The Northeast division had the highest sales this quarter.
Their sales were $124900.00
*/
