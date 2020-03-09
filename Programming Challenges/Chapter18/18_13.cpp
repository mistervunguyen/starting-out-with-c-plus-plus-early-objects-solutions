// Chapter 18, Assignment 13, Stack-Based Fibonacci Function
#include <cstdlib>
#include <stack>
#include <iostream>

using namespace std;
// Prototype 
int fibonacci(int n);

int main ( )
{
  cout << "Enter a positive integer: ";
  int number;
  cin >> number;
  cout << "The first " << number << " terms of the Fibonacci sequence are: \n";
  for (int k = 0; k <= number; k++)
  {
     cout << fibonacci(k)  << " " ;      
  }
  return 0;
}

//**************************************************
// Computes the nth term of the Fibonacci sequence *
//**************************************************
int fibonacci(int n)
{
   stack<int> fibStack;
   // Stack the first two terms of the Fibonacci sequence
   fibStack.push(1);
   fibStack.push(1);
   
   // Stack the rest of the terms from 2..n
   for (int k = 2; k <= n; k++)
   {
       // pop last two elements off the stack 
       int t1 = fibStack.top();
       fibStack.pop();
       int t2 = fibStack.top();
       fibStack.pop();
       // put the first element popped back on the stack
       fibStack.push(t1);
       // push the sum of t1 and t1 onto the stack
       fibStack.push(t1+t2);       
   }
   // return top of the stack
   return fibStack.top(); 
}
