// Chapter 10 - Assignment 10,  Smart Pointers
// This program modifies Program 10-16 to use smart pointers.
// The Squares class uses a unique pointer  while the main 
// function uses a shared pointer that is shared with the 
// outputSquares function.
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Squares
{
private:
   int length;                 // How long is the sequence
   unique_ptr<int[]> sq;       // Dynamically allocated array
public:
   // Constructor allocates storage for sequence
   // of squares and creates the sequence
   Squares(int len)
   {
      length = len;
      sq.reset(new int[length]);
      for (int k = 0; k < length; k++)
      {
         sq[k] = (k + 1)*(k + 1);
      }
      // Trace
      cout << "Construct an object of size " << length << endl;
   }
   
   // Print the sequence
   void print()
   {
      for (int k = 0; k < length; k++)
         cout << sq[k] << "  ";
      cout << endl;
   }
   
   // Destructor deallocates storage 
   ~Squares()
   {
      // Trace
      cout << "Destroy object of size " << length << endl;
   }
};

//***********************************************
// Outputs the sequence of squares in a         *
// Squares object                               *
//***********************************************
void outputSquares(shared_ptr<Squares> sqPtr)
{
   cout << "The list of squares is: ";
   sqPtr->print();

}


int main()
{
   // Main allocates a Squares object
   // Uses a pointer that is shared with the outputSquares function.
   shared_ptr<Squares> sqPtr(new Squares(3));
   outputSquares(sqPtr);

   return 0;
}