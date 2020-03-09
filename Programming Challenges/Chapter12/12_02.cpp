//  Chapter 12--  Assignment 2: Average Number of Letters
// This program computes the average number of letters in a word in a string

#include <iostream>
#include <cctype>
using namespace std;

void  countWordsAndLetters(char *, int &, int&);

int main()
{
    // Create buffer to hold the string
    const int LENGTH = 81;
    char string[LENGTH];

    // Read the string
    cout << "\nPlease enter a string of " 
         << LENGTH-1 << " or fewer characters:\n";
    cin.getline(string, LENGTH);

    // Compute and print average number of letters per word
    double average;
    int totalWords, totalLetters;
    
    countWordsAndLetters(string, totalLetters, totalWords) ;
    cout << "\nWord Count: " << totalWords;    
    cout << "\nAverage number of letters per word: " 
         << totalLetters/double(totalWords)<< endl << endl;

    return 0;
}

/**********************************************************************
*               countWordsAndLetters                                  *
* Determine number of words and number of letters in the string.      *
***********************************************************************/
void countWordsAndLetters(char *str, int &totalLetters, int &totalWords)
{
   totalWords = 0, totalLetters = 0;

   while (*str != 0)
   {
      // Find beginning of next word
      while (*str != 0 && isspace(*str))
         str++;

      // Increment the word count
      if (*str != 0)
         totalWords++;

      // Go to the end of this word
      // while counting the letters in it
      while (*str != 0 && !isspace(*str))
      {
         totalLetters++;
         str++;
      }
   }  
}
