// Chapter 11 - Assignment 11, Prime Number Generation
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// This is a function object that checks if an integer is composite.
// It checks for the existence of factors up to the square root of the number.
class IsComposite
{
public:
   bool operator()(int number)
   {
      for (int d = 2; d*d <= number; d++)
      {
         if (number % d == 0) { return true; }
      }
      return false;
   }
};

int main()
{   
   vector<int> primes;

   cout << "This program will generate all prime numbers less or equal to any number you specify." << endl;
   int X;
   cout << "Enter a positive integer: ";
   cin >> X;
   for (int i = 2; i <= X; i++)
   {
      primes.push_back(i);
   }
   auto start_rem = remove_if(begin(primes), end(primes), IsComposite());

   primes.erase(start_rem, end(primes));

   cout << "Here are all the prime numbers less than or equal to  "  << X << ":" << endl;
   for (int x : primes) 
   { 
      cout << x << " ";  
   }

   cout << endl;

   return 0;
}