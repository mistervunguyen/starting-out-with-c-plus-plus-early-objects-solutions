// Chapter 13 - Assignment 1, File Previewer
// This program allows a user to ``preview" a file by looking at the 
// the first 10 lines of the file.
 
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    const int  NUM_LINES = 10;

    // Explain program to user
    cout << "This program prints the first " 
         << NUM_LINES << " lines of a file you select.\n";

    // Get Name of file from user
    cout << "Enter Name of file (joke.txt): ";
    string fileName;
    cin >> fileName;

    // Open the file for input
    ifstream inputFile(fileName.data());
    if (!inputFile)
    {
        cout << "The file " << fileName << " could not be opened.";
        exit(1);
    }

    // Read and print the first 10 lines, or until end of file
    int numberLinesProcessed = 0;
    string line;
    while (getline(inputFile, line))
    {
        cout << line << endl;
        numberLinesProcessed ++;
        if (numberLinesProcessed == NUM_LINES)
            exit(0);
    }
    cout << "The entire file has been displayed.";    

    return 0;
}