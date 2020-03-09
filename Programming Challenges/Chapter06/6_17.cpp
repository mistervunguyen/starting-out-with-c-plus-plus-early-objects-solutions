// Chapter 6 - Programming Challenge 17, Population
// This program calculates projected future population based
// on current population and birth and death rates.
// Note: Students should be shown the cmath library round() function
// to round a floating-point number to the nearest whole number.

#include <iostream>
#include <iomanip>
#include <cmath>         // Needed to use the round() rounding function
using namespace std;

long population(long, double, double);

int main()
{
	long startPop,        // Population at the beginning of a year
		 newPop;          // Projected population at the end of that year

	double birthRate,     // Birth and death rates. These are the number
		   deathRate;     // per 1000 people, expressed as a decimal. 

	int numYears;         // Number of years to track population changes
        
	// Input and validate starting population size
	cout << "This program calculates population change.\n";
	cout << "Enter the starting population size: ";
	cin  >> startPop;
	while (startPop < 2)
	{
		cout << "Starting population must be 2 or more.  Please re-enter: ";
		cin  >> startPop; 
	}
	
	// Input and validate annual birth rate
	cout << "Enter the annual birth rate (as % of current population): ";
	cin  >> birthRate;	
	while (birthRate < 0)	
	{
		cout << "Birth rate percent cannot be negative.  Please re-enter: ";
		cin  >> birthRate;
	}
	birthRate = birthRate / 100;     // Convert from % to decimal
	
	// Input and validate annual death rate
	cout << "Enter the annual death rate (as % of current population): ";
	cin  >> deathRate;	
	while (deathRate < 0)	
	{	cout << "Death rate percent cannot be negative.  Please re-enter: ";
		cin  >> deathRate;
	}
	deathRate = deathRate / 100;     // convert from % to decimal

	// Input and validate number of years to project population figures
	cout << "For how many years do you wish to view population changes? ";
	cin  >> numYears;
	while (numYears < 1)
	{	cout << "Years must be one or more. Please re-enter: ";
		cin  >> numYears;
	}

	// Calculate and display yearly population projections
	cout << "\nStarting population: " << startPop << "\n\n";
	cout << "Projected population at the end of \n\n";
	
	for (int year = 1; year <= numYears; year++)
	{	
		newPop = population(startPop, birthRate, deathRate);
		cout << "   year " << year << ": " << setw(7) << newPop << endl;
		startPop = newPop;    // Set starting pop. for next year's calculation
	}
	return 0;

}// end of main function

/*******************************************************************
 *                         population                              *
 *  This function computes and returns the projected new population*
 *  at the end of a year, rounded to the nearest whole number.     *
 *                                                                 *
 *  Called by: main                                                *
 *  Arguments received: Population at the beginning of the year,   *
 *                      the birth rate, and the death rate.        *
 ******************************************************************/
long population(long pop, double birthRate, double deathRate)
{  
   long newPop = static_cast<long>
                 (round( pop * (1 + birthRate) * (1 - deathRate) ));
   return newPop;

}// end of population function

/* SAMPLE RUN RESULTS

This program calculates population change.
Enter the starting population size: 20919
Enter the annual birth rate (as % of current population): 8.0
Enter the annual death rate (as % of current population): 2.8
For how many years do you wish to view population changes? 5

Starting population: 20919

Projected population at the end of

year 1:   21960
year 2:   23053
year 3:   24200
year 4:   25404
year 5:   26668
*/
