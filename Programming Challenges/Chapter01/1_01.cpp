// Chapter 1 - Programming Challenge 1, Candy Bar Sales
// This program calculates earnings from candy bar sales.
// Note: Because students are creating this program by modifying Program 1-1 
// and have not yet learned about different data types, all variables are 
// declared as doubles, as in Program 1-1.
#include <iostream>
using namespace std;

int main()
{
	double numSold, earningsPerBar, totalEarnings;

	// Get the number of candy bars sold.
	cout << "How many candy bars were sold? ";
	cin  >> numSold;

	// Get the amount earned per bar sold.
	cout << "How much is earned for each bar sold? ";
	cin  >> earningsPerBar;

	// Calculate the total earnings.
	totalEarnings = numSold * earningsPerBar;

	// Display the total earnings.
	cout << "You have earned $" << totalEarnings << endl;
	return 0;
}

/* SAMPLE RUN RESULTS
How many candy bars were sold? 210
How much is earned for each bar sold? .15
You have earned $31.5
*/
