// Chapter 7 - Programming Challenge 18, Fishing Game Simulation
// This program creates an instance of the Dice class, which the student must
// write, and uses it to simulate what the user "catches" while fishing.
// Students may use different "catches" and point values.
#include <iostream>
#include <iomanip>
#include "Dice.h"
using namespace std;

int main()
{
	Dice myDice;           // Create a 6-sided Dice object
	int side;              // Which side of the dice displays
	double points = 0;
	char play;

	cout << "Let's play a fishing game and see what you catch \n\n"
		 << "Enter f to start fishing: ";
	cin  >> play;
		
	while (play == 'f' || play == 'F')
	{
		side = myDice.roll();

		switch (side)
		{
		case 1: cout << "You caught a small fish. You earn 2 points. \n\n";
			points += 2;
			break;

		case 2: cout << "You caught a medium fish. You earn 4 points. \n\n";
			points += 4;
			break;

		case 3: cout << "You caught a big fish. You earn 6 points. \n\n";
			points += 6;
			break;

		case 4: cout << "A fish took your bait. You lose 2 points. \n\n";
			points -= 2;
			break;

		case 5: cout << "You caught an old shoe. You earn 0 points. \n\n";
			break;

		case 6: cout << "Your line tangled on something. You lose 1 point. \n\n";
			points -= 1;
		}

		cout << "Enter f to keep fishing or anything else to quit: ";
		cin >> play;
	}

	// Tell the user how they did
	if (points >= 20)
		cout << "\nYou had a great day. You earned " << points << " points.\n";
	else if (points >= 8)
		cout << "\nYou had a fair day. You earned " << points << " points.\n";
	else
	{	
		cout << "\nWell you didn't do so well. ";

		if (points >= 0)
			cout << "You earned just " << points << " points. \n";
		else
			cout << "You lost " << points << " points. \n";

		cout << "But I hope you had fun anyway. \n";
	}
	return 0;
}

/* SAMPLE RUN OUTPUT 

Let's play a fishing game and see what you catch

Enter f to start fishing: f
You caught a big fish. You earn 6 points.

Enter f to keep fishing or anything else to quit: f
A fish took your bait. You lose 2 points.

Enter f to keep fishing or anything else to quit: f
You caught an old shoe. You earn 0 points.

Enter f to keep fishing or anything else to quit: f
You caught a small fish. You earn 2 points.

Enter f to keep fishing or anything else to quit: f
A fish took your bait. You lose 2 points.

Enter f to keep fishing or anything else to quit: f
You caught a medium fish. You earn 4 points.

Enter f to keep fishing or anything else to quit: f
You caught an old shoe. You earn 0 points.

Enter f to keep fishing or anything else to quit: f
You caught an old shoe. You earn 0 points.

Enter f to keep fishing or anything else to quit: f
You caught a small fish. You earn 2 points.

Enter f to keep fishing or anything else to quit: q

You had a fair day. You earned 10 points.
*/
