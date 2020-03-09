// Chapter 4 - Programming Challenge 16, Body Mass Index
// This program calculates a person's body mass index (BMI),
// which is based on a ratio between their weight and height.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double weight,    // User's weight in pounds
		   height,    // User's height in inches
		   BMI;       // User's body mass index

	// Input user's height and weight
	cout << "Input your weight and height and I will compute your body mass index (BMI). \n\n";
	cout << "Weight (in pounds): ";
	cin  >> weight;

	cout << "Height (in inches): ";
	cin  >> height;

	// Compute BMI
	BMI = (weight * 703) / (height * height);
	
    // Display results
	cout << "\nAn ideal BMI is between 18.5 and 25.0 \n";
	cout << "Your BMI = " << BMI << endl;;
	
	if (BMI < 18.5)
		cout << "This is considered underweight. \n ";
	else if (BMI > 25)
		cout << "This is considered overweight. \n";
	else  
		cout << "Congratulations. Your weight is healthy.\n";

	return 0;
}

/* SAMPLE RUN RESULTS

Input your weight and height and I will compute your body mass index (BMI).

Weight (in pounds): 138
Height (in inches): 64

An ideal BMI is between 18.5 and 25.0
Your BMI = 23.6851
Congratulations. Your weight is healthy.
*/
