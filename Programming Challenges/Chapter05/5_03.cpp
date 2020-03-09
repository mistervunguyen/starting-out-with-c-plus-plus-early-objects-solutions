// Chapter 5 - Programming Challenge 3, Distance Traveled
// This program calculates and displays how many miles a 
// vehicle has traveled after each hour of its journey. 
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double speed,            // Speed of the vehicle in mph
		   totalHours;       // Number of hours the vehicle travels

	// Input and validate the vehicle's speed
	cout << "What is the speed of the vehicle in mph? ";
	cin  >> speed;
	while (speed < 0)
	{
		cout << "The speed cannot be less than zero. Re-enter speed in mph: ";
		cin  >> speed;
	}

	// Input and validate hours traveled
	cout << "How many hours has it traveled? ";
	cin  >> totalHours;
	while (totalHours < 1)	
	{
		cout << "Travel time must be 1 hour or greater. Re-enter hours traveled: ";
		cin  >> totalHours;
	}
	
	// Perform calculations and display a table of 
	// cumulative distance travelled at the end of each hour
	cout << "\nHour   Miles Traveled\n";
	cout << "----------------------------\n";
	for (int hour = 1; hour <= totalHours; hour++)
		cout << setw(4) << hour << setw(11) << (speed * hour) << endl;

	return 0;
}
