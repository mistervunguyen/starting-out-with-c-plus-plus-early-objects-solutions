// Chapter  10 - Assignment 5,  Pie a la Mode
// This program computes the mode of an array of integers.

#include <iostream>
using namespace std;

double modeFunction(double a[ ], int numElements);  // Prototype

int main()
{
    int numElements;
    double *number;     // Pointer to array of numbers

    // Determine how many numbers there are
    cout << "This program computes the mode of a sequence of numbers.\n"
         << "How many numbers do you have?\n";
    cin >> numElements;

    // Allocate storage
    number = new double[numElements];
    // Read in the numbers
    cout << "Enter your sequence of numbers and I will tell you the mode: \n";
    for (int k = 0; k < numElements; k++)
        cin >> *(number + k);

    // Tell user the mode
    cout << "\nThe mode of the list \n";
    for (int j = 0; j < numElements;  j++)
        cout << number[j] << "  ";
    cout << "\nis " << modeFunction(number, numElements) << ".";
    return 0;
}

//********************************************************************
//                 indexOfMax                                        *
// This function  returns the index of a maximum entry in  an array  *
//********************************************************************
int indexOfMax(int a[ ], int numElements)
{
    int maxIndex = 0;
    for (int k = 1; k < numElements; k++)
    {
        if (a[k] > a[maxIndex])        
            maxIndex = k;
    }
    return maxIndex;
}

//**********************************************************************
//                    modeFunction                                     *
// This function computes the mode of an array.                        *
// The strategy is to compute the frequency with with each array entry * 
// occurs and store these frequencies in an auxiliary array freq.      *
// We can then pick an array entry with the largest frequency using    *
// the indexOfMax function.                                            *
//**********************************************************************
double modeFunction(double a[ ], int numElements)
{
    // Represent frequencies of individual array entries
    int *freq = new int[numElements]; 
    
    // Compute the frequencies
    for (int k = 0; k < numElements; k++)
    {
        // Set freq[k] to how often a[k] appears in the array
        // Freq[k] is same as *(freq + k)
        *(freq + k) = 0;
        for (int j = 0; j < numElements; j++)
            if (a[j] == a[k]) 
                *(freq + k) = *(freq + k) + 1;        
    }

    // Locate position of mode
    int modePosition = indexOfMax(freq, numElements);

    // Clean up and return mode
    delete [ ]freq;
    return a[modePosition];    
}
    