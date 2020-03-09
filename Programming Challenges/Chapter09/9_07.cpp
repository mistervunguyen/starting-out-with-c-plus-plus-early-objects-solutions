// Chapter 9 - Programming Challenge 7, Binary String Search
// This program modifies binary search to work on strings. It uses 
// the code developed for Chapter 9 Programming Challenge 6 to sort 
// and display the strings before the array is searched for values.
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

// Function prototypes
void   selectionSort(string [], int);
string upperCaseIt(const string);
void   displayNames(const string [], int);
bool   binarySearch(const string [], int, string);

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

	// Call a function to search for a name that is in the array
	cout <<"\nSearching for Bill Wolfe ...\n";
	if (binarySearch(name, SIZE, "Wolfe, Bill"))
		cout << "Bill Wolfe was found in the array.\n";
	else
		cout << "Bill Wolfe was NOT found in the array.\n\n";

	// Search for a name that is NOT in the array
	cout <<"\nSearching for Wilbur the Pig...\n";
	if (binarySearch(name, SIZE, "Wilbur the Pig"))
		cout << "Wilbur the Pig was found in the array.\n";
	else
		cout << "Wilbur the Pig was NOT found in the array.\n";

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
	int startScan,    // Array indexes to be compared
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
 * Called by: selectionSort and binarySearch                 *
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
 *                       displayNames                        *
 * Called by: main                                           *
 * Passed   : The array of names and the number of names     *
 * Purpose  : Prints the list of names                       *
 *************************************************************/
void displayNames(const string name[], int NUM_NAMES)
{
	for (int item = 0; item < NUM_NAMES; item++)
		cout << name[item] << endl;
}

/****************************************************************
 *                        binarySearch                          *
 * Called by: main                                              *
 * Passed   : The array of strings, the number of strings,      *
 *            and the string being searched for                 *
 * Purpose  : Searches for a string in an array of strings      *
 * Method   : Uses a binary search modified to work with strings*
 * Returns  : Boolean true if the string is found, or false if  *
 *            it is not found                                   *
 ****************************************************************/
bool binarySearch(const string array[], int numElems, string searchString)
{
	bool found = false;
	int  first = 0,
		 last = numElems - 1, 
		 middle;

	// Uppercase the local copy of the string being searched for
	searchString = upperCaseIt(searchString);  

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		// Compare the uppercased search string to an uppercase version of 
		// a string in the array, without actually changing the array string
		if (upperCaseIt(array[middle]) == searchString)
			found = true;
		else if (upperCaseIt(array[middle]) > searchString)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return found;
}

/* OUTPUT CREATED BY THIS TEST PROGRAM

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

Searching for Bill Wolfe ...
Bill Wolfe was found in the array.

Searching for Wilbur the Pig...
Wilbur the Pig was NOT found in the array.
*/
