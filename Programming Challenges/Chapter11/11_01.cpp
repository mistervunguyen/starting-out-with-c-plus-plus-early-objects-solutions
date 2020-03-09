// Chapter 11 - Assignment 1, Check Writing
// This program creates a Number Translation class 
// that can be used for writing checks.

#include <iostream>
#include <string>
using namespace std;

// This class represents functionality needed to convert 
// an integer number to word description of the number.
class Numbers
{
public:
    const static string lessThan20[ ];
    const static string tens[ ];
    const static string hundred;
    const static string thousand;    
    void print();
    Numbers(int x){ number = x;}
private:
    int number;    
};

// Static member variables must be defined outside of the class	
const string Numbers::lessThan20[ ] = 
     {"zero", "one", "two", "three", "four", "five",
      "six", "seven", "eight", "nine", "ten", 
      "eleven", "twelve", "thirteen", "fourteen", 
      "fifteen", "sixteen", "seventeen", "eighteen",
      "nineteen", 
};

const string Numbers::tens[ ] = 
    { "zero", "ten", "twenty", "thirty", "forty",
      "fifty", "sixty", "seventy", "eighty", "ninety",
};


const string Numbers::hundred = "hundred";
const string Numbers::thousand = "thousand";

//**********************************************************
//                     print                               *
// Prints out the English description of the number.       *
//**********************************************************
void Numbers::print()
{
    if (number < 0) cout << "minus ";
    int residue = number;  // What remains to be printed out

    // Make sure residue is nonnegative
    if (residue < 0) residue = - residue;
    
    // Take care of thousands, if any
    int n_thousands = residue/1000;
    residue = residue % 1000;
    if (n_thousands > 0) 
    {
        cout << " " << lessThan20[n_thousands];
        cout << " thousand ";
    }

    // Take care of hundreds, if any
    int n_hundreds= residue /100;
    residue = residue % 100;
    if (n_hundreds > 0)
    {
       cout  <<  " " << lessThan20[n_hundreds];
       cout << " hundred ";       
    }

    // Take care numbers less than  100
    if (residue >= 20)
    {
        int n_tens = residue /10;
        residue = residue % 10;    
        if (n_tens > 0)        
           cout << " " << tens[n_tens];
        if (residue == 0) return;                    
    }
    
    // Take care of anything less than 20
    cout << " " << lessThan20[residue];
}

int main()
{
    // Tell user what the program does and get input
    cout << "This program translates whole dollar amounts into words for the ";
    cout << "for the purpose of writing checks.";
    cout << "\nEntering a negative terminates the program.";
    cout << "\nEnter an amount for be translated into words: "; 
    int  number;
    cin >> number;

    // Keep translating numbers until the user enters a negative value
    while (number >= 0)
    {
        // Create a Numbers object
        Numbers n(number);
        // Print the English description
        n.print();
        // Get another number
        cout << "\nEnter another number: ";
        cin >> number;
    }  

    // We are done       
    return 0;
}
    
    
    
