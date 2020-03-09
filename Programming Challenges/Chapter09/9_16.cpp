// Chapter 9 - Programming Challenge 16, 
//             Using Vectors--String Selection Sort Modification
// This program, which uses Selection Sort to arrange a set of strings in 
// ascending order, modifies Programming Challenge 9-15 to use a vector of 
// strings, rather than an array of strings. The strings are read in from 
// the names.dat file, which is located in the Chapter 9 Programs folder, and for
// faculty is also in the same folder as this solution file. A copy of the data
// file should be placed in the program's project directory. 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

// Function prototypes
void getData(vector<string> &, int &);
void selectionSort(vector<string> &, int);
string upperCaseIt(const string);
void displayNames(vector<string>, int);

int main()
{
	// Define the vector that will hold the names
	vector<string> name;

	// define a counter to count the names as they are read in
	int numNames = 0; 

	// Call a function to read the names from a file into the vector
	getData(name, numNames);

	// Call a function to sort the strings
	selectionSort(name, numNames);

	// Call a function to display the (now sorted) strings
	cout << "The names in sorted order are: \n\n";
	displayNames(name, numNames);

	return 0;
}

/***************************************************************
 *                         getData                             *
 * Called by: main                                             *
 * Passed   : The empty name vector and the number of names    *
 *            (both by reference)                              *
 * Purpose  : Reads the names from a file, counts them, and    * 
 *            stores them in new vector elements. Upon         *
 *            returning, the name vector will hold the strings *
 *            and numStrings will hold the number of strings   *
 *            read in and stored.                              *
 ***************************************************************/
void getData(vector<string> &name, int &numStrings)
{
	numStrings = 0;
	string aName;
	ifstream dataIn;

	// Open the file and test that it opened correctly
	dataIn.open("names.dat");
	if (!dataIn)
		cout << "Error opening data file\n";
	else
	{   // Read in all the data
		while(getline(dataIn, aName))   // While there was a name to be read
		{
			name.push_back(aName);      // put it in a vector element
			numStrings++;               // and increment string count
		}
		// Close the file
		dataIn.close();
	}
}

/*************************************************************
 *                    selectionSort                          *
 * Called by: main                                           *
 * Passed   : The vector of names (by reference) and the     *
 *            number of names                                *
 * Purpose  : Sorts the names into alphabetic                *
 *            (i.e. ascending) order                         *
 * Method   : Uses a selection sort modified to work with    *
 *            strings                                        *
 *************************************************************/
void selectionSort(vector<string> &name, int numStrings )
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
		{	// Compare the uppercase version of the 2 strings
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
 *                       displayNames                        *
 * Called by: main                                           *
 * Passed   : The vector of names and the number of names    *
 * Purpose  : Prints the list of names                       *
 *************************************************************/
void displayNames(vector<string> name, int numNames)
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
