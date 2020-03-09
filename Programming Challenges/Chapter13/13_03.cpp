// Chapter 13 - Assignment 3, Punch Line
// This program reads a joke from one text file and its punchline
// from another file. It allows the student to practice working with
// text files.
 
#include <fstream>
#include <iostream>
using namespace std;

// Function prototypes
void displayAllLines(ifstream &infile);
void displayLastLine(ifstream &infile);  

int main()
{
   // Names of files, and file stream objects
   string fileName1, fileName2;          
   ifstream jokeFile,  punchlineFile;
          
   //Explain program to user
   cout << "This program will print a joke and its punch line.\n\n";

   //Get the file names from the user
   cout << "Enter the name of the file holding the joke (joke.txt): ";
   cin  >> fileName1;
   
   cout << "Enter name of file holding the punch line (punchline.txt): ";
   cin  >> fileName2;
   
   //Open the files
   jokeFile.open(fileName1.data());  
   if (!jokeFile)
   {
      cout << "The file " << fileName1 << " could not be opened.";
      exit(0);
   }
   
   punchlineFile.open(fileName2.data());  
   if (!punchlineFile)
   {
       cout << "The file " << fileName2 << " could not be opened.";
       exit(0);
   }	
   cout << endl << endl; 

   // Call displayAllLines to display contents of the joke file
   displayAllLines(jokeFile);
   
   // Call displayLastLine to display the last line in the punch line file
   displayLastLine(punchlineFile); 
   cout << endl;   
   
   // Close the files
   jokeFile.close();
   punchlineFile.close();
	
   return 0;
}

//*****************************************************************
//                       displayAllLines                          *
// Reads and displays all lines in the text file whose ifstream   *
// variable is passed to the function.                            *
//*****************************************************************
void displayAllLines(ifstream &infile)
{
   string line;
   
   infile.seekg(0, ios::beg);      // Just to make sure we're at
                                   // the beginning of the file
   
   while (getline(infile, line))   // While a line was successfully read in
      cout << line << endl;        // display it on the screen
}
   
//*****************************************************************
//                     displayLastLine                            *
// Displays the final line in a file. It finds it by going to the *
// end of the file and then backing up a character at a time until*
// it reaches the beginning of the last line.                     *
//*****************************************************************
void displayLastLine(ifstream &infile)
{
	char ch;
   string line;
   bool foundLastLine = false;
	    
   // Find the beginning of the last line
   
   infile.clear();                  // Do this just in case we are 
                                    // already at end of file
   infile.seekg(0, ios::end);       // Go to the end of the file
   
   infile.seekg(-1, ios::cur);      // Move backwards to beginning of the
   ch = infile.get();               // final char in the file and read it in
  
   while (infile && !foundLastLine)  // While it successfully read in
   {                                 // a char and has not previously found
                                     // the last line, test what was read.
      if (ch != '\n')                // If the char just read is NOT an 
      {  infile.seekg(-2, ios::cur); // endline, back up 2 more characters -- 
         ch = infile.get();          // 1 to skip the char just read and 
      }                              // one more to move to just before the
                                     // previous char so we can read it next.
      else                           // else
         foundLastLine = true;       // It found the endline at the end of the
                                     // next to last line, so we are where we
                                     // want to be. The next char begins the
                                     // final line.
   }
   // Read final line and display it
   getline(infile, line);
   cout << line;
}
