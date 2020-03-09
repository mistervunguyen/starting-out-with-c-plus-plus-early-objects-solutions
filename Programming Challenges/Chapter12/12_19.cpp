// Chapter 12 - Assignment 19, String Splitter
// This program splits each sentence entered as a single line
// into its constituent words.

#include <string>
#include <vector>
#include <cctype>
#include <iostream>
using namespace std;

// Prototype for the string-splitting function
vector<string> split(string str);

// The function that splits strings can be in one of two states
// at any given time: it can be in the middle of a word, or it can be
// between words.
enum class State { IN_WORD, BETWEEN_WORDS };


int main()
{
   string input;
   while (true)
   {
      cout << "Enter a string to split and type ENTER, or just type ENTER to terminate:\n";

      // Read next string and break if the string is empty.
      getline(cin, input);
      if (input.length() == 0) { break; }

      // Split the string.
      vector<string> parts = split(input);

      // Output the result of the split.
      cout << "The words of the sentence are:\n";
      for (int k = 0; k < parts.size(); k++)
      {
         cout <<  parts[k] << endl;
      }
      cout << endl;
   }
   return 0;
}


//***********************************************************
//                     split                                *
// This function splits the string str into a sequence of   * 
// its constituent words stored in a vector.                *
//**********************************************************/
vector<string> split(string str)
{
   vector<string> parts;
   State state = State::BETWEEN_WORDS;
   string current_word = "";

   for (int k = 0; k < str.length(); k++)
   {
      char ch = str[k];
      switch (state)
      {
      case State::BETWEEN_WORDS:      
         if (isspace(ch))
         {
            // Stay in same state            
            continue;
         }
         // Nonspace means change state
         state = State::IN_WORD;
         // Store the nonspace character
         current_word += ch;
         continue;

         case State::IN_WORD:
            if (isspace(ch))
            {
               // End of word
               parts.push_back(current_word);
               current_word = "";
               state = State::BETWEEN_WORDS;
               continue;                
            }
            // Store nonspace character
            current_word += ch;
      }    
   }
   
   // Add the last word to the vector, unless it is empty.
   if (current_word.length() > 0)
   {
      parts.push_back(current_word);
   }
   return parts;   
}