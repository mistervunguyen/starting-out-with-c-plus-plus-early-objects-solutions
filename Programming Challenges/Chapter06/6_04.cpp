// Chapter 6 - Programming Challenge 4, Kinetic Energy
// This program has a function that uses an object's mass
// and velocity to compute and return its kinetic energy.
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototype
double kineticEnergy(double, double);

int main()
{
	double mass,          // Object's mass in kilograms
		   velocity;      // Object's vecocity in meters-per-second

	cout << "Enter an object's mass and velocity, "
		 << "and I will compute its kinetic energy.\n\n";

	cout << "Mass in kilograms: ";
	cin  >> mass;
	cout << "Velocity in meters per second: ";
	cin  >> velocity;

	cout << "\nThe kinetic energy of this object is "
		 << kineticEnergy(mass, velocity) << " joules. \n";

	return 0;
	
}// end of main function

/**************************************************************
 *                       kineticEnergy                        *
 * When passed an object's mass (m) in kilograms and its      *
 * velocity (v) in meters-per-second, this function computes  *
 * and returns its kinetic energy in joules.                  *
 **************************************************************/   
double kineticEnergy(double m, double v)
{
	double ke = 0.5 * m * v * v;       // Compute kinetic energy
	return ke;
	
}// end of kineticEnergy function

/*SAMPLE RUN RESULTS

Enter an object's mass and velocity, and I will compute its kinetic energy.

Mass in kilograms: 3
Velocity in meters per second: 25

The kinetic energy of this object is 937.5 joules.
*/
