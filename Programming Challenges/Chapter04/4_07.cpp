// Chapter 4 - Programming Challenge 7, Time Calculator
// This program converts seconds to days, hours, or minutes, 
// whichever is most appropriate.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{ 
	const int SEC_PER_DAY = 86400,    // Number of seconds in a day
		      SEC_PER_HOUR = 3600,    // Number of seconds in an hour
			  SEC_PER_MINUTE = 60;    // Number of seconds in a minute

	double seconds;                   // Length of time measured in seconds

	// Input the number of seconds
	cout << "This program will convert seconds to days, hours, or minutes. \n\n";
	cout << "Enter the number of seconds (60 or more): ";
	cin  >> seconds;

	// Set the output format
	cout << fixed << setprecision(2);

	// Determine and print the corresponding number of days, hours,
	// or minutes depending on the number of seconds entered
	if (seconds >= SEC_PER_DAY)
		cout << "This equals " << seconds / SEC_PER_DAY << " days. \n";
	else if (seconds >= SEC_PER_HOUR)
		cout << "This equals " << seconds / SEC_PER_HOUR << " hours. \n";
	else if (seconds >= SEC_PER_MINUTE)
		cout << "This equals " << seconds / SEC_PER_MINUTE << " minutes. \n";
	else
		cout << "This is less than one minute. \n";
   
	return 0;
}

/* SAMPLE RUN RESULTS - RUN 1
This program will convert seconds to days, hours, or minutes.

Enter the number of seconds (60 or more): 95000
This equals 1.10 days.

SAMPLE RUN RESULTS - RUN 2
This program will convert seconds to days, hours, or minutes.

Enter the number of seconds (60 or more): 3000
This equals 50.00 minutes.

SAMPLE RUN RESULTS - RUN 3
This program will convert seconds to days, hours, or minutes.

Enter the number of seconds (60 or more): 45
This is less than one minute.
*/