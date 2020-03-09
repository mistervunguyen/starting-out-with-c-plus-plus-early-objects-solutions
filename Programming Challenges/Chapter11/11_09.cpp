// Chapter 11, Assignment 9: Rational Arithmetic II
#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;

class Rational
{
   // Declaration of overloaded stream insertion operator
   friend ostream & operator << (ostream &, Rational r);
   // Declaration of overloaded arithmetic operators
   friend Rational operator +(Rational, Rational);
   friend Rational operator -(Rational, Rational);
   friend Rational operator *(Rational, Rational);
   friend Rational operator /(Rational, Rational);
   Rational operator -();   // overloaded unary minus
private:
   int numerator, denominator;
public:
   // Constructor builds a rational number n/d
   Rational(int n, int d):numerator(n), denominator(d)
   {    
      reduce();
   }
private:
   // This member function transforms a rational number into 
   // reduced form where the numerator and denominator have 1
   // as greatest common factor
   void reduce();  
};

//************************************************************
// This member function transforms a rational number into    *
// reduced form where the numerator and denominator have 1   *
// as greatest common factor.                                *
//************************************************************
void Rational::reduce()
{
    bool negative = (numerator < 0) != (denominator < 0);
    numerator = abs(numerator);
    denominator = abs(denominator);

    int factor = 2;
    while (factor <= min(numerator, denominator))
    {
       if (numerator % factor == 0 && denominator % factor == 0)
       {
           numerator = numerator / factor;
           denominator = denominator / factor;
           continue;
       }
       factor ++;
    }
    if (negative) 
       numerator = - numerator;
}


//************************************************
// Overloaded stream insertion operator          *
//************************************************
ostream & operator << (ostream &out, Rational r)
{
   out << r.numerator << "/" << r.denominator;
   return out;
}

//************************************************
// Overloaded unary minus operator               *
//************************************************
Rational Rational::operator-()
{
  Rational rat(-numerator, denominator);
  rat.reduce();
  return rat;
}

//************************************************
// Overloaded stream addition operator           *
//************************************************
Rational operator +(Rational a, Rational b)
{
   int denominator = a.denominator * b.denominator;
   int numerator = a.numerator * b.denominator + a.denominator * b.numerator;
   Rational sum(numerator, denominator);
   sum.reduce();
   return sum;
}

//************************************************
// Overloaded stream subtraction operator        *
//************************************************
Rational operator -(Rational a, Rational b)
{
  return a + -b;
}

//************************************************
// Overloaded stream multiplication operator     *
//************************************************
Rational operator *(Rational a, Rational b)
{
   int denominator = a.denominator * b.denominator;
   int numerator = a.numerator * b.numerator;
   Rational prod(numerator, denominator);
   prod.reduce();
   return prod;
}

//************************************************
// Overloaded stream division operator           *
//************************************************
Rational operator /(Rational a, Rational b)
{
  // a / b is a *  ( inverse of b)
  Rational bInverse = Rational(b.denominator, b.numerator);
  return a * bInverse;
}


int main()
{
  // Use an istringstream object to simulate file or keyboard input
  istringstream input("2 / 3 + 2 / 8\n2 / 3 * -2 / 8\n"
                      "2 / 3 - 2/ 8\n 2 / 3 / 2 / 8"
                     );
  int numerator, denominator;
  string slash;  // The slash string between the numerator and denominator
  string op;     // Binary operator to apply to the two rationals
  
  // Get the numerator for the first rational
  input >> numerator;
  while (input)
  {
      //A numerator was found, so we assume there is another line of input      
      input >> slash >> denominator;
      Rational a(numerator, denominator);
      //Read the binary operator between the rationals and the second rational
      input >> op >> numerator >> slash >>  denominator;
      Rational b(numerator, denominator);
      // Perform the operation
      Rational result(0,0);
      switch(op[0])
        {
        case '+' : result = a + b; break;
        case '-' : result = a - b; break;
        case '*' : result = a * b; break;
        case '/' : result = a / b ; break;
        default:  cout << "Internal Error in Program."; exit(1);     
        }
      //Print the results
      cout << a << " " <<  op[0] << " " << b << " = " << result << endl;
      // See if there is another line by checking for a numerator
      input >> numerator;
  }
  // end of input
  
  return 0;
}