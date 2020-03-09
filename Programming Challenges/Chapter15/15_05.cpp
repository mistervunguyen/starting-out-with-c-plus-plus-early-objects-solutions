// Chapter 15 - Assignment 5, File Filter
// This program implements an object-oriented file filter.
// Different types of file filters can be obtained
// by providing different overrides of the transform()
// member function.
// This program implements conversion-to-uppercase filter.
 
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

// This is the abstract Filter class.
// Concrete derived classes will override the transform 
// member function.
class Filter
{
public:
    void doFilter(fstream &in, fstream &out);
protected:
    virtual char transform(char ch) = 0;
};

//**********************************
//           Filter::doFilter      *
//    Performs actual filtering.   *
//**********************************
void Filter::doFilter(fstream &in, fstream &out)
{
    char ch = in.get();
    while (ch != EOF)
    {
        out.put(transform(ch));
        ch = in.get();
    }
}

// Uppercase subclass filter class
class UpperCaseFilter: public Filter
{
protected:
    char transform(char ch)
    {
        return toupper(ch);
    }    
};

void printFile(fstream &); // Prototype

int main( )
{
    // Explain the program
    cout << "This program creates an uppercase version of a file of text." << endl;

    // Get name of input file
    cout << "Enter name of input file (input.txt): ";
    string inFileName;
    cin >> inFileName;
    fstream inputFile(inFileName.data(), ios::in);
    if (!inputFile)
    {
        cout << "The file " << inFileName << " cannot be opened." << endl;
        exit(1);
    }

    // Echo the input file
    cout << "\nOriginal file is: " << endl;
    printFile(inputFile);
    cout << endl;

    // Get name of output file
    cout << "Enter name of output file (output.txt): ";
    string outFileName;
    cin >> outFileName;

    // Open the output file
    fstream outputFile(outFileName.data(), ios::out);
    if (!outputFile)
    {
        cout << "The file " << outFileName << " cannot be opened." << endl;
        exit(1);
    }
    
    // Process 
    UpperCaseFilter upperFilter;
    upperFilter.doFilter(inputFile, outputFile);

    // Close output file and reopen for  reading so we can  print
    outputFile.clear();
    outputFile.close();
    outputFile.open(outFileName.data(), ios::in);
    cout << "\nFiltered file is: " << endl;
    printFile(outputFile);

    // Close all files
    inputFile.close();
    outputFile.close();
    return 0;    
}    

//********************
//    printFile      *
//   Print file.     *
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



    
    

