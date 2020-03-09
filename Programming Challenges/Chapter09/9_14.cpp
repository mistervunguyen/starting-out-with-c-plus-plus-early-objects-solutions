// Chapter 9 - Programming Challenge 14, Using Files--Birthday Look Up
// This program modifies Programming Challenge 13 to display a sorted list of
// names, allows the user to select one, and then displays that person's
// birthday. The data file, birthdays.dat, is located in the Chapter 9 Programs
// folder, and for faculty is also in the same folder as this solution file. 
// A copy of the data file should be placed in the program's project directory. 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class Person
{
public:  string name,
	        	birthday;
};

const int SIZE = 10;

// Function prototypes
void getData(Person []);
void displayNames(const Person []);
int getChoice(int, int);
void selectionSort(Person []);
void findBirthday(const Person [], int);

int main()
{
	int choice,
		index;

	// Define the array that will hold the names and birthdays
	Person friends[SIZE];

	// Call a function to read the data from a file into the array
	getData(friends);

	// Call a function to sort the data in alphabetical name order
	selectionSort(friends);

	// Call functions to display the names & get the user's name choice
	displayNames(friends);
	choice = getChoice(1, SIZE);
	index = choice - 1;
	
	// Display chosen person's birthday
	findBirthday(friends, index);

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
 * Purpose  : Sorts the elements in ascending name order     *
  ************************************************************/
void selectionSort(Person friends[])
{
	int startScan,     // Array indexes to be compared
		minIndex;

	Person temp;       // Used to swap two friend elements
	string minValue;   // Will be in the name field of element
	                   // with minIndex
		
	// Sort array elements
	for (startScan = 0; startScan < (SIZE - 1); startScan++)
	{
		minIndex = startScan;
		minValue = friends[startScan].name;
		for (int index = startScan + 1; index < SIZE; index++)
		{   // Compare data in the name fields
			if (friends[index].name < friends[minIndex].name)
			{
				minValue = friends[index].name;
				minIndex = index;
			}
		}
		// Move elements to their new positions
		temp = friends[minIndex];
		friends[minIndex] = friends[startScan];
		friends[startScan] = temp;
	}   
}

/************************************************************
*                       displayNames                        *
* Called by: main                                           *
* Passed   : The data array                                 *
* Purpose  : Displays the names field of the elements.      *
*************************************************************/
void displayNames(const Person friends[])
{
	cout << "   Birthday List \n" << "  ============== \n";
	for (int pos = 0; pos < SIZE; pos++)
	{
		cout << setw(2) << pos + 1 << "  " << friends[pos].name << endl;
	}
	cout << endl;
}

/************************************************************
*                          getChoice                        *
* Called by: main                                           *
* Passed   : min and max values                             *
* Purpose  : Gets, validates, and returns user choice       *
************************************************************/
int getChoice(int min, int max)
{
	int choice;


	cout << "Enter the number of your choice: ";
	cin >> choice;

	while (choice < min || choice > max)
	{
		cout << "Choice must be between " << min << " and " << max << endl;
		cout << "Re-enter the number of your choice: ";
	}
	return choice;
}

/*************************************************************
 *                       findBirthday                        *
 * Called by: main                                           *
 * Passed   : The array of person objects and an index       *
 * Purpose  : Displays the name and birthday of the object   *
 *            at the specified index.                        *
 *************************************************************/
void findBirthday(const Person friends[], int index)
{
	cout << friends[index].name << "   " << friends[index].birthday << endl;
}

/* SAMPLE RUN RESULTS

   Birthday List
   ==============
 1  Anne Dawson
 2  Bill Johnson
 3  Darius Williams
 4  Dev Patel
 5  Evelyn Maroto
 6  Jill Benson
 7  Mario Rubio
 8  Randy Mack
 9  Sandra Day
10  Sean O'Connor

Enter the number of your choice: 5
Evelyn Maroto   11/03
*/
