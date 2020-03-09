// Dice class specification file
#ifndef DICE_H
#define DICE_H
#include <cstdlib>                // Needed to use random numbers
#include <ctime>                  // Needed to use time

using namespace std;

class  Dice
{
public:
	// Default constructor 
	Dice()
	{
		srand(time(0));           // Set random generator seed 
	}

	// The roll function rolls the dice and returns 
	// the value of the side that comes up (1-6) 
	int roll()  
	{
		return rand() % 6 + 1;
	}

};
#endif
