// Chapter 9 - Programming Challenge 8, Search Benchmarks
// This program compares the number of comparisons used by linear
// search vs. binary search to find a value.
#include <iostream>
using namespace std;

// Function prototypes
int linearSearchBench(int[], int, int);
int binarySearchBench(int [], int, int);

const int SIZE = 20;

int main()
{
	int numCompares = 0;         // Accumulator to count the number of comparisons 
   
	int tests[SIZE] =            // The array to be searched
		{ 101, 142, 147, 189, 199, 207, 222,
		  234, 289, 296, 310, 319, 388, 394,
		  417, 429, 447, 521, 536, 600       };

	// Compare searches for a value in the middle of the array
	cout << "Searching for a value in the middle of the array -- \n";
	cout << "Searching for the value 296.\n";

	numCompares = linearSearchBench(tests, SIZE, 296);
	cout << "The linear search made " << numCompares 
		 << " comparisons.\n";

	numCompares = binarySearchBench(tests, SIZE, 296);
	cout << "The binary search made " << numCompares
		 << " comparisons.\n";

	// Compare searches for a value at the end of the array
	cout << "\nSearching for a value at the end of the array -- \n";
	cout << "Searching for the value 600.\n";

	numCompares = linearSearchBench(tests, SIZE, 600);
	cout << "The linear search made " << numCompares
		 << " comparisons.\n";

	numCompares = binarySearchBench(tests, SIZE, 600);
	cout << "The binary search made " << numCompares
		 << " comparisons.\n";

	// Compare searches for a value not in the array
	cout << "\nSearching for a value not in the array -- \n";
	cout << "Searching for the value 312.\n";

	numCompares = linearSearchBench(tests, SIZE, 312);
	cout << "The linear search made " << numCompares
		 << " comparisons.\n";

	numCompares = binarySearchBench(tests, SIZE, 312);
	cout << "The binary search made " << numCompares
		 << " comparisons.\n";

	return 0;
}

/********************************************************************
 *                       linearSearchBench                          *
 * Called by: main                                                  *
 * Passed   : An array to search in, the number of elements in      *
 *            the array, and the value to search for                *
 * Purpose  : To count the number of comparisons made to complete   *
 *            the linear search                                     *
 * Returns  : The comparison count                                  *
 * Note     : Linear search can be written to be more efficient than*
 *            the algorithm used below in determining that a value  *
 *            is NOT present in the array if the array elements     *
 *            are known to be in sorted order.                      *
 ********************************************************************/
int linearSearchBench(int array[], int numElems, int value)
{
	int  comparisons = 0,
		 index = 0;
	bool found = false;

	while (!found && index < numElems)
	{
		comparisons++;
		if (array[index++] == value)
			found = true;              // This lets us leave the loop
	}
	return comparisons;
}

/******************************************************************
 *                       binarySearchBench                        *
 * Called by: main                                                *
 * Passed   : An array to search in, the number of elements in    *
 *            the array, and the value to search for              *
 * Purpose  : To count the number of comparisons made to complete *
 *            the binary search                                   *
 * Returns  : The comparison count                                *
 ******************************************************************/
int binarySearchBench(int array[], int numElems, int value)
{
	bool found = false;
	int  first = 0, 
		 last = numElems - 1, 
		 middle,
		 comparisons = 0;

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		
		comparisons++;
		if (array[middle] == value)
			found = true;
		else if (array[middle] > value)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return comparisons;  
}

/* RUN RESULTS CREATED BY THIS TEST PROGRAM

Searching for a value in the middle of the array --
Searching for the value 296.
The linear search made 10 comparisons.
The binary search made 1 comparisons.

Searching for a value at the end of the array --
Searching for the value 600.
The linear search made 20 comparisons.
The binary search made 5 comparisons.

Searching for a value not in the array --
Searching for the value 312.
The linear search made 20 comparisons.
The binary search made 4 comparisons.

*/
