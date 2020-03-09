// Chapter 7 - Programming Challenge 4, Car Class
// This program creates a Car class and uses it to create a Car 
// object that simulates an accelerating and braking Car object.
#include <iostream>
#include <string>
using namespace std;

// Car class declaration
class Car
{
  private:
	int year;       // Model year of the Car
	string make;    // Make of the Car
	int speed;      // Current speed of the Car (mph)
   
  public:
	// Constructor with default parameters
	Car(int y = 2013, string m = "Unknown")
	{	year = y;
		make = m;
		speed = 0;
	}

	// Accessors (i.e. "get" functions)
	int getYear()
	{  return year;  }

	string getMake()
	{  return make;  }

	int getSpeed()
	{  return speed;  }

	// Mutators
	void accelerate()
	{  speed +=5;  }

	void brake()
	{	if (speed >= 5)
			speed -=5;
		else
			speed = 0;
	}
};
   
// ************************* main ***************************
int main()
{
	Car hotRod(2017, "Mazda");        // Create a Car object

	// Describe the car (This line was not required by the problem specs.)
	cout << "I'm in my " << hotRod.getYear() << " " 
		 << hotRod.getMake() << " hot rod.\n\n";

	// Accelerate 
	cout << "I'm accelerating ... \n\n";
	for (int faster = 1; faster <= 5; faster++)
	{
		hotRod.accelerate();
		cout << "Current speed: " << hotRod.getSpeed() << " mph. \n";
	}

	// Now stop
	cout << "\nNow I'm braking ... \n\n";
	for (int slower = 1; slower <= 5; slower++)
	{
		hotRod.brake();
		cout << "Current speed: " << hotRod.getSpeed() << " mph. \n";
	}    
	return 0;
}

/* RUN RESULTS

I'm in my 2017 Mazda hot rod.

I'm accelerating ...

Current speed: 5 mph.
Current speed: 10 mph.
Current speed: 15 mph.
Current speed: 20 mph.
Current speed: 25 mph.

Now I'm braking ...

Current speed: 20 mph.
Current speed: 15 mph.
Current speed: 10 mph.
Current speed: 5 mph.
Current speed: 0 mph.
*/
