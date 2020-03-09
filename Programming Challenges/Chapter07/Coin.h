// Coin class specification file
#ifndef COIN_H
#define COIN_H
#include <cstdlib>                // Needed to use random numbers
#include <ctime>                  // Needed to use time
#include <string>
using namespace std;

class  Coin
{
private:
	string sideUp;

public:
	// Default constructor 
	Coin()
	{
		srand(time(0));           // Set random generator seed 
		toss();
	}

	void toss()
	{
		int side = rand() % 2;    // Get random side showing

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
#endif

