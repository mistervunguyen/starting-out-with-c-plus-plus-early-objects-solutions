// Chapter 12, Assignment 17,  I before e except after c.

// The part that implements the strstr version of the solution
// is commented out.
#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>
#include <cstring>

using namespace std;

// Prototypes
bool caseInsensitiveFind(string str, string patter); 
bool cStringCaseInsensitiveFind(string str, string pattern);
string toLowerCase(string);

int  main (int argc, char** argv)
{
  
  istringstream input
  (
    "A friend of yours receives  a report about her husband that might be a lie."
    "\nShould she believe it immediately or seek to tie loose ends together."
  );  
  
  string word;
  while (input >> word)
    {     
      if (caseInsensitiveFind(word, "ie") || caseInsensitiveFind(word, "ei"))
        cout << word << " ";   
      
      /* CString version
      if (cStringCaseInsensitiveFind(word, "ie") || cStringCaseInsensitiveFind(word, "ei"))
        cout << word << " ";  
      */ 
    }
  
  return 0;
}

//******************************************
// Computes and returns lower case version *
// of a string.                            *
//******************************************
string toLowerCase(string str)
{
  string result;
  for (int k = 0; k < str.length(); k++)
    result += tolower(str[k]);
  return result;
}

//**********************************************
// Checks if str contains an an instance of    *
// the string pattern in any case              *
//**********************************************
bool caseInsensitiveFind(string str, string pattern)
{
  // convert both to lower case
  str = toLowerCase(str);
  pattern = toLowerCase(pattern);
  return str.find(pattern, 0) != string::npos; 
}

//******************************************************
// Cstring version of the caseInsensitiveFind function *
//******************************************************
bool cStringCaseInsensitiveFind(string str, string pattern)
{
    // convert both to lower case
    str = toLowerCase(str);
    pattern = toLowerCase(pattern);
    return strstr(str.c_str(), pattern.c_str());  
}



