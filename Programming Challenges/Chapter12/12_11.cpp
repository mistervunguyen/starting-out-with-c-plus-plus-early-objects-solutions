//  Chapter 12 -- Assignment 11:  Phone Number List
// The program looks up phone numbers of people based on 
// partial name information entered by the user.

/* The getline(cin, str) function in Borland C++ Builder 5.0 somehow
   corrupts the string read so that the find(string, pos) member function
   fails to work.  Using find(string.data(), pos) seems to get around the
   difficulty.
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
   // Variables to hold program information
   const int SIZE = 11;
   string  name; // Name to look for
   string  phoneDirectory[SIZE] = {
        "Renee Javens, 678-1223",
        "Joe Looney, 586-0097",
        "Geri Palmer, 223-8787",
        "Lynn Presnell, 887-1212",
        "Bill Wolfe, 223-8878",
        "Sam Wiggins, 486-0998",
        "Bob Kain, 586-8712",
        "Tim Haynes, 586-7676",
        "John Johnson, 223-9037",
        "Jean James, 678-4939",
        "Ron Palmer, 486-2783" };

   // Get name from user
   cout << "Enter a name or partial name to search for: ";
   getline(cin, name);

   // Look up information
   int numberEntriesFound = 0;
   cout << "\nHere are the results of the search: " << endl;
   for (int k = 0; k < SIZE; k++)
     {
       if (phoneDirectory[k].find(name.data(), 0) < phoneDirectory[k].length())
        {
           numberEntriesFound ++;
           cout << phoneDirectory[k] << endl;
        }
     }
   if (numberEntriesFound == 0)
      cout << "\nNo Entries were found for " << name;

   return 0;
}

