// Chapter 9 - Programming Challenge 3, Lottery Winners Modification
// This program modifies Programming Challenge 2 to use a binary search 
// to see if an entered winning 5-digit lottery number matches the number
// on any of the player's tickets.
#include <iostream>
using namespace std;

bool searchList(const long [], int, long); // Function prototype

const int SIZE = 10;

int main()
{
	long ticket[SIZE] = { 13579,  26791,  26792,  33445,  55555,
		                  62483,  77777,  79422,  85647,  93121 };
	long winningNum;

	cout << "Please enter this week's 5-digit winning lottery number: ";
	cin  >> winningNum;

	// If searchList returns Boolean true, player has a winning ticket.
	// If searchList returns false, the ticket is not a winner.
	if (searchList(ticket, SIZE, winningNum))   
		cout << "You have a winning ticket.\n";
	else
		cout << "You did not win this week." << endl;

	return 0;
}

/*******************************************************************
 *                       searchList                                *
 * Called by: main                                                 *
 * Passed   : 3 arguments: an array of numbers, the size of that   *
 *            array, and the number to search for                  *
 * Purpose  : Determines if the number to search for is in the set *
 *            of stored numbers                                    *
 * Method   : Uses a binary search                                 *
 * Returns  : true (if the number is found) or false (if not found)*
 *******************************************************************/
bool searchList(const long list[], int numElems, long value)
{
	bool found = false;

	int first = 0,
		last = numElems - 1,
		middle;

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
	
		if (list[middle] == value)
			found = true;
		else if (list[middle] > value)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return found;
}

/* SAMPLE RESULTS RUN 1

Please enter this week's 5-digit winning lottery number: 56988
You did not win this week.

   SAMPLE RESULTS RUN 2

Please enter this week's 5-digit winning lottery number: 33445
You have a winning ticket.
*/
