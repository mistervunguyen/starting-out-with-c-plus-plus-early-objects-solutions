//  Chapter 12 -- Assignment 5: Name Arranger
// This program arranges the three components of a person's name
// in a canonical order: Last-name, first-name middle-name.

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Variables needed to hold the name(s)
    const int NAME_LENGTH = 21;
    char first[NAME_LENGTH], middle[NAME_LENGTH], 
         last[NAME_LENGTH], full[3*NAME_LENGTH];

    // Get the names
    cout << "Enter your first name: ";
    cin.getline(first, NAME_LENGTH);
    cout << "Enter your middle name: ";
    cin.getline(middle, NAME_LENGTH);
    cout << "Enter your last name: ";
    cin.getline(last, NAME_LENGTH);

    // Arrange the names
    strcpy(full, last);
    strcat(full, ", ");
    strcat(full, first);
    strcat(full, " ");
    strcat(full, middle);

    // Print the result
    cout << full << endl;

    return 0;
}