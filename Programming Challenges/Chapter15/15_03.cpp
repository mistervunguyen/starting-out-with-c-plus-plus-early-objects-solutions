// Chapter 15 -- Assignment 3, Sequence Sum
 
#include <iostream>
using namespace std;

// This class represents an abstract sequence
// together with operations for generating a member of
// the sequence, printing the sequence, and summing the 
// sequence.
class AbstractSeq
{
public:
  virtual int fun(int k) = 0;
  void printSeq(int k, int m);
  int sumSeq(int k, int m);
};

// **************************************
//       AbstractSeq::sumSeq            *
// Sum a portion of the sequence.       *
// **************************************
int AbstractSeq::sumSeq(int k, int m)
{
   int sum = 0;
   for (int i = k; i <= m; i++)
     sum = sum + fun(i);
   return sum;
}

//****************************************
//       AbstractSeq::printSeq           *
// Print a portion of the sequence.      *
//****************************************
void AbstractSeq::printSeq(int k, int m)
{
  for (int i = k; i <= m; i++)
    cout << fun(i) << "  ";
}

// Odd sequence subclass
class OddSeq : public AbstractSeq
{
  int fun(int k){ return 2*k - 1; }
};

// Square sequence subclass
class SquareSeq : public AbstractSeq
{
  int fun(int k) { return k*k; }
};

int main()
{
  // Create two sequences
  OddSeq odd;
  SquareSeq sq;

  // Display the two sequences
  cout << "The first 5 odd numbers are: " << endl;
  odd.printSeq(1, 5);
  cout << "\nThe sum of the first 5 odd numbers is: " << odd.sumSeq(1, 5);
  cout << endl;
  cout << "\nThe first 5 squares are: " << endl;
  sq.printSeq(1, 5);

  // Display sum of the square sequence
  cout << "\nThe sum of the first 5 squares is: " << sq.sumSeq(1, 5);
  cout << endl;

  return 0;
}
