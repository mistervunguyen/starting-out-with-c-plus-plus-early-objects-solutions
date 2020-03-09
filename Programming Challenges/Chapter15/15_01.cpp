// Chapter 15 - Assignment 1, Analysis of Sorting Algorithms
// This Program uses a class named AbstractSort as a framework
// for sorting algorithms that sort by comparing pairs of array entries.
// To obtain a concrete class for sorting, one first subclasses
// the AbstractSort class and then overrides the pure virtual function
// sort. The sort() function must call the compare(int, int) function
// to compare pairs of array entries.
 
#include <iostream>
#include <algorithm>
#include <cstdlib> // For random
using namespace std;

class AbstractSort
{
public:
    virtual void sort(int arr[ ], int size) = 0;    
    int getComparisonCount()
    {
        return comparisonCount;
    }
    void resetComparisonCount()
    {
        comparisonCount = 0;
    }
protected:  
    int compare(int x, int y);    
private:
    int comparisonCount;    
};

//******************************************************
//         AbstractSort::compare                       *
//   Returns -1, 0, or 1 a la strcmp                   * 
// This also keeps track of the number of comparisons  *
// performed.                                          *
//******************************************************
int AbstractSort::compare(int x, int y)
{
    comparisonCount++;
    return x - y;
}

// Derived class
class MaxSort : public AbstractSort
{
public:
    void sort(int arr[ ], int size);
};

//************************************************************
//                MaxSort::sort                              *
// Sort the given array with the given number of elements.   *
//************************************************************
void MaxSort::sort(int arr[ ], int size)
{   
    resetComparisonCount();
    for (int k = size-1; k >= 1; k--)
    {
        // Arr[k+1..size-1] contains the biggest items in the array is sorted order
        // Find biggest item in arr[0..k] and move it to a[k]
        
        int indexOfLargest = 0;
        for (int ix = 1; ix <= k; ix++)
            if (compare(arr[ix], arr[indexOfLargest]) > 0)
                indexOfLargest = ix;
            
        swap(arr[indexOfLargest],  arr[k]);        
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
    cout << "How large do you want the array to be?";
    
    // Get the size of the array
    cin >> size;    
    if (size > MAX_SIZE) 
    {
        cout << "The size of the array must be no greater than 100.";
        exit(1);
    }
    
    // Initialize random number generator
    srand(time(0));
    
    // Fill the array with random numbers
    for (int k = 0; k < size; k++)
        arr[k] = rand() % 1000;
    
    // Output array to be sorted
    cout << "Array to be sorted is: \n";
    for (int k = 0; k < size; k++)
        cout << arr[k] << "  ";
    
    // Sort and output results
    MaxSort maxSort;
    maxSort.sort(arr, size);
    cout << "\nThe sorted array is: \n";
    for (int k = 0; k < size; k++)
        cout << arr[k] << "  ";
    cout << "\nNumber of comparisons performed is: " << maxSort.getComparisonCount();
    
    return 0;    
}



