// Chapter 7 - Programming Challenge 16, Coin Toss Simulator - Solution B
// This program creates a Coin class and uses it in a client program that
// simulates tossing a coin and counting how times heads vs. tails come up.
// The Coin class is defined in a separate header file. Solution A, found in  
// the file 7_16A.cpp, defines the class in the same file as the client program. 
#include <iostream>
#include <iomanip>
#include "Coin.h"
using namespace std;

int main()
{
	const int NUM_TOSSES = 20;
	
	Coin tosser;          // Create a coin object

	int numHeads = 0;
	
	// Toss the coin and display and count the results
	for (int toss = 1; toss <= NUM_TOSSES; toss++)
	{
		cout << "Toss " << setw(2) << toss << "   ";

		tosser.toss();              // Toss the coin
		if (tosser.getSideUp() == "heads")
		{
			cout << "heads \n";
			numHeads++;
		}
		else
			cout << "tails \n";
	}

	// Report the totals
	cout << "\nHeads came up " << numHeads << " times and tails came up "
	     << NUM_TOSSES - numHeads << " times. \n";

	return 0;
}

/* SAMPLE RUN OUTPUT 

Toss  1   heads
Toss  2   tails
Toss  3   heads
Toss  4   heads
Toss  5   tails
Toss  6   heads
Toss  7   heads
Toss  8   tails
Toss  9   tails
Toss 10   tails
Toss 11   heads
Toss 12   tails
Toss 13   tails
Toss 14   heads
Toss 15   tails
Toss 16   heads
Toss 17   heads
Toss 18   tails
Toss 19   tails
Toss 20   heads

Heads came up 10 times and tails came up 10 times.
*/
