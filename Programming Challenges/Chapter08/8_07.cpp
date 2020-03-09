// Chapter 8 - Programming Challenge 7, Lottery
// This program uses two parallel arrays to store a 5-digit 
// user-entered lottery number and a 5-digit randomly generated
// winning lottery number. It then compares the corresponding
// digits of the two arrays and reports how many digits match.
#include <iostream>
#include <string>
#include <cstdlib>       // Needed to generate random numbers
#include <ctime>         // Needed to use the time function to seed the
                         // random number generator
using namespace std;

const int SIZE = 5;

// Functgion prototypes
bool getPlayerNumber(int[]);
void getWinningNumber(int[]);
int countMatches(int[], int[]);
string getNumberString(int[]);

int main()
{
	int winningDigits[SIZE],
		player[SIZE];

	int numMatches = 0;

	bool numberOK;

	// Call functions to get the user's lottery number and
	// to randomly generate the winning lottery number

	cout << "Enter the 5 digits of your lottery number, separated by blanks: ";
	numberOK = getPlayerNumber(player);
	while (!numberOK)
	{
		cout << "\nOnly digits between 0 and 9 are allowed.\n";
		cout << "Re-enter the 5 digits of your lottery number, separated by blanks: ";
		numberOK = getPlayerNumber(player);
	}

	getWinningNumber(winningDigits);

	// Call a function to count the matching digits
	numMatches = countMatches(player, winningDigits);

	// Report the results
	cout << "\nWinning number: " << getNumberString(winningDigits);
	cout << "\nYour number   : " << getNumberString(player);
	cout << "\n\nYou have " << numMatches << " matching digit(s).\n";

	return 0;
}

/*************************************************
 *                getPlayerNumber                *
 * This function reads in the digits of the      *
 * player's lottery number and stores them in    *
 * the array that is passed to it. If all the    *
 * digits are valid (i.e. 0-9) true is returned. *
 * If not, false is returned.                    *
 ************************************************/
bool getPlayerNumber(int array[])
{
	bool digitsOK = true; 

	for (int digit = 0; digit < SIZE; digit++)
	{
		cin >> array[digit];
		if (array[digit] < 0 || array[digit] > 9)
			digitsOK = false;
	}
	return digitsOK;
}

/*************************************************
 *               getWinningNumber                *
 * This function randomly generates the digits   *
 * of the winning lottery number and stores them *
 * in the array that is passed to it.            *
 ************************************************/
void getWinningNumber(int array[])
{
	unsigned seed = time(0);
	srand(seed);

	for (int digit = 0; digit < SIZE; digit++)
	{
		// Generate and store a random number between 0 and 9
		array[digit] = rand() % 10;    
	}
}

/**************************************************
 *                  countMatches                  *
 * This function counts the number of digits that *
 * match in the two arrays passed to it.          *
 **************************************************/
int countMatches(int array1[], int array2[])
{
	int numMatches = 0;

	for (int digit = 0; digit < SIZE; digit++)
	{
		if (array1[digit] == array2[digit])
			numMatches++;
	}
	return numMatches;
}

/**************************************************
 *                 getNumberString                *
 * This function returns a string made up of the  *
 * digits in the int array that is passed to it.  *
 **************************************************/
string getNumberString(int array[])
{
	string numberString = "";
	for (int digit = 0; digit < SIZE; digit++)
	{
		// Convert the digit to a character and append it to the string
		numberString += (array[digit] + '0') ;
	}
	return numberString;
}

/* SAMPLE RESULTS RUN 1

Enter the 5 digits of your lottery number, separated by blanks: 9 3 4 4 1

Winning number: 30766
Your number   : 93441

You have 0 matching digit(s).

   SAMPLE RESULTS RUN 2

Enter the 5 digits of your lottery number, separated by blanks: 5 5 4 1 7

Winning number: 46419
Your number   : 55417

You have 2 matching digit(s).
*/
