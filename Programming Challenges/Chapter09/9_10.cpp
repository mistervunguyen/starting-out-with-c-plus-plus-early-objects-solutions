// Chapter 9 - Programming Challenge 10, Sorting Orders
// This program shows step-by-step how Bubble Sort and Selection Sort
// work by sorting the same set of numbers with each, and displayng the 
// numbers after each pass of each sort. 
#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 8;

// Function prototypes
void bubbleSort(int [], int);  
void selectionSort(int [], int);
void showNums(int[], int);

int main()
{
	// Two identical arrays
	int array1[SIZE] = { 705,  98,  221,  400,  50,  62,  120,  80 };
	int array2[SIZE] = { 705,  98,  221,  400,  50,  62,  120,  80 };

	// Call function to sort the first array using bubble sort
	bubbleSort(array1, SIZE);

	// Call function to sort the second array using selection sort
	selectionSort(array2, SIZE);
	
	return 0;
}

/*************************************************************
 *                       showNums                            *
 * Called by: main and both sorts                            *
 * Passed   : The array of numbers and the number of numbers *
 *            to be sorted                                   *
 * Purpose  : Displays the current order of the numbers in   *
 *            the array.                                     *
 *************************************************************/
void showNums(int array[], int numElts)
{
	for (int pos = 0; pos < numElts; pos++)
		cout << setw(5) << array[pos];
	cout << endl;
}


/*************************************************************
 *                       bubbleSort                          *
 * Called by: main                                           *
 * Passed   : The array of numbers and the number of numbers *
 *            to be sorted                                   *
 * Purpose  : Demonstrates the bubble sort by sorting the    *
 *            numbers into ascending order with a bubble sort*
 *            and displaying the array after each pass.      *
 *************************************************************/
void bubbleSort(int array[], int elems)
{
	bool swap;
	int  temp,
		 pass = 1;

	cout << "__________________________________________________________________________\n";
	cout << "\nOriginal array:                   ";
	showNums(array, elems);
	cout << "__________________________________________________________________________\n";
	do
	{
		swap = false;   // There have been no swaps yet on this pass.
		for (int count = 0; count < (elems - 1); count++)
		{
			if (array[count] > array[count + 1])
			{
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				swap = true;
			}
		}
		// Display the array after this pass
		cout << "Contents after bubble pass " << pass++ << ":     ";
		showNums(array, elems);

	} while (swap);    // While there was a swap on the previous pass
}
	
/*************************************************************
 *                    selectionSort                          *
 * Called by: main                                           *
 * Passed   : The array of numbers and the number of numbers *
 *            to be sorted                                   *
 * Purpose  : Demonstrates the selection sort by sorting the *
 *            numbers into ascending order with a selection  *
 *            sort and displaying the array after each pass. *
 *************************************************************/
void selectionSort(int array[], int elems)
{
	int startScan,      // These are array indexes to be compared
		minIndex,
		minValue,
		pass = 1;

	cout << "\n__________________________________________________________________________\n";   
	cout << "\nOriginal array:                   ";
	showNums(array, elems);
	cout << "__________________________________________________________________________\n";
		
	for (startScan = 0; startScan < (elems - 1); startScan++)
	{
		minIndex = startScan;
		minValue = array[startScan];
		for (int index = startScan + 1; index < elems; index++)
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

		// Display the array after this pass
		cout << "Contents after selection pass " << pass++ << ":  ";
		showNums(array, elems);
	} 
}

/* CORRRECT RESULTS

__________________________________________________________________________

Original array:                     705   98  221  400   50   62  120   80
__________________________________________________________________________
Contents after bubble pass 1:        98  221  400   50   62  120   80  705
Contents after bubble pass 2:        98  221   50   62  120   80  400  705
Contents after bubble pass 3:        98   50   62  120   80  221  400  705
Contents after bubble pass 4:        50   62   98   80  120  221  400  705
Contents after bubble pass 5:        50   62   80   98  120  221  400  705
Contents after bubble pass 6:        50   62   80   98  120  221  400  705

__________________________________________________________________________

Original array:                     705   98  221  400   50   62  120   80
__________________________________________________________________________
Contents after selection pass 1:     50   98  221  400  705   62  120   80
Contents after selection pass 2:     50   62  221  400  705   98  120   80
Contents after selection pass 3:     50   62   80  400  705   98  120  221
Contents after selection pass 4:     50   62   80   98  705  400  120  221
Contents after selection pass 5:     50   62   80   98  120  400  705  221
Contents after selection pass 6:     50   62   80   98  120  221  705  400
Contents after selection pass 7:     50   62   80   98  120  221  400  705
*/
