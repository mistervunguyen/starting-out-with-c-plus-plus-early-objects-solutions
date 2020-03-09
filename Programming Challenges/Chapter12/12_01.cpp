//  Chapter 12 --  Assignment 1, Word Counter
// This program takes a string and counts the number of words in 
// the string.

#include <iostream>
#include <cctype>
using namespace std;

// Function prototype
int wordCount(char *);

int main()
{
    // Buffer to hold the string
    const int LENGTH = 81;
    char string[LENGTH];

    // Get the string
    cout << "\nPlease enter a string of " 
         << LENGTH-1 << " or fewer characters:\n";
    cin.getline(string, LENGTH);

    // Count the number of words in the string and print
    cout << "\nThe number of words in that string:  ";
    cout << wordCount(string) << endl << endl;

    return 0;
}

//*********************************************
//           wordCount                        *
// Counts the numbers of words in a C-string. *
//*********************************************
int wordCount(char *str)
{
    int numWords = 0;

    while (*str != 0)
    {
        // Skip any leading spaces
        while (*str != 0 && isspace(*str))
           str++;
                   
        if (*str != 0)
           numWords++;

        // Find the end of the current word
        while (*str != 0 && !isspace(*str))
           str++;
    }
    return numWords;
}
