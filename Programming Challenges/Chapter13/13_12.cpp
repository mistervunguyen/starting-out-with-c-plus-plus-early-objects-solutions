// Chapter 13, Assignment 12.
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
#include <cstring>
#include <cstdlib>

using namespace std;

// Definition of Record structure that holds
// a person's information.
const int NAME_LEN = 10;
struct PersonRecord
{
  char name[NAME_LEN];
  int age;
};

int main (int argc, char** argv)
{  
  streampos writePos, readPos;  // Read and write positions in a file
  string filename;
  PersonRecord  record;         // Used to read record information from user
  PersonRecord recordAtReadPos; // Record at current read position in the file
  cout << "Enter the name of the data file: " ;
  cin >> filename;  
  fstream dataFile(filename.data(), ios::binary|ios::in|ios::out|ios::ate);
  if (!dataFile)
  {
     cout << "Cannot open  the file " << filename;
     exit(1);
  }
  
  cout << "Enter a name and age to store in the file: " ;  
  cin >> record.name >> record.age;
  writePos = dataFile.tellp(); 
  if (writePos == 0)
    {
      // The file is empty, so write the record and close the file
      dataFile.write((char *)&record, sizeof(PersonRecord));
      dataFile.close();
      return 0;      
    }
  // Output the contents of the file
  dataFile.seekg(0, ios::beg);
  cout << "The current contents of the file are: " << endl;
  while (dataFile.read((char *)&recordAtReadPos, sizeof(PersonRecord)))
    {
      cout << recordAtReadPos.name << "  " << recordAtReadPos.age << endl;
    }
  cout << endl;
  
  // Now we are at the end of the file on input
  // clear flags so we can continue using the file
  dataFile.clear();
  // Seek to the end of the file on output 
  dataFile.seekp(0, ios::end);
  
  writePos = dataFile.tellp();
  readPos = dataFile.tellg();
 
  // Back up by one record and read the last record in the file
  dataFile.clear();
  dataFile.seekg(static_cast<long>(-sizeof(PersonRecord)), ios::end);
  readPos = dataFile.tellg();
  
  while (readPos >= 0)
  {
        // Read the record at the current read position
        dataFile.seekg(readPos);
        dataFile.read((char *)&recordAtReadPos, sizeof(PersonRecord));
      
        if (strcmp(recordAtReadPos.name, record.name) <= 0) break;        
        // The new record goes closer to the beginning of the file, 
        // so move record at current read position one step toward end of file
        // and adjust the position where the new record should be written
        dataFile.seekp(writePos);
        dataFile.write((char *)&recordAtReadPos, sizeof(PersonRecord));
        readPos -= sizeof(PersonRecord);
        writePos -= sizeof(PersonRecord);       
  }
  // found where the new record goes 
  dataFile.seekp(writePos);
  dataFile.write((char *)&record, sizeof(PersonRecord));
  // close file
  dataFile.close();  
  
  return 0;
}

