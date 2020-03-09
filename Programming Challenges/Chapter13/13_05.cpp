//  Chapter 13 --  Assignment 5, String Search
// This program searches for all occurrences of a given string
// within a file, and outputs the number of such occurrences.
 
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    const int LENGTH = LENGTH;
    ifstream file;
    char name[LENGTH], inputLine[LENGTH], search[LENGTH];
    int frequency = 0;  // How many times the string has been found

    // Get name of file, open the file, and check for success
    cout << "Enter the file name: ";
    cin.getline(name, LENGTH);
    file.open(name);
    if (!file)
    {
       cout << "Error opening " << name << endl;
       return 0;
    }

    // Get the string to search for
    cout << "Enter string to search for: ";
    cin.getline(search, LENGTH);

    // Do the search
    while (!file.eof())
    {
       file.getline(inputLine, LENGTH, '\n');
       if (strstr(inputLine, search) != 0)
       {
          cout << inputLine << endl;
          frequency++;
       }
    }
    file.close();
    cout << "\n\"" << search << "\" was found " << frequency << " times.\n";
    return 0;
}

