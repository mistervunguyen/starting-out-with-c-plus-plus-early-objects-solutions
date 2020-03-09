// Chapter 5 - Programming Challenge 10, Calories Burned
// This program creates a table displaying the number of calories 
// burned running on a treadmill for various numbers of minutes.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const double CAL_PER_MIN = 3.9;  // Number of calories burned per min. 
	                                 // running on a treadmill
	// Display table heading
	cout << "          Calories \n"
		 << "Minutes    Burned  \n"
		 << "-------------------\n";

	// Create and display the table
	cout << fixed << setprecision(1);
	for (int min = 5; min <= 30; min += 5)
		cout << setw(5) << min << setw(11) << min * CAL_PER_MIN << endl;

	return 0;
}

/* CORRECT RESULTS

          Calories
Minutes    Burned
-------------------
    5       19.5
   10       39.0
   15       58.5
   20       78.0
   25       97.5
   30      117.0
*/

