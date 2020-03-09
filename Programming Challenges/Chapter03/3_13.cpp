// Chapter 3 - Programming Challenge 13, Ingredients Adjuster
// This program adjusts a recipe based on the number of cookies desired.
#include <iostream>
using namespace std;

int main()
{
	const double RECIPE_SUGAR  = 1.5,   // cups
		         RECIPE_BUTTER = 1.0,
			     RECIPE_FLOUR  = 2.75;

	const int RECIPE_COOKIES = 48;  // Batch size
	            
	int desiredCookies;            // Number of cookies to bake

	double conversionFactor,     // Converts from recipe qty to desired qty
		   sugar, butter, flour; // How much of each ingredient to use
	
	// Prompt user for number of cookies desired
	cout << "Number of cookies you want to make: ";
	cin >> desiredCookies;

	// Perform calculations avoiding integer division
	conversionFactor = (double) desiredCookies / RECIPE_COOKIES;
	sugar  = conversionFactor * RECIPE_SUGAR;
	butter = conversionFactor * RECIPE_BUTTER;
	flour = conversionFactor * RECIPE_FLOUR;
	
	// Display results
	cout << "\nTo make " << desiredCookies << " cookies, you should use \n"
	 	 << sugar << " cups of sugar, " << butter << " cups of butter, and "
		 << flour << " cups of flour. \n";

	return 0;
}

/* SAMPLE RUN RESULTS

Number of cookies you want to make: 60

To make 60 cookies, you should use
1.875 cups of sugar, 1.25 cups of butter, and 3.4375 cups of flour.
*/
