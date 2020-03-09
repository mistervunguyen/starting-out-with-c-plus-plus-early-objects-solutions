// Chapter 9 - Programming Challenge 9, Sorting Benchmarks 
// This program counts the exchanges made by Bubble Sort vs. Selection 
// Sort to sort a set of long integers and displays the two counts. 
#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 20;

// Function prototypes
int bubbleSort(long [], int);  
int selectionSort(long [], int);

int main()
{
	int exchanges;      // Number of exchanges made during the sort

	// Two identical arrays
	long accounts1[SIZE] =
		{  7058845,  9820125,  2214122,  4007541,  5001277,  6002850,
		   1200152,  8002555,  3202012,  1315352,  8115877,  9120255,
		   3298831,  9523331,  8073085,  4676651,  2681002,  9691212,
		   3082248,  1004354  };

	long accounts2[SIZE] = 
		{  7058845,  9820125,  2214122,  4007541,  5001277,  6002850,
		   1200152,  8002555,  3202012,  1315352,  8115877,  9120255,
		   3298831,  9523331,  8073085,  4676651,  2681002,  9691212,
		   3082248,  1004354  };

	cout << "The same twenty numbers were sorted by each of two sorts.\n";
	
	exchanges = bubbleSort(accounts1, SIZE);
	cout << setw(3) << exchanges
		 << " exchanges were made by Bubble Sort.\n";

	exchanges = selectionSort(accounts2, SIZE);
	cout << setw(3) << exchanges 
		 << " exchanges were made by Selection Sort.\n"; 
		  
	return 0;
}

/*************************************************************
 *                       bubbleSort                          *
 * Called by: main                                           *
 * Passed   : The array of numbers and the number of numbers *
 *            to be sorted                                   *
 * Purpose  : Sorts the numbers into ascending order and     *
 *            counts the number of swaps                     *
 * Method   : Uses a bubble sort                             *
 * Returns  : The number of swaps                            *
 *************************************************************/
int bubbleSort(long array[], int numElts)
{
	bool swap;
	long temp;
	int  exchanges = 0;

	do
	{
		swap = false;           // There have been no swaps yet on this pass
		for (int count = 0; count < (numElts - 1); count++)
		{
			if (array[count] > array[count + 1])
			{
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				swap = true;
				exchanges++;      // Count the swap
			}
		}
	} while (swap);            // While there was a swap on the previous pass

	return exchanges;
}

/*************************************************************
 *                    selectionSort                          *
 * Called by: main                                           *
 * Passed   : The array of numbers and the number of numbers *
 *            to be sorted                                   *
 * Purpose  : Sorts the numbers into ascending order and     *
 *            counts the number of swaps                     *
 * Method   : Uses selection sort                            *
 * Returns  : The number of swaps                            *
 *************************************************************/
int selectionSort(long array[], int numElts)
{
	int  startScan,       // These are array indexes to be compared
		 minIndex,
		 exchanges = 0;
	long minValue;
		
	for (startScan = 0; startScan < (numElts - 1); startScan++)
	{
		minIndex = startScan;
		minValue = array[startScan];
		for (int index = startScan + 1; index < numElts; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			}
		}
		// Move values to their new positions
		array[minIndex]  = array[startScan];
		array[startScan] = minValue;
		exchanges++;                  // Count the swap
	} 
	return exchanges;
}

/* CORRECT RESULTS FOR THESE PARTICULAR 20 VALUES

The same twenty numbers were sorted by each of two sorts.
100 exchanges were made by Bubble Sort.
19 exchanges were made by Selection Sort.
*/
