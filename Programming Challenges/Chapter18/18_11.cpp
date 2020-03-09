// Chapter 18 - Assignment 11, Balanced Multiple Parentheses
// This program checks a string to see if it contains 
// properly balanced parentheses.
 
#include <iostream>
#include <string>
#include <stack>            // STL stack
using namespace std;

bool isBalanced(string s);  // Prototype

int main()
{   
    // Tell user what program does
    cout << "This program checks a string to see if its parentheses are properly \n";
    cout << "balanced.";
    
    // Get string from user
    string str;
    cout << "\nType in a string with some parentheses:\n";
    getline(cin, str);

    // Check the string and report
    if (isBalanced(str))
        cout << "The string has balanced parentheses.";
    else
        cout << "The string does not have balanced parentheses.";    
    return 0;
}

// *********************************************************************
//                      isBalanced                                     *
// Checks to see if a string has balanced parenthesis.                 *
// Main idea is, whenever you find a left delimiter, stack the         *
// corresponding right delimiter. Then whenever a right delimiter      *
// is found, you look to match it with the current top of the stack.   *
// If we get to the end of the string and the stack is not empty.      *
// *********************************************************************
bool isBalanced(string str)
{
    stack<char> charStack;
    char expected;
    for (unsigned int k = 0; k < str.length(); k++)
    {
        switch(str[k])
        {
           case '(' : charStack.push(')'); 
                      break;
           case '{' : charStack.push('}'); 
                      break;
           case '[' : charStack.push(']'); 
                      break;
           case ')' :
           case ']' :
           case '}' :
                      expected = charStack.top();
                      charStack.pop();

                      // See if you have what you were expecting
                      if (expected != str[k]) 
                          return false;
                      else break;                          
           default:  break;        
        }
    }
    if (charStack.empty()) 
        return true;
    else 
        return false;        
}