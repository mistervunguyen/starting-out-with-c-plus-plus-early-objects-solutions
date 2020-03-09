// Chapter 18 - Assignment 14, Stack-based Evaluation of Postfix Expressions
// This program uses a stack to evaluate Postfix expressions

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;


//**************************************************************
//             skipWhiteSpace                                  *
// Skips whitespace in an input stream.                        *
//**************************************************************
void skipWhiteSpace(istream& in)
{
   while (in.good() && isspace(in.peek()) )
   {
      // Read and discard the space character
      in.get();
   }
}

//******************************************************
//                  postFixEval                        *
// If the next token in the input is an integer, read  *
// the integer and push it on the stack; but if it is  *
// an operator, pop the last two values from the stack *
// and apply the operator, and push the result onto    *
// the stack.  At the end of the string, the lone      *
// on the stack is the result.                         *
//******************************************************
int postFixEval(string str)
{
   istringstream in = istringstream(str);
   stack<int> postFixStack;
   skipWhiteSpace(in);

   while (in)
   {     
      if (in.peek() == EOF) { break; }
      // Is the next token a number?
      if (isdigit(in.peek()))
      {
         // Read a number and push it onto the stack.
         int number;
         in >> number;
         postFixStack.push(number);
         skipWhiteSpace(in);
         continue;
      }
      // Next token is an operator.
      char operatorCh = in.get();
      // Pop two values at the top of the stack, apply the 
      // operator, and push the result onto the stack.
      int y = postFixStack.top();  postFixStack.pop();
      int x = postFixStack.top();  postFixStack.pop();
      int result = 0;
      switch (operatorCh)
      {
      case '+': result = x + y; break;
      case '*': result = x * y; break;
      case '-': result = x - y; break;
      case '/': result = x / y; break;
      case '%': result = x % y; break;
      default: break;
      }
      postFixStack.push(result);
      skipWhiteSpace(in);
   }
   return postFixStack.top();
}

int main()
{
   string input;

   while (true)
   {
      cout << "Enter a postfix expression, or press ENTER to quit:\n";
      getline(cin, input);
      
      if (input.length() == 0)
      {
         break;
      }
      int number = postFixEval(input);
      cout << "The value of " << input << " is " << number << endl;
   }

   return 0;
}