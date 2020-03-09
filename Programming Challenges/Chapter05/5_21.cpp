// Chapter 5 - Programming Challenge 21, Diamond Display
// This program uses nested loops to display a diamond.
#include <iostream>
using namespace std;

int main()
{
	const int NUM_ROWS = 7,           // Number of rows
		      MAX_PLUS = 7;           // Maxiumum number of plus signs on a row

	int numSpaces,                    // Number of leading blank spaces on a row
		numPluses;                    // Number of plus signs on a row
	
	for (int row = 1; row <= NUM_ROWS; row++)
	{
		// Compute the number of pluses and number of leading spaces for this row
		numPluses = 2 * row - 1;      // This works for rows 1 thru 4

		if (numPluses > MAX_PLUS)     // This adjusts rows 5 thru 7
			numPluses = 14 - numPluses;

		numSpaces = (MAX_PLUS - numPluses) / 2; 

		// Inner loop to print the leading spaces for this row
		for (int space = 1; space <= numSpaces; space++)
			cout << ' ';

		// Inner loop to print the pluses for this row
		for (int plus = 1; plus <= numPluses; plus++)
			cout << '+';

		// Go to the next row
		cout << endl;
	}
	return 0;
}
