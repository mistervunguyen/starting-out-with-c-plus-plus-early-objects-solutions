// Chapter 6 - Programming Challenge 11, Present Value
// Given an annual interest rate and a period of time (in years),
// this program calculates how much money must be deposited now 
// to have a specified value at the end of the time period.
#include <iostream>
#include <iomanip>
#include <cmath>                  // Needed to use the pow function
using namespace std;

// Function prototype
double presentValue(double f, double r, double n);

int main()
{
	double futureValue,          // Dollar amount wanted in the future
		   interestRate,         // annual interest rate (in .xxx form)
		   years;                // Number of years in the period

	char   doAgain;              // User entered character to loop again or quit
	
	cout << fixed << showpoint << setprecision(2);
	
	cout << "This program computes the amount of money that must be saved\n"
		 << "today in order to have a desired amount at the end of a \n"
		 << "specified number of years. \n";

	do
	{	
		cout << "\nFuture value desired: $";
		cin  >> futureValue;

		cout << "Annual interest rate:  ";
		cin  >> interestRate;

		cout << "Number of years     :  ";
		cin  >> years;

		cout << "\nAmount you must deposit now: $" 
			 << presentValue(futureValue, interestRate, years);

		cout << "\n\nPeform another calculation (Y/N)? ";
		cin  >> doAgain;
		
	} while (doAgain == 'Y' || doAgain == 'y');

	return 0;
}// end of main function


/**********************************************************************
 *                            presentValue                            *
 * This function has parameters to accept a desired future dollar     *
 * amount (f), an annual interest rate (r), and a number of years (n).* 
 * It uses these values to compute and return how many dollars must   *
 * be deposited today to have that value at the end of the specified  *
 * number of years.                                                   *
 **********************************************************************/
double presentValue(double f, double r, double n)
{
	double presentAmt = f / pow(1 + r, n);
	return presentAmt;
	
}// end of presentValue function

/* SAMPLE RUN RESULTS

This program computes the amount of money that must be saved
today in order to have a desired amount at the end of a
specified number of years.

Future value desired: $10000
Annual interest rate:  .03
Number of years     :  10

Amount you must deposit now: $7440.94

Peform another calculation (Y/N)? n
*/
