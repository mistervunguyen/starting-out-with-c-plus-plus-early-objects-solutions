// Chapter 13, Assignment 10 Put it Back
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <fstream>
using namespace std;

int  main (int argc, char** argv)
{
  char ch;       // Used to read one character at a time
  int number;    // Used to read an integer from the input stream
  int numberCount = 0;  // How many number seen in the input stream
  
  // istringstream input("This is 12 of the finest 53 people you ever saw.");
  string filename;
  cout << "Enter the name of a text file that has some numbers: ";
  cin >> filename;
  ifstream input(filename.data());
  if (!input)
    {
      cout << "Could not open the file " << filename;
      exit(1);
    }
  ch = input.get();
  while (ch != EOF)
    {
      // If the character is a digit, put it back and read the number
      if (isdigit(ch))
        {
          input.putback (ch);
          input >> number;
          numberCount ++;
        }
      // Read the next character
      ch = input.get();      
    }
  // Output the count of the count of numbers in the input stream
  cout << "There are " << numberCount << " numbers in the input stream" << endl;
  return 0;
}

