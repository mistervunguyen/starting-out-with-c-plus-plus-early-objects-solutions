// Chapter 5 - Programming Challenge 17, Population
// This program predicts future population based on 
// starting size and growth rate (with 0% death rate).
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	long double organisms;    // Number of organisms on any given day
	double increase;          // Daily % increase  
	int numDays;             // Number of days in the trial
   
	// Input and validate starting number of organisms
	cout << "Enter the starting number of organisms (2 or more): ";
	cin  >> organisms;
	while (organisms < 2)	   
	{	cout << "Starting number must be at least 2. Please re-enter: ";
		cin  >> organisms;
	}

	// Input and validate daily population increase
	cout << "\nEnter the average daily population increase \n"
		  << "as a percentage of current population (e.g. 3.5): ";
	cin  >> increase;	
	while (increase < 0)	
	{	cout << "Increase percent cannot be negative.  Please re-enter: ";
		cin  >> increase;
	}
	increase = increase / 100;     // Convert from % to decimal

	// Input and validate number of days the organisms will multiply
	cout << "\nEnter the number of days the organisms will be "
		 << "left to multiply: ";
	cin >> numDays;	
	while (numDays < 1)	
	{	cout << "Number of days must be one or more.  Please re-enter: ";
		cin  >> numDays;
	}
	
	// Calculate and display results
	cout << fixed << noshowpoint << setprecision(0) << endl << endl;
	for (int day = 1; day <= numDays; day++)
	{		
		organisms += organisms * increase;

		if (organisms > 10000000)	// change output to E notation 
		{                           // after 10000000
			cout << scientific;
		}		
		cout << "Population after day " << setw(2) << day << ": " 
			 << setw(9) << organisms << endl;
	}
	return 0;
}

/* SAMPLE RUN RESULTS

Enter the starting number of organisms (2 or more): 10

Enter the average daily population increase
as a percentage of current population (e.g. 3.5): 25

Enter the number of days the organisms will be left to multiply: 15

Population after day  1:        13
Population after day  2:        16
Population after day  3:        20
Population after day  4:        24
Population after day  5:        31
Population after day  6:        38
Population after day  7:        48
Population after day  8:        60
Population after day  9:        75
Population after day 10:        93
Population after day 11:       116
Population after day 12:       146
Population after day 13:       182
Population after day 14:       227
Population after day 15:       284
*/
