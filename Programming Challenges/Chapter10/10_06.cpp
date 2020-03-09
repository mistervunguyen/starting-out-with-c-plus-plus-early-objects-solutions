//  Chapter 10--  Assignment 6,  Median Function
// This program computes the median of an array of numbers.

#include <iostream>
using namespace std;

double median(int *, int);
void printArray(int *, int);

int main()
{
   int odd[] = {1, 2, 3, 4, 5, 6, 7};     // Array with odd number of values
   int even[] = {1, 2, 3, 4, 5, 6, 7, 8}; // Array with even number of values

   // Compute and print median for odd-sized array
   cout << "\nMedian of the array :  ";
   printArray(odd, 7);
   cout << "is " << median(odd, 7) << endl;

   // Compute and print median for even-sized array
   cout << "Median of the array : ";
   printArray(even, 8);
   cout << "is " << median(even, 8) << endl << endl;
   return 0;
}

/*************************************************
*               median                           *
* Compute median of an array arr of num entries. *
*************************************************/
double median(int *arr, int num)
{
    double med;

    if (num % 2 == 0)    // Is number of elements even?
    {
       int mid1 = num / 2, mid2 = (num / 2) - 1;
       med = ((*(arr + mid1) + *(arr + mid2)) / 2.0);
    }
    else
       med = *(arr + (num / 2));
    return med;
}

/*****************************
*      printArray            *
* Print an array.            *
*****************************/
void printArray(int *p, int size)
{
  cout << endl;
  for (int k = 0; k < size; k++)
    cout << p[k] << "  ";
  cout << endl;
}


