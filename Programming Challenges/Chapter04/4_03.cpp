// Chapter 4 - Programming Challenge 3, Magic Dates 
// This program identifies "magic" dates, where a date is magic if
// the month number times the day number equals the 2-digit year number.
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int month,     // Month in 1 or 2-digit form
		day,       // Day in 1 or 2-digit form
		year;      // Year in 2-digit form

	// Get the date month, day, and year of the date to be tested
	cout << "A date is \"magic\" if month X day = year. \n";
	cout << "Enter a date and I will tell you if it is magic. \n\n";

	cout << "month number: ";
	cin  >> month;
	if (month < 1 || month > 12)
		cout << "Invalid month number. Month must be between 1 and 12 \n";
	else
	{	cout << "day number  : ";
		cin >> day;
		if (day < 1 || day > 31)
			cout << "Invalid day. Day must be between 1 and 31 \n";
		else
		{
			cout << "2-digit year number: ";
			cin >> year;
			if (month * day == year)
				cout << "\nThis date is magic. "
				     << month << " X " << day << " = " << year << endl;
			else
				cout << "\nThis date is not magic. \n";
		}
	}
	return 0;
}

/* SAMPLE RUN RESULTS

A date is "magic" if month X day = year.
Enter a date and I will tell you if it is magic.

month number: 3
day number  : 6
2-digit year number: 18

This date is magic. 3 X 6 = 18
*/
