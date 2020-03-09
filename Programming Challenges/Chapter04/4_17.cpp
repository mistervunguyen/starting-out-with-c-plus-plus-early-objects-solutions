// Chapter 4 - Programming Challenge 17, Fat Gram Calculator
// This program calculates the percent of food calories that are fat
// and lets the user know if the food is considered low-fat. 
#include <iostream>
using namespace std;

int main()
{
	const int CALORIES_PER_FAT_GRAM = 9;
	
	int totalCalories,    // Total calories in the food
	    fatGrams,         // Number of grams of fat in the food
	    fatCals;          // Number of calories from fat
	double fatPercent;    // % of the calories that come from fat

	// Get input from user
	cout << "This program will tell you if your food is low fat.\n\n";
	cout << "How many calories are in the food? ";
	cin  >> totalCalories;
	cout << "How many fat grams are in the food? ";
	cin  >> fatGrams;

	// Calculate number of fat calories
	fatCals = fatGrams * CALORIES_PER_FAT_GRAM;
      
	// Use branching logic to display the appropriate output
	if (totalCalories <= 0)
		cout << "\nCalories must be greater than zero.\n";
	else if (fatGrams < 0)
		cout << "Grams of fat cannot be less than zero.\n";
	else if (fatCals > totalCalories)
	{	cout << "\nThe input is invalid.\n";
		cout << "There are more calories in " << fatGrams << " grams of fat\n"
			 << "than you entered for total calories.\n";	  
	}
	else
	{	// Calculate and display what % of the calories are from fat
		fatPercent = 100.0 * fatCals / totalCalories;
		     
		cout << "\n" << fatPercent << "% of the total calories are from fat.\n";
		if (fatPercent < 30.0)
			cout << "This food is low in fat.\n";
	}
   	return 0;
}

/* SAMPLE RESULTS - RUN 1
This program will tell you if your food is low fat.

How many calories are in the food? 450
How many fat grams are in the food? 25

50% of the total calories are from fat.

SAMPLE RESULTS - RUN 2
This program will tell you if your food is low fat.

How many calories are in the food? 450
How many fat grams are in the food? 12

24% of the total calories are from fat.
This food is low in fat.
*/
