// Chapter 3 - Programming Challenge 12, How Many Calories?
// This program calculates the number of cookie calories consumed.
#include <iostream>
using namespace std;

int main()
{
	const int COOKIES_PER_BAG  = 30,
		      SERVINGS_PER_BAG = 10,
			  CALORIES_PER_SERVING = 240;

	int cookiesEaten,         // Number of cookies eaten
		servingSize,          // Number of cookies in a serving
		caloriesPerCookie,    // Calories in one cookie
		caloriesConsumed;     // Number of calories consumed

	// Prompt user for number of cookies eaten
	cout << "Number of cookies eaten: ";
	cin  >> cookiesEaten;

	// Perform calculations
	servingSize = COOKIES_PER_BAG / SERVINGS_PER_BAG;
	caloriesPerCookie = CALORIES_PER_SERVING / servingSize;
	caloriesConsumed = caloriesPerCookie * cookiesEaten;

	// Display result
	cout << "You consumed " << caloriesConsumed << " calories.\n";

	return 0;
}

/* SAMPLE RUN RESULTS

Number of cookies eaten: 5
You consumed 400 calories.
*/
