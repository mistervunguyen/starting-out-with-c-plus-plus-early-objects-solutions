// Chapter 8 - Programming Challenge 8, Rainfall Statistics
// This program computes and displays rainfall statistics for
// a 12-month period.
#include<iostream>
#include <string>
#include<iomanip>
using namespace std;

// Function prototypes
void getData(double []);
double getTotal(double []);
double getAverage(double []);
int getLargest(double []);
int getSmallest(double []);

const int SIZE = 12;               // The number of months of data 
                                   // being input and analyzed

const string monthName[] = {"January",   "February",  "March",    "April", 
                            "May",       "June",      "July",     "August",
						    "September", "October",   "November", "December"};
int main()
{
	double rainfall[SIZE];         // Stores total rainfall for each month
	int largeIndex, smallIndex;    // Subscripts of array locations holding
	                               // the larges and smallest values respectively
                                 
	// Call function to input the rainfall data and store it in the array.
	getData(rainfall);
	
	// Print a report heading
	cout << "\n    2015 Rain Report for NeverSnows County \n";
	
	// Display the total rainfall
	cout << fixed << showpoint << setprecision(2) << endl;
	cout << "Total rainfall: " << getTotal(rainfall) << " inches \n"; 
	
	// Display the average rainfall
	cout << "Average monthly rainfall: " << getAverage(rainfall) << " inches \n";

	// Display the months with the least and most amounts of rain.
	smallIndex = getSmallest(rainfall);
	largeIndex = getLargest(rainfall);

	cout << "The least rain fell in " << monthName[smallIndex] 
	     << " with " << rainfall[smallIndex] << " inches. \n";
		 
	cout << "The most rain fell in " << monthName[largeIndex] 
	     << " with " << rainfall[largeIndex] << " inches. \n";
	
	return 0;
}

/************************************************************
 *                         getData                          *
 * Called by: main()                                        *
 *                                                          *
 * Purpose: Accepts inputs and stores them in the array     *
 * passed to it.                                            *
 ************************************************************/
void getData(double array[])
{
	for (int month = 0; month < SIZE; month++)
	{
		cout << "Enter the rainfall (in inches) for "
			 << monthName[month] << ": ";
		cin  >> array[month];
      
		while (array[month] < 0)
		{	cout << "Rainfall must be 0 or more. Please re-enter: ";
			cin  >> array[month];
		}
	}
}

/************************************************************
 *                       	getTotal                        *
 * Called by: main() and getAverage()                       *
 *                                                          *
 * Purpose: Calculates and returns the total of the numbers *
 * stored in the array.                                     *
 ************************************************************/
double getTotal(double array[])
{
	double total = 0.0;

	for (int pos = 0; pos < SIZE; pos++)
		total += array[pos];

	return total;
}

/************************************************************
 *                     	getAverage                          *
 * Called by: main()                                        *
 *                                                          *
 * Calls: GetTotal to return the total of the values in the *
 * array and uses this to compute the average.              *
 *                                                          *
 * Purpose: Calculates and returns the average of the       *
 * numbers stored in the array.                             *
 ************************************************************/
double getAverage(double array[])
{
	double average = getTotal(array) / SIZE;
	
	return average;
}

/************************************************************
 *                     	getLargest                          *
 * Called by: main()                                        *
 *                                                          *
 * Purpose: Finds the largest value stored in the array     *
 * passed to it and returns its subscript.                  *
 ************************************************************/
int getLargest(double array[])
{
	int largest = 0;  // Position of the largest element so far

	for (int pos = 1; pos < SIZE; pos++)
	{
		if (array[pos] > array[largest])
			largest = pos;
	}		
	return largest;
}

/************************************************************
 *                     	getSmallest                         *
 * Called by: main()                                        *
 *                                                          *
 * Purpose: Finds the smallest value stored in the array    *
 * passed to it and returns its subscript.                  *
 ************************************************************/
int getSmallest(double array[])
{
	int smallest = 0;  // Position of the smallest element so far

	for (int pos = 1; pos < SIZE; pos++)
	{
		if (array[pos] < array[smallest])
			smallest = pos;
	}		
	return smallest;
}

/* SAMPLE RUN RESULTS

Enter the rainfall (in inches) for January: .78
Enter the rainfall (in inches) for February: .50
Enter the rainfall (in inches) for March: 2.6
Enter the rainfall (in inches) for April: 4.8
Enter the rainfall (in inches) for May: 4.5
Enter the rainfall (in inches) for June: 3.2
Enter the rainfall (in inches) for July: 1.1
Enter the rainfall (in inches) for August: .75
Enter the rainfall (in inches) for September: 1.7
Enter the rainfall (in inches) for October: 1.4
Enter the rainfall (in inches) for November: 2.1
Enter the rainfall (in inches) for December: .83

    2015 Rain Report for NeverSnows County

Total rainfall: 24.26 inches
Average monthly rainfall: 2.02 inches
The least rain fell in February with 0.50 inches.
The most rain fell in April with 4.80 inches.
*/
