// Chapter 18, Assignment 12 Stack-Based Binary Search
#include <cstdlib>
#include <iostream>
#include <stack>
#include <cstdlib>
#include <algorithm>
#include <ctime>

using namespace std;

class Range
{
public:
  int lower, upper;
  Range(int l, int u){ lower = l; upper = u;}
};


int bSearch(int arr[], int size, int X);
int main (int argc, char** argv)
{
  // Create an array of 10 random integers
  int arr[10];
  int size = sizeof(arr)/sizeof(arr[0]);
  srand(time(NULL));
  for (int k = 0; k < size ; k++)
  {
      arr[k] = rand() % 100 + 1;     
  }
  // Sort the array
  sort(arr, arr + size);
  
  // Display the array
  for (int k = 0; k < size; k++)
  {
     cout << arr[k] << "  ";
  }
  cout << endl;
  
  // Allow user to test the search function
  while (true)
  {
      int X;
      cout << "Enter a nonnegative number to search for, -1 to quit: ";
      cin >> X;
      if (X == -1) return 0;
      int result = bSearch(arr, size, X);
      if (result == -1)
        cout << X <<  " Not found." << endl;
      else
        cout << X << " is found at position " << result << endl;
  }
  return 0;
}

//****************************************************
// Uses a stack-based binary search to search for    *
// an integer X in an array arr of a given size.     *
// Return -1 if X is not found, index of X otherwise *
//****************************************************
int bSearch(int arr[] , int size, int X)
{
  if (size <= 0) return -1;
  
  stack<Range> rangeStack;
  
  rangeStack.push(Range(0, size-1));
  while (!rangeStack.empty())
    {
      Range currentRange = rangeStack.top();
      rangeStack.pop();
      int mid = (currentRange.lower + currentRange.upper)/2;
      if (arr[mid] == X) return mid;
      if (arr[mid] > X)
        {
          if (currentRange.lower <= mid -1)
              rangeStack.push(Range(currentRange.lower, mid-1));
        }
      else
        {
          if (mid+1 <= currentRange.upper)
              rangeStack.push(Range(mid+1, currentRange.upper));
        }
    }
  return -1;
}

