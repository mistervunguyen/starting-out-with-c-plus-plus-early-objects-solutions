// Chapter 15- Assignment 4, Flexible Encryption
// This program implements a flexible form of encryption.
// The flexibility is due to the encryption key.
#include <iostream>
#include <fstream>
using namespace std;
 
// This is the abstract encryption class
class Encryption
{
 protected:
   ifstream inFile;     
   ofstream outFile;
   int key;
 public:
   Encryption(char *inFileName, char *outFileName);
   ~Encryption();
   // Pure virtual function
   virtual char transform(char ch) = 0;
   // Do the actual work
   void encrypt();
   void setKey(int key){ this->key = key;}
};

//***************************************************
//              Constructor                         *
// Constructor opens the input and output file.     *
//***************************************************
Encryption::Encryption(char *inFileName, char *outFileName)
{
   inFile.open(inFileName);
   outFile.open(outFileName);
   if (!inFile) 
     {
       cout <<  "The file " << inFileName << " cannot be opened.";
       exit(1);
     }
   if (!outFile)
    {
      cout << "The file " << outFileName << " cannot be opened.";
      exit(1);
    }
}

//***************************************************
//                Destructor                        *
//           Destructor closes files.               *
//***************************************************
Encryption::~Encryption()
{
   inFile.close();
   outFile.close(); 
}

//******************************************************
//              Encrypt::encrypt                       *
// Encrypt function uses the virtual transform         *
// Member function to transform individual characters. *
//****************************************************** 
void Encryption::encrypt()
{
  char ch;
  char transCh;

  // Read the input file and write the encrypted form to
  // the output file
  inFile.get(ch);
  while (!inFile.fail())
    {
      transCh = transform(ch);
      outFile.put(transCh);
      inFile.get(ch);
    }
}

// The subclass simply overides the virtual
// Transformation funtion
class SimpleEncryption : public Encryption
{
public:
   char transform(char ch)
   {
     return ch + key;
   }
   SimpleEncryption(char *inFileName, char *outFileName)
   : Encryption(inFileName, outFileName)
   {

   }
};

int main()
{
  // Get names of input and output files
  char inFileName[80], outFileName[80];  
  cout << "Enter name of file to encrypt: ";
  cin >> inFileName;
  cout << "Enter name of file to receive the encrypted text: ";
  cin >> outFileName;

  // Create the encryption object
  SimpleEncryption obfuscate(inFileName, outFileName);

  // Get and set the key to be used for the encryption
  cout << "Enter a small integer as an encryption key";
  int key;
  cin >> key;
  obfuscate.setKey(key);

  // Perform the encryption
  obfuscate.encrypt();
  return 0;
}



