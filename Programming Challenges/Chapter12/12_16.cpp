// Chapter 12: Assignment 16, Pig Latin
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
int main (int argc, char** argv)
{
  // function prototype
  string getWordAy(string w);
  
  // String to simulate an input file
  istringstream input("I SLEPT MOST OF THE NIGHT");
  
  string word;  
  while (input >> word)
    {
      // input operation was successful, so transform and output the word read
      cout << getWordAy(word) << " ";     
    }  
  return 0;
}

//******************************************
// Convenience function for the pig latin  * 
// transformation of a single word.        *
// *****************************************
string getWordAy(string w)
{
  return w.substr(1, w.length()) + w[0] + "AY";
}

