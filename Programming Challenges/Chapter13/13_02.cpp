//  Chapter 13 -- Assignment 2:  File Display Program
// This program displays a file, 24 lines at a time, on the screen.
#include <iostream>
#include <fstream>
using namespace std;
 
int main()
{
    // Variables needed
    const int LENGTH = 81;
    ifstream file;
    char name[LENGTH], inputLine[LENGTH];
    int lines = 0;

    // Get name of file, open file, and do a sanity check
    cout << "Enter the file name: ";
    cin.getline(name, LENGTH);
    file.open(name);
    if (!file)
    {
        cout << "Error opening " << name << endl;
        return 0;
    }

    // Read file and diplay line by line, pausing every 24 lines
    while (!file.eof())
    {
        file.getline(inputLine, LENGTH, '\n');
        cout << inputLine << endl;
        lines++;
        if (lines == 24)
        {
           cout << "Press ENTER to continue...";
           cin.get();
           lines = 0;
        }
    }  // While

    // Clean up and go home
    file.close();
    return 0;
}

