// Chapter 5 - Programming Challenge 20, Rectangle Display
// This program uses nested loops to display a rectangle filled with Xs
// whose dimensions are specified by the user.
#include <iostream>
using namespace std;

int main()
{
	const int MIN_SIDE = 2,       // Minimum length of a rectangle side
		      MAX_SIDE = 10;      // Maximum length of a rectangle side

	int length, width,            // User entered rectangle length and width
		temp;                     // A temporary variable for swapping numbers

	// Input and validate the rectangle dimensions
	cout << "Give me a set of rectangle dimensions and I will display the rectangle.\n\n";

	cout << "Enter an integer length between " << MIN_SIDE << " and " << MAX_SIDE << ": ";
	cin >> length;

	cout << "Enter an integer width between " << MIN_SIDE << " and " << MAX_SIDE << ": ";
	cin  >> width;
	
	while (length < MIN_SIDE || length > MAX_SIDE || width < MIN_SIDE || width > MAX_SIDE)
	{
		cout << "\nThe length of each side must be between " << MIN_SIDE << " and " << MAX_SIDE
			 << "\nRe-enter the rectangle length: ";
		cin  >> length;

		cout << "\nRe-enter the rectangle width: ";
		cin >> width;
		cout << endl;
	}

	// Ensure that the length is the larger of the two inputs
	if (length < width)
	{	temp = length;           // Swap them
		length = width;
		width = temp;
	}

	// Use a nested loop to display the rectangle
	cout << "\nHere is the rectangle.\n\n";
	for (int row = 1; row <= width; row++)
	{
		for (int X = 1; X <= length; X++)
			cout << 'X';
		cout << endl;
	}
	return 0;
}

/* SAMPLE RUN RESULTS

Give me a set of rectangle dimensions and I will display the rectangle.

Enter an integer length between 2 and 10: 3
Enter an integer width between 2 and 10: 8

Here is the rectangle.

XXXXXXXX
XXXXXXXX
XXXXXXXX
*/
