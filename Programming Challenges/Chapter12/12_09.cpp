// Chapter 12 --  Assignment 9: Case Manipulator
// This program can manipulate the case of letters in a string.
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Function Prototypes
void upper(char []);
void lower(char []);
void reverse(char []);

int main()
{
    // Buffers to hold strings
    const int STR_LEN = 80;
    char str1[STR_LEN], str2[STR_LEN], str3[STR_LEN];

    // Get a string
    cout << "Enter a string: ";
    cin.getline(str1, STR_LEN);

    // Manipulate the case
    strcpy(str2, str1);
    strcpy(str3, str1);
    cout << "After a call to Upper: ";
    upper(str1);
    cout << str1 << endl;
    cout << "After a call to Lower: ";
    lower(str2);
    cout << str2 << endl;
    cout << "After a call to Reverse: ";
    reverse(str3);
    cout << str3 << endl;

    return 0;
}
//********************************
//      upper                    *
// Raise a string to uppercase.  *
//********************************
void upper(char str[])
{
   while (*str != 0)
   {
         *str = toupper(*str);
        str++;
   }
}

//******************************
//        lower                *
// Make a string lowercase.    *
//******************************
void lower(char str[])
{
   while (*str != 0)
   {
    *str = tolower(*str);
      str++;
   }
}
//******************************************* 
//               reverse                    *
// Reverse case of each letter in a string. *
//*******************************************
void reverse(char str[])
{
   while (*str != 0)
   {
       if (islower(*str))
             *str = toupper(*str);
        else if (isupper(*str))
             *str = tolower(*str);
        str++;
   }
}


