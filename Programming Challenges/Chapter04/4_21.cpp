// Chapter 4 - Programming Challenge 21, Freezing and Boiling Points
// This program indicates which substances will freeze, and which 
// will boil, at a user specified Fahrenheit temperature.
#include <iostream>
using namespace std;

int main()
{
	double temp;
	
	// Get a Fahrenheit temperature from the user
	cout << "This program indicates which substances freeze \n"
		 << "and which boil at a specified temperature.\n";
	cout << "Enter a Fahrenheit temperature: ";
	cin  >> temp;

	// Display which substances will freeze at that temperature
	cout << endl;
	if (temp <= 32)
		cout << "Water will freeze at that temperature.\n";
	if (temp <= -38)
		cout << "Mercury will freeze at that temperature.\n";
	if (temp <= -173)
		cout << "Ethyl Alcohol will freeze at that temperature.\n";
	if (temp < -362)
		cout << "Oxygen will freeze at that temperature.\n";
	
	// Display which substances will boil at that temperature
	if (temp >= -306)
		cout << "Oxygen will boil at that temperature.\n";
	if (temp >= 172)
		cout << "Ethyl Alcohol will boil at that temperature.\n";
	if (temp >= 212)
		cout << "Water will boil at that temperature.\n";
	if (temp >= 676)
		cout << "Mercury will boil at that temperature.\n";		

	return 0;
}

/* SAMPLE RUN RESULTS

This program indicates which substances freeze
and which boil at a specified temperature.
Enter a Fahrenheit temperature: 20

Water will freeze at that temperature.
Oxygen will boil at that temperature.
*/
