// Chapter 9 - Programming Challenge 5, Hit the Slopes
// This program stores a week's worth of snow data for a ski resort, sorts it,
// in ascending order of base snow depth, and then displays the results. The
// problem indicates that students may use an array of structures or objects.
// This solution uses structures.
#include<iostream>
#include <string>
#include <iomanip>
using namespace std;

struct SnowData
{
	int day;                              // Day of a month
	double snowDepth;                     // Base snow depth (in inches)

	SnowData(int d = 1, double s = 0.0)   // Constructor that uses default 
	{ day = d; snowDepth = s;}            // values if fewer than 2  
};                                        // arguments are passed to it

// Function prototypes
void getData(SnowData[], string&, int&, int);
void sortData(SnowData[], int);
void displayData(const SnowData[], string, int, int);

const int DAYS_IN_PERIOD = 7;

int main()
{                                 
	string month;
	int startDate;
	SnowData base [DAYS_IN_PERIOD];    //Create an array of SnowData structures

	// Call function to input the daily snow depths
	getData (base, month, startDate, DAYS_IN_PERIOD);

	// Call function to sort the data by snow depth
	sortData (base, DAYS_IN_PERIOD);

	// Call function to display the sorted data
	displayData (base, month, startDate, DAYS_IN_PERIOD);
	
	return 0;
}

/************************************************************
 *                       	getData                          *
 * Called by: main()                                        *
 *                                                          *
 * Receives 4 arguments: the base array, references to the  *
 * location in main where the name of the month and the     *
 * starting day in the measurement period will be stored,   *
 * and the number of days for which snow measurements are   *
 * to be recorded.                                          *
 *                                                          *
 * Purpose: Inputs, validates, and stores the base snow     *
 *          amount for each day in the measurement period.  *
 ************************************************************/
void getData (SnowData base[], string &month, int &startDate, int numDays)
{
	cout << "This program keeps track of base snow conditions\n"
		 << "at the Alpine Heaven Resort.\n";
	cout << "\nEnter the month and starting date of the report\n"
		 << "(e.g. January 9): ";
	cin  >> month >> startDate;
	cout << endl;

	for (int measurement = 0, date = startDate; measurement < numDays;
                                                measurement++, date++)
	{
		base[measurement].day = date;
		cout << "Enter the base snow (in inches) for " 
			 << month << " " << date << ": ";
		cin  >> base[measurement].snowDepth;
      
		while (base[measurement].snowDepth < 0)
		{	cout << "Snow depth must be 0 or more.  Please re-enter: ";
			cin  >> base[measurement].snowDepth;
		}
 	}
}

/************************************************************
 *                         sortData                         *
 * Called by: main()                                        *
 *                                                          *
 * Receives 2 arguments: the array and its size (numElts)   *
 *                                                          *
 * Purpose  : Sorts the array elements in ascending order   *
 *            by the snowDepth field.                       *
 ************************************************************/
void sortData(SnowData array[], int numElts)
{
	int startScan,
		minIndex;
	double minValue;
	SnowData temp;
		 
	for (startScan = 0; startScan < (numElts - 1); startScan++)
	{
		minIndex = startScan;
		minValue = array[startScan].snowDepth;
		for (int index = startScan + 1; index < numElts; index++)
		{
			if (array[index].snowDepth < minValue)
			{
				minValue = array[index].snowDepth;
				minIndex = index;
			}
		}
		// Swap records in array[startScan] and array[maxIndex]
		temp = array[minIndex];
		array[minIndex] = array[startScan];
		array[startScan] = temp;
	}   
}

/************************************************************
 *                      displayData                         *
 * Called by: main()                                        *
 *                                                          *
 * Receives 4 arguments: the base array, a string holding   *
 * the name of the month, an int holding the starting date  *
 * of the measurement period, and an int holding the size   *
 * of the array, which equals the number of days for which  *
 * snow data has been recorded.                             *
 *                                                          *
 * Purpose  : Displays the data in each structure.          *
 ************************************************************/
void displayData (const SnowData base[], string month, 
                                         int startDate, int numDays)
{
	cout << fixed << showpoint << setprecision(1);
	cout << "\nSnow Report " << month << " " << startDate
		 << " - " << (startDate + 6)    << "\n     Date    Base \n";
  
  	for (int m = 0; m < numDays; m++)
	 	cout << setw(8) << base[m].day << setw(9) << base[m].snowDepth << endl;
}

/* SAMPLE RUN RESULTS

This program keeps track of base snow conditions
at the Alpine Heaven Resort.

Enter the month and starting date of the report
(e.g. January 9): February 5

Enter the base snow (in inches) for February 5: 13
Enter the base snow (in inches) for February 6: 13
Enter the base snow (in inches) for February 7: 13
Enter the base snow (in inches) for February 8: 15
Enter the base snow (in inches) for February 9: 15
Enter the base snow (in inches) for February 10: 15
Enter the base snow (in inches) for February 11: 14

Snow Report February 5 - 11
     Date    Base
       5     13.0
       6     13.0
       7     13.0
      11     14.0
       9     15.0
      10     15.0
       8     15.0
*/
