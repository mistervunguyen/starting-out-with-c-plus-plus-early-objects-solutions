// Chapter 13 -- Assignment 8, File Decryption Filter
// This program decrypts the file encrypted by the program of 
// assignment 7.

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
   // Variables
   const int LEN = 81;
   ifstream inFile;
   ofstream outFile;
   char inName[LEN], outName[LEN], input;

   // Get and open input file
   cout << "Enter the input file name: ";
   cin.getline(inName, LEN);
   inFile.open(inName);
   if (!inFile)
   {
        cout << "Error opening " << outName << endl;
        return 0;
   }

   // Get and open output file
   cout << "Enter the output file name: ";
   cin.getline(outName, LEN);
   outFile.open(outName);
   if (!outFile)
   {
        cout << "Error opening " << outName << endl;
        return 0;
   }

   // Perform the decryption
   while (!inFile.eof())
   {
        inFile.get(input);
        // Decrypt the character by subtracting 10 from it.
        input -= 10;
        outFile.put(input);
   }

   // We are done
   cout << "The file has been decrypted.\n";
   inFile.close();
   outFile.close();

   return 0;
}

