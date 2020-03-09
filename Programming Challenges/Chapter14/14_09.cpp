// Chapter 14 -- Assignment 9, Ackermann's Function
// This program computes Ackermann's function.
 
#include <iostream>
using namespace std;

//Function Prototype
long ack(long m, long n);

int main( )
{
  for (int m = 0; m <=1; m++)
   for (int n = 0; n <=1; n++)
      cout << "A(" << m << "," << n << ") is " << ack(m, n) << endl;
  
  //On Most computers:
  //The complexity of recursion overflows the stack at this point
  //so this part cannot be executed without generating stack errors.
  
  for (int row = 1; row <= 3; row ++)
      cout << "A(" << row << "," << 2 << ") is " << ack(row, 2)
           << endl;
   
  return 0;
}

//***********************************
//           Ackerman               *
//***********************************
long ack(long m, long n)
{
   if (m == 0) return n + 1;
   if (n == 0) 
      return ack(m-1, 1);
   else 
      return ack(m-1, ack(m-1, ack(m, n-1)));
}
