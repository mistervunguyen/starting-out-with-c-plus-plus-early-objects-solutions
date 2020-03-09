// Chapter 7 - Programming Challenge 16, Coin Toss Simulator - Solution A
// This program creates a Coin class and uses it in a client program that
// simulates tossing a coin and counting how times heads vs. tails come up.
// The Coin class is defined in this file, along with the client program. 
// Solution B, found in the file 7_16B.cpp defines the class in a separate file. 
#include <iostream>
#include <iomanip>
#include <cstdlib>            // Needed to use random numbers
#include <ctime>              // Neede to use time
#include <string>
using namespace std;

// Coin class declaration 
class  Coin
{
private:
	string sideUp;

public:
	// Default constructor 
	Coin()
	{
		srand(time(0));        // Set random generator seed 
		toss();
	}

	void toss()
	{
		int side = rand() % 2;     // Get random side showing

		if (side == 0)
			sideUp = "tails";
		else
			sideUp = "heads";
	}

	string getSideUp()
	{
		return sideUp;
	}
};

// Client program
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

Toss  1   tails
Toss  2   tails
Toss  3   heads
Toss  4   heads
Toss  5   tails
Toss  6   tails
Toss  7   heads
Toss  8   tails
Toss  9   tails
Toss 10   heads
Toss 11   heads
Toss 12   tails
Toss 13   heads
Toss 14   tails
Toss 15   tails
Toss 16   heads
Toss 17   heads
Toss 18   heads
Toss 19   tails
Toss 20   tails

Heads came up 9 times and tails came up 11 times.
*/
