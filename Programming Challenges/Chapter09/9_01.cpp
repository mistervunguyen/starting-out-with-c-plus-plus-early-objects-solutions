// Chapter 9 - Programming Challenge 1, Charge Account Validation
// This program uses a linear search to match an entered account
// number to a set of stored valid account numbers.
#include <iostream>
using namespace std;

bool searchList(long [], int, long); // Function prototype

const int SIZE = 18;
int main()
{
	long accounts[SIZE] = 
			{	5658845,  4520125,  7895122,  8777541,  8451277,  1302850,
				8080152,  4562555,  5552012,  5050552,  7825877,  1250255,
				1005231,  6545231,  3852085,  7576651,  7881200,  4581002, };
	long acctNum;

	cout << "Please enter a 7-digit account number: ";
	cin  >> acctNum;

	// If searchList returns Boolean true, it is a valid number.
	// If searchList returns false, it is NOT valid.
	if (searchList(accounts, SIZE, acctNum))   
		cout << "The number you entered is valid.\n";
	else
		cout << "The number you entered is invalid." << endl;

	return 0;
}

/*******************************************************************
 *                       searchList                                *
 * Called by: main                                                 *
 * Passed   : 3 arguments: an array of valid numbers, the size     *
 *            of that array, and the acct. number to search for    *
 * Purpose  : Determines if the acct. number is in the set of      *
 *            valid numbers                                        *
 * Method   : Uses a linear search                                 *
 * Returns  : true (if the number is found) or false (if not found)*
 *******************************************************************/
bool searchList(long list[], int numElems, long value)
{
	bool found = false;

	for (int count = 0; count < numElems && !found; count++)
	{
		if (list[count] == value)
			found = true;
	}
	return found;
}

/* SAMPLE RESULTS RUN 1

Please enter a 7-digit account number: 5552010
The number you entered is invalid.

   SAMPLE RESULTS RUN 2

 Please enter a 7-digit account number: 5552012
The number you entered is valid.  
*/
