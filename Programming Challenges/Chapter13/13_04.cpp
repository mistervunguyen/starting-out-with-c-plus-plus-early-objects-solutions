// Chapter 13 - Assignment 4, Tail of File
// This program allows a user to look at the last  10 lines
// of a text file.
 
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void backupLines(ifstream &in, int lines);  // Prototype

int main()
{
    // Explain program to user
    cout << "This program will print the last 10 lines in a file.\n"

    // Get name of file from user
    string fileName;
    cout << "Enter name of file: ";
    cin >> fileName;

    // Open the file
    ifstream inputFile(fileName.data());
    if (!inputFile)
    {
        cout << "The file " << fileName << " could not be opened.";
        exit(0);
    }

    // Go to the end of the file
    inputFile.seekg(0, ios::end);

    // Back up 10 lines, or till at beginning
    backupLines(inputFile, 10);
   
    // Read and print lines till end of file
    string line;   
    while (getline(inputFile, line))
         cout << line << endl;

    return 0;
}

// *****************************************************************
//                      bakupLines                                 *
//     backup the given number of lines from the current position  *  
// *****************************************************************

void backupLines(ifstream &in, int lines)
{
   char ch;
   in.clear(); // Just in case we are at end of file 
   in.seekg(-1, ios::cur);
   while (true)
   {
     // Are we already at beginning?     
     long pos = in.tellg();
     if (pos == 0) return;            
   
     // What character did we back up over?
     ch = in.get();
     if (ch == '\n') lines--;

     // Reading the character undid the backing up
     in.clear();
     in.seekg(pos-2, ios::beg);
     if (lines == 0) return;       
   }
}