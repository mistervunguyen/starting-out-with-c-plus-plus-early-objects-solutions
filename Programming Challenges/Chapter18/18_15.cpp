// Chapter 18 - Assignment 15, Stack-based Evaluation of Prefix Expressions.
// This program evaluates prefix expressions using a stack.
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>

using namespace std;

struct StackElement
{
   bool is_value;
   int value;
   char op;
   StackElement(int number)
   {
      is_value = true;
      value = number;
   }
   StackElement(char ch)
   {
      is_value = false;
      op = ch;
   }
};

int prefixExpr(istream & inputStream);
int evaluate(char op, int left_operand, int right_operand);
bool prefix_reducible(vector<StackElement>& pstack);
ostream &operator << (ostream &out, StackElement & s);


int main()
{
   string input;
   cout << "Enter a prefix expression to convert to evaluate,"
      << " \nor a blank line to quit the program:";
   getline(cin, input);
   while (input.size() != 0)
   {
      // Convert string to a string stream
      istringstream inputExpr(input);
      cout << "The value is "
         << prefixExpr(inputExpr) << endl;
      cout << "Enter another prefix expression: ";
      getline(cin, input);
   }
   return 0;
}

//***************************************************************
// Takes an istream that contains a single prefix expression p  *
// and returns its value                                        *
//***************************************************************
int prefixExpr(istream & in)
{
   // Stack of operators and stack of values
   vector<StackElement> prefixStack;

   // Used to read characters in the expression
   char ch;
   // Used to read numbers in the expression            
   int number;
   // Used to remove infix expressions from the stack        
   string lExpr, rExpr;

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
      // If the next character is a digit, read and
      // push the number onto the stack
      if (isdigit(ch))
      {
         in >> number;
         prefixStack.push_back(StackElement(number));

         // if there are at least three entries on the stack,
         // top two entries are values
         // and the third from the top is an operator, apply the operator
         // and replace the top three elements with the result
         while (prefix_reducible(prefixStack))
         {
            int right_operand = prefixStack.back().value;
            prefixStack.pop_back();
            int left_operand = prefixStack.back().value;
            prefixStack.pop_back();
            char op = prefixStack.back().op;
            prefixStack.pop_back();

           // cout << "operands are " << left_operand << " " << right_operand << endl;
           // cout << "operator is " << op << endl;
            

            prefixStack.push_back(StackElement(evaluate(op, left_operand, right_operand)));
         }
         // Get ready for next iteration
         ch = in.peek();
         continue;
      }
      // If the next character is an operator,
      // read the character and push it onto the
      // operator stack
      ch = in.get();
      if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
      {
         prefixStack.push_back(StackElement(ch));
         ch = in.peek();
      }
      else
      {
         cout << "Error in the input expression" << endl;
         exit(1);
      }     
   }
   if (prefixStack.size() != 1)
   {
      cout << "Error: Incorrectly formed expression.\n";
      for (auto x : prefixStack) { cout << x << endl; }
      exit(1);
   }
   return prefixStack.back().value;
}


//********************************************************
// applies a single operand to a pair of operands.       *
//********************************************************
int evaluate(char op, int left_operand, int right_operand)
{
   cout << op << " " << left_operand << " " << right_operand << endl;
   switch (op)
   {
   case '+': return left_operand + right_operand;
   case '-': return left_operand - right_operand;
   case '*': return left_operand * right_operand;
   case '/': return left_operand / right_operand;
   default: assert(false);
   }
}

//*****************************************************************
// Returns true if there are at least three entries on the stack  *
// that consist of two values on top of an operator.               *
//*****************************************************************
bool prefix_reducible(vector<StackElement>& pstack)
{
   int size = pstack.size();
   if (size < 3) return false;
 
   return pstack[size - 1].is_value && pstack[size - 2].is_value 
                                    && !pstack[size - 3].is_value;
}

//****************************************************************
//                  overloaded operator <<                       *
//  Prints a StackElement.                                       *
//****************************************************************
ostream & operator << (ostream &out, StackElement& s)
{
   out << "is_value: " << s.is_value << " ";
   if (s.is_value)
      out << s.value;
   else
      out << s.op;

   return out;
}