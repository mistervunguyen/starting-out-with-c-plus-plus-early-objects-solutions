// Chapter 2 - Programming Challenge 13, Pay Period Gross Pay
// This program computes both bi-monthly and bi-weekly gross pay 
// for a salaried employee. Because students have not yet learned 
// to format output, dollar amounts will not be displayed rounded 
// to two decimal places.
#include <iostream>
using namespace std;

int main()
{
	double annualSalary = 39000.0,   // Employee's annual gross salary
	       biMonthlyPay,             // Pay period gross with 24 paychecks per year
		   biWeeklyPay;              // Pay period gross with 26 paychecks per year
		   
	// Compute Pay period gross for each pay plan
	biMonthlyPay = annualSalary / 24;
	biWeeklyPay  = annualSalary / 26;

	// Display results
	cout << "Annual gross salary               $"  << annualSalary << endl;
	cout << "Gross pay per bi-monthly paycheck $ " << biMonthlyPay << endl;
	cout << "Gross pay per bi-weekly  paycheck $ " << biWeeklyPay  << endl;
	
	return 0;
}

/* CORRECT RESULTS
Annual gross salary               $39000
Gross pay per bi-monthly paycheck $ 1625
Gross pay per bi-weekly  paycheck $ 1500
*/
