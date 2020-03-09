//  Chapter 14 --  Assignment 3, QuickSort Template
//  This program shows that recursive functions can use templates.
 
#include <iostream>
#include <algorithm>  // Needed for swap template function
using namespace std;


// Function Prototypes
template <class T>
void quickSort(T arr[], int start, int end);
template <class T>
int partition(T arr[], int start, int end);

int main()
{
      // Array to sort
	int array[10] = {7, 3, 9, 2, 0, 1, 8, 4, 6, 5};
	for (int  x = 0; x < 10; x++)
		cout << array[x] << " ";
	cout << endl;

      // Call QuickSort to sort
	quickSort<int>(array, 0, 9);

      // Print out sorted version of the array
	for (int x = 0; x < 10; x++)
		cout << array[x] << " ";
	cout << endl;

	return 0;
}

//**************************************************
//               quickSort                         *
// quickSort uses the quicksort algorithm to       *
// sort arr, from arr[start] through arr[end].     *
//**************************************************
template <class T>
void quickSort(T arr[], int start, int end)
{
	int pivotPoint;

	if (start < end)
	{
		// Get the pivot point
		pivotPoint = partition(arr, start, end);

		// Sort the first sub list
		quickSort(arr, start, pivotPoint - 1);

		// Sort the second sub list
		quickSort(arr, pivotPoint + 1, end);
	}
}

//***************************************************************
//              partition                                       *
// partition selects the value in the middle of the             *
// array set as the pivot. The list is rearranged so            *
// all the values less than the pivot are on its left           *
// and all the values greater than pivot are on its right.      *
//***************************************************************
template <class T>
int partition(T arr[], int start, int end)
{
   // Select the leftmost value in the range to be the pivot element
   int pivotPos = start;
   
   // Consider all the remaining elements, and put each to the left
   // of the pivot if it is less than the pivot element, and to the
   // right of the pivot if it is greater or equal to the pivot element
   for (int k = start + 1; k <= end; k++)
   {
      if (arr[k] < arr[pivotPos])
      {
         // To the left of the pivot in two swaps
         swap(arr[k], arr[pivotPos+1]);
         swap(arr[pivotPos], arr[pivotPos+1]);
         pivotPos = pivotPos +1;
      }
   }

   return pivotPos;
}

