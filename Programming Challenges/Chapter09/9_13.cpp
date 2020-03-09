// Chapter 9 - Programming Challenge 13, Using Files--Birthday List
// This program reads names and birthdays in from a file, stores them in an 
// array of objects, sorts the data by birthday, and displays it. To simplify 
// the program, the Person class data has been made public. The data 
// file, birthdays.dat, is located in the Chapter 9 Programs folder, and for
// faculty can also be found in the same folder as this solution file. A copy
// of this file should be placed in the program's project directory. 
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

class Person
{
public:  string name,
	        	birthday;
};

const int SIZE = 10;

// Function prototypes
void getData(Person []);
void selectionSort(Person []);
void displayBirthdays(const Person []);

int main()
{
	// Define the array that will hold the names and birthdays
	Person friends[SIZE];

	// Call a function to read the data from a file into the array
	getData(friends);

	// Call a function to sort the data in date order
	selectionSort(friends);

	// Call a function to display the (now sorted) data
	cout << "Birthday List \n" << "Date     Name \n" << "============= \n";
	displayBirthdays(friends);

	return 0;
}

/****************************************************************
 *                            getData                           *
 * Called by: main                                              *
 * Passed   : The array holding the data                        *
 * Purpose  : Reads the data from a file into the array elements*
 ****************************************************************/
void getData(Person friends[])
{
	ifstream dataIn;

	// Open the file and test that it opened correctly
	dataIn.open("birthdays.dat");
	if (!dataIn)
		cout << "Error opening data file\n";
	else
	{	// Read in all the data
		for (int index = 0; index < SIZE; index++)
		{
			getline(dataIn, friends[index].name);
			getline(dataIn, friends[index].birthday);
		}
		// Close the file
		dataIn.close();
	}
}

/*************************************************************
 *                    selectionSort                          *
 * Called by: main                                           *
 * Passed   : The data array                                 *
 * Purpose  : Sorts the elements in ascending date order     *
  ************************************************************/
void selectionSort(Person friends[])
{
	int startScan,     // Array indexes to be compared
		minIndex;

	Person temp;       // Used to swap two friend elements
	string minValue;   // Will be in the birthday field of element
	                   // with minIndex
		
	// Sort array elements
	for (startScan = 0; startScan < (SIZE - 1); startScan++)
	{
		minIndex = startScan;
		minValue = friends[startScan].birthday;
		for (int index = startScan + 1; index < SIZE; index++)
		{   // Compare data in the birthday fields
			if (friends[index].birthday < friends[minIndex].birthday)
			{
				minValue = friends[index].birthday;
				minIndex = index;
			}
		}
		// Move elements to their new positions
		temp = friends[minIndex];
		friends[minIndex] = friends[startScan];
		friends[startScan] = temp;
	}   
}

/*************************************************************
 *                   displayBirthdays                        *
 * Called by: main                                           *
 * Passed   : The array of person objects                    *
 * Purpose  : Prints names and bithdays in order of date.    *
 *************************************************************/
void displayBirthdays(const Person friends[])
{
	for (int pos = 0; pos < SIZE; pos++)
		cout << friends[pos].birthday << "   " << friends[pos].name << endl;
}

/* CORRECT RESULTS

Birthday List
Date     Name
=============
02/09   Mario Rubio
03/16   Sandra Day
06/08   Sean O'Connor
07/15   Dev Patel
08/22   Darius Williams
09/18   Anne Dawson
10/31   Randy Mack
11/03   Evelyn Maroto
11/22   Bill Johnson
12/01   Jill Benson
*/
