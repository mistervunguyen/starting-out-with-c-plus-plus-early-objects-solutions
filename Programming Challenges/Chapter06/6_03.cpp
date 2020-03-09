// Chapter 6 - Programming Challenge 3, Falling Distance
// This program uses a function that computes and returns 
// the distance an object falls due to gravity in a specific 
// number of seconds. The information is displayed in a table.
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototype
double fallingDistance(int);

int main()
{
	// Display table heading
	cout << "           Distance \n"
		 << "  Seconds  (meters) \n"
		 << "---------------------\n";

	// Create and display the table
	cout << fixed << setprecision(1);

	for (int sec = 1; sec <= 10; sec++)
		cout << setw(6) << sec << setw(11) << fallingDistance(sec) << endl;
   
	return 0;
	
}// end of main function

/*************************************************************
 *                     fallingDistance                       *
 * When passed a time in seconds (t), this function computes *
 * and returns the distance in meters an object falls due to *
 * gravity during that time period.                          *
 *************************************************************/
double fallingDistance(int t)
{
	const double G = 9.8;        // Gravitational constant
	double distance = 0.5 * G * t * t;

	return distance;
	
}// end of fallingDistance function

/* CORRECT RESULTS

           Distance
  Seconds  (meters)
---------------------
     1        4.9
	 2       19.6
	 3       44.1
	 4       78.4
	 5      122.5
	 6      176.4
	 7      240.1
	 8      313.6
	 9      396.9
    10      490.0
*/