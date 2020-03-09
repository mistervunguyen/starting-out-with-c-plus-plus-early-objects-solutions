// Chapter 9 - Programming Challenge 6, String Selection Sort 
// This program displays a set of strings after sorting them in
// ascending order. 
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

// Function prototype
void selectionSort(string [], int);
string upperCaseIt(const string);
void displayNames(const string [], int);

int main()
{
	const int SIZE = 20;

	// Set up the array of strings, in this case names
	string name[SIZE] = 
		{ "Collins, Bill",  "Smith, Bart",  "Michalski, Joe", "Griffin, Jim",
		  "Sanchez, Manny", "Rubin, Sarah", "Taylor, Tyrone", "Johnson, Jill", 
		  "Allison, Jeff",  "Moreno, Juan", "Wolfe, Bill",    "Whitman, Jean",
		  "Moretti, Bella", "Wu, Hong",     "Patel, Renee",   "Harrison, Rose",
		  "Smith, Cathy",   "Conroy, Pat",  "Kelly, Sean",    "Holland, Beth" };

	// Call a function to sort the strings
	selectionSort(name, SIZE);

	// Call a function to display the (now sorted) strings
   cout << "The names in sorted order are: \n\n";
   displayNames(name, SIZE);

   return 0;
}

/*************************************************************
 *                    selectionSort                          *
 * Called by: main                                           *
 * Passed   : The array of names and the number of names     *
 * Purpose  : Sorts the names into alphabetic                *
 *            (i.e. ascending) order                         *
 * Method   : Uses a selection sort modified to work with    *
 *            strings                                        *
 *************************************************************/
void selectionSort(string name[], int numStrings )
{
	int startScan,           // Array indexes to be compared
		minIndex;

	string minValue;
		
	// Sort the strings
	for (startScan = 0; startScan < (numStrings - 1); startScan++)
	{
		minIndex = startScan;
		minValue = name[startScan];
		for (int index = startScan + 1; index < numStrings; index++)
		{
			// Compare the uppercase version of the 2 strings
			// without changing the strings themselves
			if (upperCaseIt(name[index]) < upperCaseIt(minValue))
			{ 
				minValue = name[index];
				minIndex = index;
			}
		}
		// Move values to their new positions
		name[minIndex]  = name[startScan];
		name[startScan] = minValue;
	}   
}

/*************************************************************
 *                        upperCaseIt                        *
 * Called by: selectionSort                                  *
 * Passed   : A string                                       *
 * Returns  : An uppercased copy of the string passed in     *
 *************************************************************/
string upperCaseIt(const string stringIn)
{
	string s = stringIn;     // Local copy of stringIn we'll uppercase

	for (unsigned pos = 0; pos < s.length(); pos++)
	 	s[pos] = toupper(s[pos]);
	 
	return s;
}

/*************************************************************
 *                      displayNames                         *
 * Called by: main                                           *
 * Passed   : The array of names and the number of names     *
 * Purpose  : Prints the list of names                       *
 *************************************************************/
void displayNames(const string name[], int numNames)
{
	for (int item = 0; item < numNames; item++)
		cout << name[item] << endl;
}

/* CORRECT RESULTS

The names in sorted order are:

Allison, Jeff
Collins, Bill
Conroy, Pat
Griffin, Jim
Harrison, Rose
Holland, Beth
Johnson, Jill
Kelly, Sean
Michalski, Joe
Moreno, Juan
Moretti, Bella
Patel, Renee
Rubin, Sarah
Sanchez, Manny
Smith, Bart
Smith, Cathy
Taylor, Tyrone
Whitman, Jean
Wolfe, Bill
Wu, Hong
*/
