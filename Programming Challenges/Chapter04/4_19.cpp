// Chapter 4 - Programming Challenge 19, The Speed of Sound in Gases
// This program determines how far a sound wave traveled through a
// specific gas in a given number of seconds.
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// Speed of sound in meters per sec. through various gases
	const double CO2_SPEED      =  258.0,
	             AIR_SPEED      =  331.5,
			     HELIUM_SPEED   =  972.0,
				 HYDROGEN_SPEED = 1270.0;
	
	int    menuChoice;  // Menu choice for which gas the sound traveled through
	       
	double speed,       // Speed of sound (meters per sec.) in the selected gas
		   time,        // Number of seconds the sound wave traveled
		   distance;    // Number of meters the sound wave traveled  
		   
	string gas;         // Name of the gas the sound wave traveled thru
	          
	bool   validInput = true;     

	// Provide user selections and get input
	cout << "This program will tell you how far a sound wave traveled \n"
	     << "in a specified number of seconds through a particular gas. \n\n";
	cout << "Select which gas the sound wave traveled through.\n\n";
	cout << "  1. Carbon dioxide\n  2. Air\n  3. Helium\n  4. Hydrogen\n";
	cin  >> menuChoice;
   
	if (menuChoice < 1 || menuChoice > 4)
	{	cout << "\nYou may only enter 1, 2, 3, or 4 for the gas.\n";
		validInput = false;
	}
   
	if (validInput)        // This is asking if (validInput == true)
	{	cout << "\nEnter the number of seconds the sound wave traveled (0-30): ";
		cin  >> time;
      
		// Additional optional input validation
		if (time < 0.0 || time > 30.0)
		{	cout << "\nTravel time must be 0 and 30 seconds.\n";
			validInput = false;
		}
	}

	// If user inputs are valid, calculate and display
	// the distance the sound traveled. 
	if(validInput)         
	{
		switch(menuChoice)
		{
			case 1:	 speed = CO2_SPEED;
			         gas = "carbon dioxide";
				     break;
			case 2:	 speed = AIR_SPEED;   
			         gas = "air";
				     break;
			case 3:	 speed = HELIUM_SPEED;
			         gas = "helium";
				     break;
			case 4:	 speed = HYDROGEN_SPEED;
			         gas = "hydrogen";
		}
		distance = speed * time;
		cout << "In " << time << " seconds the sound wave went " 
		     << distance << " meters through " << gas << ".\n";
	}
	return 0;
}

/* SAMPLE RUN RESULTS

This program will tell you how far a sound wave traveled
in a specified number of seconds through a particular gas.

Select which gas the sound wave traveled through.

  1. Carbon dioxide
  2. Air
  3. Helium
  4. Hydrogen
2

Enter the number of seconds the sound wave traveled (0-30): 10
In 10 seconds the sound wave went 3315 meters through air.
*/
