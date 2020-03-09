// Chapter 12, Assignment 15, Word Separator
#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Prototype for function that does all the work
string split(string);
int main( )
{
    cout << split("StopAndSmellTheRoses.");
    return 0;
}

/*********************************************
 *              split                        *
 *********************************************/
string split(string str)
{
   string result;
   // Copy the current string into the result
   // string, inserting a space before each
   // uppercase character except the first
   if (str.length()==0) return result;
   
   result += str[0];
   for (int k = 1; k < str.length(); k++)
   {
       // Copy the next character
       char ch = str[k];
       if (isupper(ch))
       {
           result += ' ';
           ch = tolower(ch);
       }
       result += ch;
   }
   return result;
} 

