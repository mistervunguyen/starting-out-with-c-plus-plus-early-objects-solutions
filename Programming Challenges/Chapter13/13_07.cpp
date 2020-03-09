//  Chapter 13 --  Assignment 7:  File Encryption Filter
// This program uses a simple encryption algorithm to encrypt a file.
 
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Various variables
    const int LEN = 81;
    ifstream inFile;
    ofstream outFile;
    char inName[LEN], outName[LEN], input;

    // Get name of  input file from user, open, and check for success
    cout << "Enter the input file name: ";
    cin.getline(inName, LEN);
    inFile.open(inName);
    if (!inFile)
    {
        cout << "Error opening " << outName << endl;
        return 0;
    }

    // Get name of output file from user, open it, and check for success
    cout << "Enter the output file name: ";
    cin.getline(outName, LEN);
    outFile.open(outName);
    if (!outFile)
    {
        cout << "Error opening " << outName << endl;
        return 0;
    }
    
    // Perform the encryption
    while (!inFile.eof())
    {
       inFile.get(input);
       // Encrypt the character by adding 10 to it.
       input += 10;
       outFile.put(input);
    }
    
    // We are done
    cout << "The file has been encrypted.\n";
    inFile.close();
    outFile.close();

    return 0;
}

