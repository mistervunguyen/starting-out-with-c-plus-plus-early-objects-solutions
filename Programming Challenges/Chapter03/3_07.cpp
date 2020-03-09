// Chapter 3 - Programming Challenge 7, Average Rainfall 
//	This program calculates the average rainfall for a 3-month period.
#include <iostream>
#include <iomanip> 
#include <string>         // Needed by most compilers to use strings
using namespace std;

int main()
{
	const int NUM_MONTHS = 3;

	string month1, month2, month3;  // Month names
	
	double rain1, rain2, rain3,     // Amount of rainfall (in inches) each month
		   avgRain;                 // Average rainfall for the 3-month period

	// Prompt user for month names and rainfall amounts
	cout << "This program will compute the average rainfall for a "
		 << NUM_MONTHS << " month period.\n";
        
	cout << "For each month, enter the month name followed by a space \n"
		 << "and then the amount of rain (in inches) that fell that month.\n\n";
	  
	cout << "Month 1: ";
	cin  >> month1 >> rain1;

	cout << "Month 2: ";
	cin  >> month2 >> rain2;

	cout << "Month 3: ";
	cin  >> month3 >> rain3;

	// Calculate the average rainfall
	avgRain = (rain1 + rain2 + rain3) / NUM_MONTHS;

	// Display the results 
	cout << "\nThe average rainfall for ";
	cout << month1	<< ", " << month2 << ", and " << month3 << " was ";
	cout << fixed << showpoint << setprecision(2);
	cout << avgRain  << " inches.\n";
   
   return 0;
}

/* SAMPLE RUN RESULTS

This program will compute the average rainfall for a 3 month period.
For each month, enter the month name followed by a space
and then the amount of rain (in inches) that fell that month.

Month 1: August 1.8
Month 2: September 2.2
Month 3: October 2.4

The average rainfall for August, September, and October was 2.13 inches.
*/
