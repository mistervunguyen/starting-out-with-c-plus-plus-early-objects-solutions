// Chapter 3 - Programming Challenge 5, Batting Avarage
// This program calculates a baseball player's batting average.
// It uses a type cast.
#include <iostream>
#include <string>         // Needed by most compilers to use strings
#include <iomanip>        // Needed for formatted output 
using namespace std;

int main()
{
	int atBats,           // Number of times the player was at bat
		hits;             // Number of hits the player got
	double battingAvg;    // The player's batting average

	cout << "This program computes a baseball player's batting average. \n\n";

	// Prompt user for times at bat and number of hits
	cout << "How many times was the player at bat? ";
	cin  >> atBats;

	cout << "How many hits did the player get? ";
	cin  >> hits;

	// Compute and display the batting average
	battingAvg = static_cast<double>(hits) / atBats;

	cout << fixed << showpoint << setprecision(4);
	cout << "The player's batting average is " << battingAvg << endl;

    return 0;
}

/* SAMPLE RUN RESULTS

This program computes a baseball player's batting average.

How many times was the player at bat? 84
How many hits did the player get? 18
The player's batting average is 0.2143
*/
