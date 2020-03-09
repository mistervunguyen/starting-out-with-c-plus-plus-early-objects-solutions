// Chapter  13 - Assignment 6, Sentence Filter
// This program allows the user to transform an 
// input file into an output file by executing a 
// transformation on each character of the input file.
 
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

void process(fstream &in, fstream & out);  // Prototype
void printFile(fstream &); // Prototype

int main()
{
    // Tell user what the program does
    cout << "This program capitalizes letters at beginning of sentences. " << endl;
    cout << "The program also makes lowercase all other letters. " << endl;
    cout << "Contents come from a file and are written to a second file." << endl;

    // Get name of files from user
    cout << "Enter name of input file (input.txt): ";
    string inFileName;
    cin >> inFileName;
    fstream inputFile(inFileName.data(), ios::in);
    if (!inputFile)
    {
        cout << "The file " << inFileName << " cannot be opened." << endl;
        exit(1);
    }

    // Echo input file
    printFile(inputFile);
    cout << endl;
    cout << "Enter name of output file (output.txt): ";
    string outFileName;
    cin >> outFileName;
    fstream outputFile(outFileName.data(), ios::out);
    if (!outputFile)
    {
        cout << "The file " << outFileName << " cannot be opened." << endl;
        exit(1);
    }           

    // Call the process function to do the actual filtering
    process(inputFile, outputFile);  
        
    // Close the output file and reopen for reading so we can print it
    outputFile.close();
    outputFile.open(outFileName.data(), ios::in);

    // Print filtered file
    cout << endl;
    cout << "Here is the filtered  file:" << endl;
    printFile(outputFile);

    // Close both files
    inputFile.close();
    outputFile.close();
}        


//***************************************************************************
//                    process                                               *
// Filters from in to out by capitalizing first letter of each sentence     *
// and lowercasing all other letters.                                       *
//***************************************************************************
void process(fstream &in, fstream &out)
{
    enum STATE {LOWER, UPPER}; // Lower case or upper case
    STATE state = UPPER;       // Keep track of whether we should up or down the case
    char ch = in.get();        // Current character

    while (ch != EOF)
    {
        switch(state)
        {
        case UPPER: 
            if (!isspace(ch))
            {
                ch = toupper(ch);
                state = LOWER;
            }
            break;            
        case LOWER:
            if (ch == '.')
                state = UPPER;
            ch = tolower(ch);
            break;            
        }
        out.put(ch); 
        ch = in.get();    
    }    
}

//********************
//     printFile     *
// Print file.       *
//********************
void printFile(fstream &file)
{
   // Start at beginning of file
   file.clear(); 
   file.seekg(0, ios::beg);

   // Print the file contents
   char ch = file.get();
   while (ch != EOF)
   {
      cout << ch;
      ch = file.get();
   }
   
   // Go back to beginning of file for further processing
   file.clear();
   file.seekg(0, ios::beg);
}


