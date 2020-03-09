//        Chapter 12 -- Assignment 8,  Replace Substring Function.
//  This program takes three strings as parameter, and replaces every
//  occurrence of the second string in the first string with a copy
//  of the third string.

#include <iostream>
#include <string>
using namespace std;

// Prototype 
void replaceSubstring(string &str, string replacee, string s);

int main()
{
   // Get the string
   cout << "Enter the main string : ";
   string str;     
   getline(cin, str);
   
   // Get the replacee
   cout << "Enter the substring to be replaced: ";
   string replacee;
   getline(cin, replacee);
   
   // Get the new replacement
   cout << "Enter the string that will replace " << replacee << " :";
   string s;
   getline(cin, s);
   
   // Do the replacement
   replaceSubstring(str, replacee, s);

   // Print out the information
   cout << "The new string is : " << str << endl;
   
   return 0;    
}

//*************************************************************************
//              replaceSubstring                                          *
//    Replaces every copy of the second string with a copy of the third.  *
//*************************************************************************   
void replaceSubstring(string &str, string replacee, string s)
{
    // Determine length of replacee
    int nCharsToReplace = replacee.length();
    
    // Find position of replacee in str
    unsigned pos  = str.find(replacee, 0);    

    // str.find() returns string::npos if not found.
    while (pos !=  string::npos)
    {
        // Erase the appropriate number of characters at that position
        str.replace(pos, nCharsToReplace, s);                
       
        // Find position of next occurrence of replacee in str
        pos = str.find(replacee, pos);            
    }    
}