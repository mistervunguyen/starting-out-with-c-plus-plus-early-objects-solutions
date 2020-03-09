// Chapter 18, Assignment 8, Evaluating Postfix expressions 
// This program evaluates postfix expressions.
 
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

int postfixExpr(istream & inputStream);

int main()
{
    string input;
    cout << "Enter a postfix expression to convert to infix, \nor a blank line to "
         << "quit the program:";
    getline(cin, input);
    while (input.size() != 0)
    {
        istringstream inputExpr(input);   // Convert string to a string stream
        cout << "The value of the expression is " << postfixExpr(inputExpr) << endl;
        cout << "Enter a postfix expression to evaluate: ";
        getline(cin, input);
    }
    return 0;
}

//***************************************************************
// Takes an istream that contains a single postfix expression p *
// and returns the value of the expression                      *
//***************************************************************
int postfixExpr(istream & in)
{
   stack<int> valueStack;     // Holds intermediate values in computation
   char ch;                   // Used to read  characters in the expression
   int number;                // Used to read numbers in the  expression
   int value1, value2;        // Used to remove values from the stack

   ch = in.peek();
   while (ch != EOF)
   {
       // If we have a whitespace character skip it and
       // continue with the next iteration of this loop
       if (isspace(ch))
       {
           ch = in.get();
           ch = in.peek();
           continue;  // Go back to top of loop
       }
       // Nonspace character is next in input stream
       // If the next character is a number, read it 
       // and push it onto the stack
       if (isdigit(ch))
       {
          in >> number;
		  valueStack.push(number);
          
          ch = in.peek();
          continue;
       }
       // If the next character is an operator,
       // pop the two top values stored on the
       // stack, apply the operator and then
       // push the result on the stack

       value2 = valueStack.top();
       valueStack.pop();
       value1 = valueStack.top();
       valueStack.pop();
	   switch(ch)
	   {
	   case '+': valueStack.push(value1 + value2); break;
	   case '-': valueStack.push(value1 - value2); break;
	   case '*': valueStack.push(value1 * value2); break;
	   case '/': valueStack.push(value1 / value2); break;
	   default:
		   cout << "Error in the input expression" << endl;
           exit(1);
	   }
       
       ch = in.get();  // Actually read the operator character
       ch = in.peek(); // Prepare for the next iteration of the loop
   }
   return valueStack.top();
}
