// Chapter 13, Assignment 12 Insertion Sort on File I
// Note that when opened for input and output, tellg and tellp both
// refer to the same position. Although we have used both tellg and tellp
// and both seekg and seekp, you only need to use one.

// When backing up in the file, use two variables readPos and writePos.
// The readPos variable in one integer closer to the beginning of the file
// than the writePos variable.

// Note: The input file must exist. You can start by creating an empty file.
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int main (int argc, char** argv)
{  
  streampos writePos, readPos;  // Read and write positions in a file
  string filename;
  int number;                   // Used to read an integer from user
  int numberAtReadPos;          // Number at current read position in the file
  cout << "Enter the name of the data file: " ;
  cin >> filename;  
  fstream dataFile(filename.data(), ios::binary|ios::in|ios::out|ios::ate);
  if (!dataFile)
  {
     cout << "Cannot open  the file " << filename;
     exit(1);
  }
  
  cout << "Enter an integer to store in the file: " ;  
  cin >> number;
  writePos = dataFile.tellp(); 
  if (writePos == 0)
    {
      // The file is empty, so write the number and close the file
      dataFile.write((char *)&number, sizeof(number));
      dataFile.close();
      return 0;      
    }
  // Output the contents of the file
  dataFile.seekg(0, ios::beg);
  cout << "The current contents of the file are: " << endl;
  while (dataFile.read((char *)&numberAtReadPos, sizeof(int)))
    {
      cout << numberAtReadPos << "  ";
    }
  cout << endl;
  
  // Now we are at the end of the file on input
  // clear flags so we can continue using the file
  dataFile.clear();
  // Seek to the end of the file on output 
  dataFile.seekp(0, ios::end);
  
  writePos = dataFile.tellp();
  readPos = dataFile.tellg();
 
  // Back up by one integer and read the last integer in the file
  dataFile.clear();
  dataFile.seekg(static_cast<long>(-sizeof(int)), ios::end);
  readPos = dataFile.tellg();
  
  while (readPos >= 0)
  {
        // Read the number at the current read position
        dataFile.seekg(readPos);
        dataFile.read((char *)&numberAtReadPos, sizeof(int));
      
        if (numberAtReadPos <= number) break;        
        // The new number goes closer to the beginning of the file, 
        // so move number at current read position one step toward end of file
        // and adjust the position where the new number should be written
        dataFile.seekp(writePos);
        dataFile.write((char *)&numberAtReadPos, sizeof(int));
        readPos -= sizeof(int);
        writePos -= sizeof(int);       
  }
  // found where the new number goes 
  dataFile.seekp(writePos);
  dataFile.write((char *)&number, sizeof(int));
  // close file
  dataFile.close();  
  
  return 0;
}

