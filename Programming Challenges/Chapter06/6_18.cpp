// Chapter 6 - Programming Challenge 18, Transient Population
// This program enhances Programming Challenge 17 to calculate projected
// future population in a region, considering migration into and out of 
// the region as well as current population, and birth and death rates.
// Note: Students should be shown the cmath library round() function 
// to round each new population figure to the nearest whole number.

#include <iostream>
#include <iomanip>
#include <cmath>         // Needed to use the round() rounding function
using namespace std;

long population(long, int, int, double, double);

int main()
{
	long startPop,        // Population at the beginning of a year
		 newPop;          // Projected population at the end of that year

	double birthRate,     // Birth and death rates. These are the number
		   deathRate;     // per 1000 people, expressed as a decimal. 

	int moveIn,          // Number of individuals who move into the area
		moveOut,         // Number of individuals who move out of the area
        numYears;        // Number of years to track population changes

	// Input and validate starting population size
	cout << "This program calculates population change.\n\n";
	cout << "Starting population size: ";
	cin  >> startPop;
	while (startPop < 2)
	{
		cout << "Starting population must be 2 or more.  Please re-enter: ";
		cin  >> startPop; 
	}

	// Input and validate number of individuals moving in
	cout << "Number of people who typically move into this region in a year: ";
	cin  >> moveIn;
	while (moveIn < 0)
	{
		cout << "Number of people cannot be less than 0. Please re-enter: ";
		cin  >> moveIn; 
	}

	// Input and validate number of individuals moving out
	cout << "Number of people who typically move out of this region in a year: ";
	cin  >> moveOut;
	while (moveOut < 0)
	{
		cout << "Number of people cannot be less than 0. Please re-enter: ";
		cin  >> moveOut; 
	}
	
	// Input and validate annual birth rate
	cout << "Enter the annual birth rate (as % of current population): ";
	cin  >> birthRate;	
	while (birthRate < 0)	
	{	cout << "Birth rate percent cannot be negative.  Please re-enter: ";
		cin  >> birthRate;
	}
	birthRate = birthRate / 100;     // convert from % to decimal
	
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
	cout << "\nStarting population: " << startPop << "\n";
	cout << "Projected population at the end of \n\n";
	for (int year = 1; year <= numYears; year++)
	{	
		newPop = population(startPop, moveIn, moveOut, birthRate, deathRate);
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
 *                      the number of individuals who move in and  *
 *                      out of the region annually, and the birth  *
 *                      and the death rate.                        *
 *******************************************************************/
long population(long pop, int moveIn, int moveOut,
                double birthRate, double deathRate)
{
	long newPop = static_cast<long>
                 (round( (pop + moveIn - moveOut) * (1 + birthRate) * (1 - deathRate) ));
	
	return newPop;

}// end of function population

/* SAMPLE RUN RESULT

This program calculates population change.

Starting population size: 122500
Number of people who typically move into this region in a year: 2500
Number of people who typically move out of this region in a year: 350
Enter the annual birth rate (as % of current population): 7.2
Enter the annual death rate (as % of current population): 3.6
For how many years do you wish to view population changes? 5

Starting population: 122500
Projected population at the end of

year 1:  128814
year 2:  135339
year 3:  142082
year 4:  149051
year 5:  156252
*/
