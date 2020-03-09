// Chapter 3 - Programming Challenge 24, Angle Calculator 
// This program calculates the sine, cosine, and tangent of an angle.
// It uses C++ mathematical library functions.
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	double angRadian,   // Angle expressed in Radians
		   sine,        // Sine of the angle
		   cosine,      // Cosine of the angle
		   tangent;     // Tangent of the angle

	// Get user input
	cout << "Enter an angle (in radians):  ";
	cin  >> angRadian;

	// Perform calculations
	sine     = sin(angRadian);
	cosine   = cos(angRadian);
	tangent  = tan(angRadian);

	// Display results
	cout << fixed << showpoint << setprecision(4);
	cout << "\nThe sine of the angle is:\t"    << setw(7) << sine;
	cout << "\nThe cosine of the angle is:\t"  << setw(7) << cosine;
	cout << "\nThe tangent of the angle is:\t" << setw(7) << tangent
		 << endl << endl;
	return 0;
}

/* SAMPLE RUN RESULT

Enter an angle (in radians):  3.14159

The sine of the angle is:        0.0000
The cosine of the angle is:     -1.0000
The tangent of the angle is:    -0.0000
*/
