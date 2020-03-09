// Chapter 11 - Assignment 6, String Encryption
// This program uses a class derived from string to 
// to encrypt strings
 
#include <iostream>
#include <string>
using namespace std;

// This class represents a string that
// Is can be encrypted
class EncryptableString : public string
{
  public:
  void encrypt();   
  EncryptableString(string s) : string(s)
  {
  }
};

//****************************************************
//      EncryptableString::encrypt                   *
// Encrypts the string.                              *
//****************************************************
void  EncryptableString::encrypt()
{
  for (int k = 0; k < this->length(); k++)
    (*this)[k]++;    
}

int main ()
{
  // Request input from user
  string str;
  cout << "This is an Encryption program. Enter a string to encrypt:\n";
  cin >> str;

  // Create an object that will encrypt strings
  EncryptableString s(str);

  // Encrypt and print
  s.encrypt();
  cout << "\nHere is the encrypted string: ";
  cout << static_cast<string>(s);

  return 0;
}