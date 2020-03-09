// Chapter 5 - Programming Challenge 9, Weight Loss
// This program creates a table displaying a dieting person's weight
// over a period of 6 months if they lose 4 pounds a month.
// Students may choose to use a different type of loop.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const int DIET_LENGTH = 6,      // Months on the diet
		      LOSS_PER_MONTH = 4;   // Expected monthly weight loss 
	int weight;
		      
	// Explain the program
	cout << "If you cut your calorie intake by 500 calories a day \n"
		 << "you can expect to lose about 4 pounds per month. \n"
		 << "This program will help you see your likely results. \n\n";

	cout << "Enter your current weight in pounds: ";
	cin  >> weight;

	// Print table heading
	cout << "\n     Weight Loss Table \n"
		 << "========================== \n";
	cout << "Starting Weight " << weight << " pounds \n";

	// Create and display the table
	for (int mo = 1; mo <= DIET_LENGTH; mo++)
	{
		weight -= LOSS_PER_MONTH;
		cout << "After month " << mo << "   " << weight << " pounds \n";
	}
	return 0;
}

/* SAMPLE RUN RESULTS

If you cut your calorie intake by 500 calories a day
you can expect to lose about 4 pounds per month.
This program will help you see your likely results.

Enter your current weight in pounds: 185

     Weight Loss Table
==========================
Starting Weight 185 pounds
After month 1   181 pounds
After month 2   177 pounds
After month 3   173 pounds
After month 4   169 pounds
After month 5   165 pounds
After month 6   161 pounds     
*/