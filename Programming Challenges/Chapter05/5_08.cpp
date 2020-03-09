// Chapter 5 - Programming Challenge 8, Pennies for Pay
// This program calculates an employee's total monthly pay if the daily 
// pay amount is doubled each day worked, starting with 1 penny on day 1.
// It uses a while loop to validate the user input for number of days
// worked, and a for loop to calculate the pay. Students may choose to
// use a while loop for both tasks.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int    daysWorked;       // Number of days worked during the month
	double dailyPay = 0.01;  // Current day's pay (starts with .01 on day 1)
	double monthPay = 0.0;   // Accumulator for total month's pay 

	// Get and validate days worked
	cout << "How many days did the employee work this month? ";
	cin  >> daysWorked;
	while (daysWorked < 1 || daysWorked > 31)
	{
		cout << "The number of days must be between 1 and 31.\n";
		cout << "Please re-enter days worked. ";
		cin >> daysWorked;
	}

	//Display table heading
	cout << "\nDay            Pay\n";
	cout << "------------------\n";
	
	// Create and display the table
	cout << fixed << showpoint << setprecision(2);

	for (int day = 1; day <= daysWorked; day++) 
	{	// Display the day's pay
		cout << setw(2) << day << "     " << setw(11) << dailyPay << endl;
		// Add the day's pay to the monthly total
		monthPay += dailyPay;
		// Calculate the daily pay for the following day
		dailyPay *= 2;
	}
	// Display the total pay for the month			
	cout << "------------------\n";
	cout << "Total" << " $" << setw(11) << monthPay << endl;
	
	return 0;
}

/* SAMPLE RUN RESULTS

Day            Pay
------------------
 1            0.01
 2            0.02
 3            0.04
 4            0.08
 5            0.16
 6            0.32
 8            1.28
 9            2.56
10            5.12
11           10.24
12           20.48
13           40.96
14           81.92
15          163.84
16          327.68
17          655.36
18         1310.72
19         2621.44
20         5242.88
------------------
Total $   10485.75
*/
