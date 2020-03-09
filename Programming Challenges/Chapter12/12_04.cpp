//  Chapter 12 -- Assignment 4: Vowels and Consonants 
// This program counts the number of vowels and consonants appearing in 
// a string.

#include <iostream>
#include <cctype>
using namespace std;

// Function prototypes
int vowels(char *);
int consonants(char *);

//*********************************************************
//               main                                     *
// Assumes that the string contains no characters other   *
// than consonants and vowels.                            *
//*********************************************************
int main()
{
   // Buffer to hold input string
   const int BUFFER_SIZE = 81;
   char choice, string[BUFFER_SIZE];

   // Get input string from user
   cout << "Enter a string: ";
   cin.getline(string, BUFFER_SIZE);

   // Display menu of choices and process the user's choice
   do
   {
      cout << "\tA) Count the vowels in the string\n";
      cout << "\tB) Count the consonants in the string\n";
      cout << "\tC) Count both vowels and consonants\n";
      cout << "\tD) Enter another string\n";
      cout << "\tE) Exit this program\n\n";
      do
      {
         cin >> choice;
         if (toupper(choice) < 'A' || toupper(choice) > 'E')
             cout << "\tEnter A, B, C, D, or E.\n";
      } while (toupper(choice) < 'A' || toupper(choice) > 'E');
      switch (toupper(choice))
      {
          case 'A':    
                   cout << "The string has ";
                   cout << vowels(string) << " vowels.\n\n";
                   break;
          case 'B': 
                   cout << "The string has ";
                   cout << consonants(string) << " consonants.\n\n";
                   break;
          case 'C': 
                   cout << "The string has ";
                   cout << vowels(string) << " vowels and ";
                   cout << consonants(string) << " consonants.\n\n";
                   break;
          case 'D':   
                   cin.get();
                   cout << "Enter a string: ";
                   cin.getline(string, 81);
                   break;
          case 'E':    
                   return 0;
      }
   } while (toupper(choice) != 'E');
   return 0;
}

//***********************************************************************
//                  vowels                                              *
// The following function accepts a pointer to a string                 *
// As its argument. It returns the number of vowels in the string.      *
//***********************************************************************
int vowels(char *str)
{
    char v[] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};
    int numVowels = 0;

    while (*str != 0)
    {
        for (int count = 0; count < 10; count++)
        {
            if (*str == v[count])
            {
               numVowels++;
               break;
            }
        }
        str++;
   }
   return numVowels;   
}

//*******************************************************************
//                      consonants                                  *
// This function accepts a pointer to a string  as its  argument.   *
// It returns the number of consonants in the string.               *
//*******************************************************************
int consonants(char *str)
{
    char v[] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};
    int numCons = 0;
    bool isVowel;

    while (*str != 0)
    {
        // Check if the current character is a consonant and 
        // increment number of consonants if so
        isVowel = false;
        for (int count = 0; count < 10; count++)
        {
           if (*str == v[count])
           {
              isVowel = true;
              break;
          }
        }
        if (!isVowel)
            numCons++;
        str++;
    }
    return numCons;
}

