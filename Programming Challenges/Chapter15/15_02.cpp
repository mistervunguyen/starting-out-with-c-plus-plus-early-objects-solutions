// Chapter 15 - Assignment 2, Analysis of Quicksort
// This Program uses a class named AbstractSort as a framework
// for sorting algorithms that sort by comparing pairs of array entries.
// To obtain a concrete class for sorting, one first subclasses
// the AbstractSort class and then overrides the pure virtual function
// sort. The sort() function must call the compare(int, int) function
// To compare pairs of array entries. This program analyzes the performance
// of Quicksort.
 
#include <iostream>
#include <algorithm>
#include <cstdlib> // For random
#include <ctime>   // For time
using namespace std;

// This class provides the framework for sortng by comparisons
// and counting the numbber of comaprisons performed.
class AbstractSort
{
public:
    virtual void sort(int arr[ ], int size) = 0;   
    int getComparisonCount()
    {
        return comparisonCount;
    }
protected:    
    int compare(int x, int y);
    void resetComparisonCount()
    {
        comparisonCount = 0;
    }
private:
    int comparisonCount;    
};

//*****************************************
//       Abstract::compare                *
// Returns -1, 0, or 1 a la strcmp.       *
//*****************************************
int AbstractSort::compare(int x, int y)
{
    comparisonCount++;
    return x - y;
}

// Derived class specializes the AbstractSort class
// to use QkuickSort
class QuickSort : public AbstractSort
{
public:
    void sort(int arr[ ], int size);
private:
    void quicksort(int arr[ ], int lower, int upper);
    void partition(int arr[ ], int lower, int upper, int &pivot);
};

//************************************************************
//               QuickSort::sort                             *
// Sort the given array with the given number of elements.   *
//************************************************************
void QuickSort::sort(int arr[ ], int size)
{   
	resetComparisonCount();
    quicksort(arr, 0, size-1);
}

//*********************************************************
//             QuickSort::quicksort                       *
//   This implements the QuickSort algorithm.             *
//*********************************************************
void QuickSort::quicksort(int arr[ ], int lower, int upper)
{
   if (lower >= upper) return; 
   int pivot;
   partition(arr, lower, upper, pivot);
   quicksort(arr, lower, pivot-1);
   quicksort(arr, pivot+1, upper);
}

//******************************************
//         QuickSort::partition            *
//   Partition strategy for quicksort.     *
//******************************************
void QuickSort::partition(int arr[ ], int lower, int upper, int &pivot)
{
  pivot = lower;
  int frontier = lower+1;

  // Arr[lower..pivot-1], arr[pivot], arr[pivot+1.. frontier -1] has been partioned
  while (frontier <= upper)
  {
    if (compare(arr[frontier],  arr[pivot]) < 0)
    {
       swap(arr[frontier], arr[pivot+1]);
       swap(arr[pivot+1], arr[pivot]);
       pivot ++;
    }
    frontier ++;
    // Arr[lower..pivot-1], arr[pivot], arr[pivot+1.. frontier -1] has been partioned
  }
}

int main()
{
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size;
    
    // Explain the program
    cout << "This program keeps track of the number of comparisons required to\n"; 
    cout << "to sort a randomly generated array array.\n";

    // Get size of the array
    cout << "How large do you want the array to be?";    
    cin >> size;    
    if (size > MAX_SIZE) 
    {
        cout << "The size of the array must be no greater than 100.";
        exit(1);
    }
    
    // Initialize random number generator
    srand(time(0));
    
    // Fill the array with random values
    for (int k = 0; k < size; k++)
        arr[k] = rand() % 1000;
    
    // Output array to be sorted
    cout << "Array to be sorted is: \n";
    for (int k = 0; k < size; k++)
        cout << arr[k] << "  ";
    
    // Sort and output results
    QuickSort qsort;
    qsort.sort(arr, size);
    cout << "\nThe sorted array is: \n";
    for (int k = 0; k < size; k++)
        cout << arr[k] << "  ";
    cout << "\nNumber of comparisons performed is: " << qsort.getComparisonCount();
    
    return 0;    
}



