// Chapter 7 - Programming Challenge 17, Tossing Coins for a Dollar
// This program creates 3 instances of the Coin class created in Programming
// Challenge 16, one represents a quarter, another a dime, and another a
// nickel. It uses these to play a game. 
#include <iostream>
#include <iomanip>
#include "Coin.h"
using namespace std;

int main()
{
	double balance = 0;
	
	Coin quarter,          // Create 3 coin objects
		dime,
		nickel;

	while (balance < 1.00)
	{
		quarter.toss();
		if (quarter.getSideUp() == "heads")
			balance += .25;

		dime.toss();
		if (dime.getSideUp() == "heads")
			balance += .10;

		nickel.toss();
		if (nickel.getSideUp() == "heads")
			balance += .05;
	}
	if (balance == 1.00)
		cout << "Congratulations. Your tosses add up to $1.00 so you win! \n";
	else
	{
		cout << fixed << showpoint << setprecision(2);
		cout << "Your tosses add up to $" << balance << " so you lose. \n";
	}
	return 0;
}

/* SAMPLE OUTPUT RUN 1

Your tosses add up to $1.30 so you lose.

SAMPLE OUTPUT RUN 2

Congratulations. Your tosses add up to $1.00 so you win!
*/
