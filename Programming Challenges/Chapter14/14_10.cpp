// Chapter 14, Assignment 10, Prefix to Postfix
// This program converts prefix expressions to Postfix
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
 
//Prototype
string prefixToPostfix(istream &exprStream); 

int main()
{
    string input;
    cout << "Enter prefix expressions to evaluate.\n"
         << "Press enter after each expression,\n"
         << "and press enter on a blank line to quit.\n\n" ;
    cout << "Enter a prefix expression to convert: ";
    getline(cin, input);
    while (input.size() != 0)
    {
        // Convert string to istringstream
        istringstream exprStream(input);
        // Evaluate the prefix expression
        cout << prefixToPostfix(exprStream) << endl;
        // Get next line of input
        cout << "Enter a prefix expression to convert: ";
        getline(cin, input);
    }
    return 0;
}

//***************************************************************
// Takes an istream that contains a single prefix expression p  *
// and returns the postfix equivalent.                          *
//***************************************************************
string prefixToPostfix(istream &exprStream)
{

   // Peek at first non-space character in prefix expression
   char ch = exprStream.peek();
   while (isspace(ch))
   {
       ch = exprStream.get();   // Read the space character
       ch = exprStream.peek();  // Peek again
   }

   if (isdigit(ch))
   {
       // The prefix expression is a  single number
       int number;
       ostringstream ostr;
       exprStream >> number;

       // Convert the expression to a string and return that.      
       ostr << number;
       return ostr.str();
   }
   else
   {
       // The prefix expression is an operator followed
       // by two prefix expressions

       // Read the operator
       ch = exprStream.get();

       // Recursively evaluate the two subexpressions
       string expr1 = prefixToPostfix(exprStream);
       string expr2 = prefixToPostfix(exprStream);

       // Place the operator after the two subexpressions
       if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
       {
	  cout << "Error in expression.";
          exit(1);
	}

	// Form the postfix expression and return the result
	return expr1 + " " + expr2 + " " +  ch;
   }
}
