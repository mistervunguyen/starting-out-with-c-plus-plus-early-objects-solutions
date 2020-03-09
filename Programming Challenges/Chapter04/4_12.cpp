// Chapter 4 - Programming Challenge 12, Color Mixer
// This program determines what color will result 
// from mixing two primary colors.
#include <iostream>
#include <string>
using namespace std;

int main()
{
	bool validColor = true;
	string color1,
		   color2;
  
	// Explain the program
	cout << "When you enter two primary colors, I will tell you \n"
		 << "what color they make when they are mixed together.\n\n"; 

	// Get and validate the colors
	// If the colors are valid, report the color they make
	cout << "Enter red, blue, or yellow: ";
	getline(cin, color1);

	if (color1 == "red")
	{	cout << "Now enter blue or yellow: ";
		getline(cin, color2);

		if (color2 == "blue")
			cout << "\nRed and blue make purple. \n";
		else if (color2 == "yellow")
			cout << "\nRed and yellow make orange. \n";
		else
			cout << "\nYou did not enter a requested color. \n";
	}
	else if (color1 == "blue")
	{	cout << "Now enter red or yellow: ";
		getline(cin, color2);

		if (color2 == "red")
			cout << "\nBlue and red make purple. \n";
		else if (color2 == "yellow")
			cout << "\nBlue and yellow make green. \n";
		else
			cout << "\nYou did not enter a requested color. \n";
	}
	else if (color1 == "yellow")
	{	cout << "Now enter red or blue: ";
		getline(cin, color2);

		if (color2 == "red")
			cout << "\nYellow and red make orange. \n";
		else if (color2 == "blue")
			cout << "\nYellow and blue make green. \n";
		else
			cout << "\nYou did not enter a requested color. \n";
	}
	else
		cout << "\nYou did not enter a requested color. \n";
	
	return 0;
}

/* SAMPLE RESULT - RUN 1

When you enter two primary colors, I will tell you
what color they make when they are mixed together.

Enter red, blue, or yellow: blue
Now enter red or yellow: yellow

Blue and yellow make green.

SAMPLE RESULT - RUN 2

When you enter two primary colors, I will tell you
what color they make when they are mixed together.

Enter red, blue, or yellow: red
Now enter blue or yellow: pink

You did not enter a requested color.
*/
