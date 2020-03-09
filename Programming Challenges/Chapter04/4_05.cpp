// Chapter 4 - Programming Challenge 5, Book Club Points
// This program awards points to book club members based on the number
// of books purchased in a month. An if / else if statement is used for
// the branching logic. A switch statement could also have been used.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int numBooks,           // Number of books purchased in a month
		points;             // Number of points earned

	// Input the number of books purchased
	cout << "How many books did you purchase through the book club this month? ";
	cin  >> numBooks;

	// Determine the number of points awarded
	if (numBooks <= 0)
		points = 0;
	else if (numBooks == 1)
		points = 5;
	else if (numBooks == 2)
		points = 15;
	else if (numBooks == 3)
		points = 30;
	else // numBooks must be 4 or more
		points = 50;

	// Display the result
	cout << "You earned " << points << " points this month. \n";

	return 0;
}

/* SAMPLE RESULTS - RUN 1
How many books did you purchase through the book club this month? 3
You earned 30 points this month.

SAMPLE RESULTS - RUN 2
How many books did you purchase through the book club this month? 7
You earned 50 points this month.
*/
