// Chapter 14 -- Assignment 7, String reverser
 
#include <iostream>
#include <cstring>
using namespace std;

//Function Prototype
void printReverse(char *);

int main( )
{
   char str[81];
   cout << "Enter a string: " ;
   cin >> str;
   cout << "The reversed string is :\n";
   printReverse(str);
   return 0;
}

//*********************************************
//            printReverse                    *
//   prints a string in reverse.              *
//*********************************************

//An empty string is printed in reverse by doing nothing.
//A non empty string is printed in reverse by first printing
//the tail of the string in reverse, then printing the
//first character of the print last.  The tail of the string is
//what remains after you cut off the first element.
void printReverse(char *s)
{
  if (*s != '\0')
  { 
    //non base case : print the tail in reverse
    printReverse(s+1);
    cout << *s;  //print the first character last
  }
}





