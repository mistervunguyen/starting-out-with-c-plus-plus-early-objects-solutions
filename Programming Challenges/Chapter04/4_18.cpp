// Chapter 4 - Programming Challenge 18, The Speed of Sound
// This program determines the time required for sound to 
// travel a specified distance through a selected substance.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	// Speed of sound in feet per sec. through various media
	const int AIR_SPEED   = 1100,
	          WATER_SPEED = 4900,
			  STEEL_SPEED = 16400;
	
	int    menuChoice,  // Menu choice selecting the medium
	       speed;       // Speed of sound (ft. per sec.) in this medium
		   
	string medium;      // Name of the substance sound is travelling thru
          
	double distance,    // Number of feet the sound will travel
	       time;        // Number of seconds required to travel this far
          
	bool   validInput = true;     

	// Provide user selections and get input
	cout << "This program will tell you how long it takes a sound wave \n"
	     << "to travel a specific distance through a particular medium. \n\n";
	cout << "Select a substance for the sound to travel through:\n";
	cout << "     1. Air\n     2. Water\n     3. Steel\n";
	cin  >> menuChoice;

	if (menuChoice < 1 || menuChoice > 3)
	{	cout << "\nYou may only enter 1, 2, or 3 for the medium.\n";
		validInput = false;
	}
	if (validInput)        // Same as saying if (validInput == true)
	{	cout << "\nEnter the number of feet the sound wave will travel: ";
		cin  >> distance;
		if (distance < 0)
		{	cout << "\nYou may only enter positive numbers for distance.\n";
			validInput = false;
		}
	}
	// If user inputs are valid, calculate and display sound travel time
	if(validInput)         
	{
		switch(menuChoice)
		{
			case 1:	 speed = AIR_SPEED;    
			         medium = "air";
				     break;
			case 2:	 speed = WATER_SPEED;    
			         medium = "water";
				     break;
			case 3:	 speed = STEEL_SPEED;   
			         medium = "steel";
		}
		time = distance / speed;
		
		cout << "The sound wave will travel " << distance << " feet through ";
		cout << fixed << showpoint << setprecision(4);
		cout << medium << " in " << time << " seconds.\n";
	}
	return 0;
}

/* SAMPLE RUN RESULTS

This program will tell you how long it takes a sound wave
to travel a specific distance through a particular medium.

Select a substance for the sound to travel through:
     1. Air
     2. Water
     3. Steel
3

Enter the number of feet the sound wave will travel: 5280
The sound wave will travel 5280 feet through steel in 0.3220 seconds.
*/