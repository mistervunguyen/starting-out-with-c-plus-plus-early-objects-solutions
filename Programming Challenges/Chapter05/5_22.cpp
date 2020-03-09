// Chapter 5 - Programming Challenge 22, Triangle Display
// This program uses nested loops to display a triangle.
#include <iostream>
using namespace std;

int main()
{
	const int NUM_ROWS = 7,           // Number of rows
		      MAX_PLUS = 7;           // Maxiumum number of plus signs on a row

	int numPluses;                    // Number of plus signs on a row
	
	for (int row = 1; row <= NUM_ROWS; row++)
	{
		// Compute the number of pluses for this row
		numPluses = 2 * row - 1;      // This works for rows 1 thru 4

		if (numPluses > MAX_PLUS)     // This adjusts rows 5 thru 7
			numPluses = 14 - numPluses;

		// Inner loop to print the pluses for this row
		for (int plus = 1; plus <= numPluses; plus++)
			cout << '+';

		// Go to the next row
		cout << endl;
	}
	return 0;
}
