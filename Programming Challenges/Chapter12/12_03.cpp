// Chapter  12 - Assignment 3, Sentence Capitalizer
// This program accepts a string that is a collection of 
// Sentences and capitalizes the first letter of each sentence.

#include <cstdlib>
#include <iostream>
#include <cctype>
using namespace std;


void capitalize(char *s);  // Prototype

int main()
{
     // Buffer to hold the string    
     const int LENGTH = 81;
     char str[LENGTH];
     char ch;                     // Used to read string one character at a time

     // Explain use of program
     cout << "This program capitalizes first letter of each sentence in a string.";
     cout << "\nSentences end with a period.\n";

     // Read the string one character at a time
     cout << "Enter a string containing some sentences: ";
     ch = cin.get();
     int k = 0;
     while (ch != '\n')
     {
         str[k] = ch;
         if (k == LENGTH -2) { k++; break; }
         k++;
         ch = cin.get();
     }

     // Insert null terminator
     str[k] = 0;
     
     // Pass string to the function
     capitalize(str);

     // Print modified string
     cout << "The modified string is:\n " << str;

     return 0;
}

//****************************************************************
//                        capitalize                             *
// Capitalizes first letter of each word that begins a sentence. *
//****************************************************************

void capitalize(char *s)
{
    enum State {CAP, NO_CAP}; // Capitalize, Do not capitalize
    State state = CAP;
    while(*s)
    {
        // Not yet at end of string.
        // Switch statement checks if we should capitalize current character
        switch(state)
        {
        case CAP: 
            // Find the first non space character and capitalize it
            while (isspace(*s) && *s != 0)
                s++;
            if (*s == 0) return;  // End of string	

            // Capitalize the character		
            *s = toupper(*s);   
      
            // Do not capitalize next character
            state = NO_CAP;
            break;
        case NO_CAP:
            // If current character is . then next  nonblank character 
            // Will be capitalized
            if (*s == '.')
                state = CAP;            
            break;            
        }
        // Go to next character in string
        s++;        
    }    
}