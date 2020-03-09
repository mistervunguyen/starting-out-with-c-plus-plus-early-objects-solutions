// Chapter 4 - Programming Challenge 6, Change for a Dollar Game
// This program challenges the user to enter a combination of coins
// that equals exactly one dollar.
#include <iostream>
using namespace std;

int main()
{
	const double PENNY_VALUE   = .01,   
		         NICKEL_VALUE  = .05,
				 DIME_VALUE    = .10,
				 QUARTER_VALUE = .25,
				 GOAL          = 1.00;
				 
	int numPennies, numNickels, numDimes, numQuarters;
	double total;

	// Input the number of each denomination to use.
	cout << "The goal of this game is to enter a combination of quarters,\n"
	     << "dimes, nickels, and pennies that add up to exactly one dollar. \n\n";

	cout << "How many quarters should I use? ";
	cin  >> numQuarters;
	
	cout << "How many dimes should I use? ";
	cin  >> numDimes;

	cout << "How many nickels should I use? ";
	cin  >> numNickels;
	
	cout << "How many pennies should I use? ";
	cin  >> numPennies;

	total = numQuarters * QUARTER_VALUE + numDimes * DIME_VALUE + 
	        numNickels * NICKEL_VALUE + numPennies * PENNY_VALUE;
			
	if (total > GOAL)
		cout << "\nYour coins total $" << total << ". That is more than a dollar. \n";
	else if (total < GOAL)
		cout << "\nYour coins total $" << total << ". That is less than a dollar. \n";
	else
		cout << "\nCongratulations. Your coins total exactly a dollar. \n";

	return 0;
}

/* SAMPLE OUTPUT - RUN 1 
The goal of this game is to enter a combination of quarters,
dimes, nickels, and pennies that add up to exactly one dollar.

How many quarters should I use? 2
How many dimes should I use? 2
How many nickels should I use? 4
How many pennies should I use? 5

Your coins total $0.95. That is less than a dollar.

SAMPLE OUTPUT - RUN 2
The goal of this game is to enter a combination of quarters,
dimes, nickels, and pennies that add up to exactly one dollar.

How many quarters should I use? 3
How many dimes should I use? 1
How many nickels should I use? 2
How many pennies should I use? 5

Congratulations. Your coins total exactly a dollar.
*/
