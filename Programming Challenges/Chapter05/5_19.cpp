// Chapter 5 - Programming Challenge 19, Hotel Suites ccupancy
// This program calculates the occupancy rate for a hotel's suites.
// These are located on floors 10-16. There is no 13th floor.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const int
		SUITES_PER_FLOOR = 20,   // Number of suites per floor
		MIN_FLOOR = 10,          // Lowest floor of suite units
		MAX_FLOOR = 16,          // Highest floor of suite units

		TOTAL_SUITES = (MAX_FLOOR - MIN_FLOOR) * SUITES_PER_FLOOR;

	int occupied,                // Number of occupied suites on the floor
		totalOccupied = 0;       // Total number of occupied suites

	double occupancyRate;        // % of the suites that are occupied

	// Get and validate occupancy information for each floor
	cout << "Enter the number of occupied suites (0 - " << SUITES_PER_FLOOR  
		 << ") on each of the following floors.\n\n";

	for (int floor = MIN_FLOOR; floor <= MAX_FLOOR; floor++)
	{
		if (floor == 13)
     		continue;		  // Skip thirteenth floor
		
		cout << "Floor " << floor << ": "; 
		cin  >> occupied;										
		while (occupied < 0 || occupied > SUITES_PER_FLOOR)
		{
			cout << "\nThe number of occupied suites must be between 0 and " <<  SUITES_PER_FLOOR << endl;
			cout << "Re-enter the number of occupied suites on floor " << floor << ": ";
			cin  >> occupied;
		}
        // Add occupied suites on this floor to the total
		totalOccupied += occupied;
	}
	
	// Compute occupancy rate in % form
	occupancyRate = 100.0 * totalOccupied / TOTAL_SUITES;	

	// Display results
	cout << fixed << showpoint << setprecision(1);
	cout << "\nThe hotel has a total of " << TOTAL_SUITES << " suites.\n";
	cout << totalOccupied << " are currently occupied.\n";
	cout << "This is an occupancy rate of " << occupancyRate << "% \n";

	return 0;
}

/* SAMPLE RUN RESULTS

Enter the number of occupied suites (0 - 20) on each of the following floors.

Floor 10: 14
Floor 11: 12
Floor 12: 16
Floor 14: 18
Floor 15: 19
Floor 16: 17

The hotel has a total of 120 suites.
96 are currently occupied.
This is an occupancy rate of 80.0%
*/
