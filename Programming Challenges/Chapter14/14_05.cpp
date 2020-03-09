//  Chapter 14 -- Assignment 5, Recursive Multiplication
// This program demonstrates how to use recursion to implement
// multiplication
 
#include <iostream>
using namespace std;

// Function Prototype
int mult(int, int);

int main()
{
    // Get the two numbers to multiply
    cout << "Enter 2 integers to computer a product: ";
    int x, y;
    cin >> x >> y;

    // Call the function mult and print the result
    cout << "The product is " << mult(x, y);
    cout << endl;

    return 0;
}

// ****************************
//          mult              *
// Recursive multiplication.  *
// ****************************
int mult(int x, int y)
{
    // Base case
    if (x == 0)
       return 0;

    // If x is not 0 then handle negative and positive values 
    // separately   
    if (x > 0) 
        return y + mult(x-1, y);
    else 
        return -mult(-x, y);    
}

