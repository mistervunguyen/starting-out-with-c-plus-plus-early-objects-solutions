// Chapter 6 - Programming Challenge 12, Future Value
// Given an initial deposit, an annual interest rate and a 
// number of months, this program calculates how much money
// will be in the account at the end of those months.

// THIS NEW PROGRAM MUST BE REWRITTEN TO DO WHAT IS REQUESTED

#include <iostream>
#include <iomanip>
#include <cmath>             // Needed to use the pow function
using namespace std;

// Function prototype
double futureValue(double p, double i, double t);

int main()
{
	double amtDeposited,  // Deposit amount (also called present value)
		annualIntRate,    // annual interest rate (in .xxx form)
		moIntRate;        // monthly interest rate (1/12 of annual rate)

	int months;           // Number of months the money grows

	char   doAgain;       // User entered character to loop again or quit
	
	cout << fixed << showpoint << setprecision(2);
	
	cout << "This program computes the amount of you will have at the \n"
		 << "end of a specified number of months, based on the amount \n"
		 << "you deposit now and the annual interest rate. \n";
	do
	{	
		cout << "\nAmount you are depositing: $";
		cin  >> amtDeposited;

		cout << "Annual interest rate:  ";
		cin  >> annualIntRate;
		moIntRate = annualIntRate / 12;

		cout << "Number of months you will let the money grow: ";
		cin  >> months;

		cout << "\nAt the end of " << months << " months you will have $"
			<< futureValue(amtDeposited, moIntRate, months);
		
		cout << "\n\nPeform another calculation (Y/N)? ";
		cin  >> doAgain;
		
	} while (doAgain == 'Y' || doAgain == 'y');

	return 0;
}// end of main function

/****************************************************************************
 *                               futureValue                                *
 * This function has parameters to accept the dollar amount (present value) *
 * deposited in an account (p), the monthly interest rate (i), and the time *
 * in months (t) it will be left to grow. It uses these values to compute   *
 * and return the amount of money (future value) in the account at the end  *
 * of the specified period.                                                 *
 ****************************************************************************/
double futureValue(double p, double i, double t)
{
	double finalAmt = p * pow(1 + i, t);
	return finalAmt;
	
}// end of futureValue function

/* SAMPLE RUN RESULTS

This program computes the amount of you will have at the
end of a specified number of months, based on the amount
you deposit now and the annual interest rate.

Amount you are depositing: $5000
Annual interest rate:  .03
Number of months you will let the money grow: 120

At the end of 120 months you will have $6746.77

Peform another calculation (Y/N)? n
*/
