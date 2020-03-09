//        Chapter 12 -- Assignment 7,  Most Frequent Character.
//  This program determines the character that appears with the 
//  the highest frequency in a string.

#include <iostream>
#include <string>
using namespace std;

// Prototype 
char getMostFrequentChar(string str);

int main()
{
   // Get the string
   cout << "Enter a string : ";
   string str;     
   getline(cin, str);
   
   // Get the required information   
   char mostFrequentChar;
   mostFrequentChar = getMostFrequentChar(str);
   
   // Print out the information
   cout << "The most frequent char in this string is "
        << mostFrequentChar << endl;
   
   return 0;    
}

//**********************************************************************
//              getMostFrequentChar                                    *
//     Returns the character that occurs most frequently in a string.  *
//**********************************************************************   
char getMostFrequentChar(string str)
{
  // Array to keep track of how many times each character
  // has been seen.  The array is indexed by characters, or 
  // more accurately, it is indexed by the ASCII code of the 
  // the characters
  int charFreq[128];
  
  // Initialize the array of frequencies
  for (int k = 0; k < 128; k++)
      charFreq[k] = 0;
  
  // Record how many times each character appears
  for (int k = 0; k < str.length(); k++)
      charFreq[str[k]]++;
  
  // Now find the character that occurs with the highest frequency 
  char mostFrequentChar = 0;
  for (int ch = 1; ch < 128; ch++)
  {
      if (charFreq[ch] > charFreq[mostFrequentChar])
          mostFrequentChar = ch;
  }
  
  return mostFrequentChar; 
}

