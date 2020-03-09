// Chapter 3 - Programming Challenge 9, Vacation Days
// This program converts an entered number of 
// vacation days to hours, minutes, and seconds.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int numDays,       // vacation days
		numHrs,        // equivalent vacation hours
		numMin,        // equivalent vacation minutes
		numSec;        // equivalent vacation seconds

	// Prompt user for the number of vacation days
	cout << "How many days do you plan to spend on your next vacation? ";
	cin >> numDays;

	// Compute how long this is in hours, in minutes, and in seconds
	numHrs = numDays * 24;
	numMin = numHrs * 60;
	numSec = numMin * 60;

	// Display results 
	cout << "\nThat is equivalent to \n"
		<< setw(7) << numHrs << " hours \n"
		<< setw(7) << numMin << " minutes \n"
		<< setw(7) << numSec << " seconds \n";
  	   
   return 0;
}

/* SAMPLE RUN RESULTS

How many days do you plan to spend on your next vacation? 7

That is equivalent to
   168 hours
 10080 minutes
604800 seconds
*/
