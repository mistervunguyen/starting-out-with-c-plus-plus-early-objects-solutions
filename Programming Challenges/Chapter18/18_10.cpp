// Chapter 18 - Assignment 10, Balanced Parentheses
// This program checks a string to see if it contains 
// properly balanced parentheses.
 
#include <iostream>
#include <string>
#include <stack>             // STL stack
using namespace std;

bool isBalanced(string s);   // Prototype

int main()
{   
    // Tell user what program does
    cout << "This program checks a string to see if its parentheses are properly \n";
    cout << "balanced.";
    
    // Get string from user
    string str;
    cout << "\nType in a string with some parenthesis:\n";
    getline(cin, str);

    // Check the string and report
    if (isBalanced(str))
        cout << "The string has balanced parentheses.";
    else
        cout << "The string does not have balanced parentheses.";    
    return 0;
}

//**********************************************************************
//                        isBalanced                                   *    
// Checks to see if a string has balanced parenthesis.                 *
// Main idea is to stack each left parenthesis as it is found, and     *
// then pop it off the stack when its mate is encountered.             *
// The string is not balanced if upon encountering a right             *
// parenthesis, the top of the stack is not a left parenthesis, or if  *
// we get to the end of the string and the stack is not empty.         *
//**********************************************************************
bool isBalanced(string str)
{
    stack<char> charStack;
    for (unsigned int k = 0; k < str.length(); k++)
    {
        switch(str[k])
        {
        case '(' : 
            // Put left paren on stack
            charStack.push(str[k]); break;
        case ')' : 
            // See if right paren has a mate on the stack
            if (charStack.empty()) 
               return false;
            else 
               charStack.pop(); 
            break;
        default: 
            // Ignore all other characters
            ;            
        }
    }
    if (charStack.empty()) 
        return true;
    else 
        return false;        
}
