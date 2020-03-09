// Chapter 4 - Programming Challenge 15, February Days
// Given a year, this program reports how many days February has that year.
#include <iostream>
using namespace std;

int main()
{
	int year,
		FebDays = 28;

	bool leapYear = false;

	// Explain the program
	cout << "If you give me a year I can tell you how many days \n"
		 << "February has that year \n";

	// Get the year
	cout << "Enter a year using all 4 digits: ";
	cin >> year;

	// Is this a leap year?
	if (year % 100 == 0 && year % 400 == 0)
		leapYear = true;
	else if (year % 100 != 0 && year % 4 == 0)
		leapYear = true;
	
	// Display the results
	if (leapYear)    // Same as if (leapYear == true)
		FebDays = 29;
	cout << "In " << year << " February has " << FebDays << " days.\n";

	return 0;
}