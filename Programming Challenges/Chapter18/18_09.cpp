//  Chapter 18 -- Assignment 9, File Reverser
// This program uses a stack to make a reversed copy of a file.
 
#include<iostream>
#include <fstream>
using namespace std;

template <class T>
class DynStack
{
private:
   struct StackNode
   {
    T value;
    StackNode *next;
    // Constructor to ease the drudgery
    StackNode(T val, StackNode *nextP)
    {
      value = val; next = nextP;
    }
   };
   StackNode *top;
public:
   DynStack() { top = NULL; }
   void push(T);
   void pop(T &);
   bool isEmpty();
};

//**************************************************
//                  Stack::push                    *
// Member function push pushes the argument onto   *
// the stack.                                      *
//**************************************************
template <class T>
void DynStack<T>::push(T val)
{
    top = new  StackNode(val, top);
}

//*********************************************************
//                     Stack::pop                         *
// Member function pop pops the value at the top          *
// of the stack off, and copies it into the variable      *
// passed as an argument.                                 *
//*********************************************************
template <class T>
void DynStack<T>::pop(T &val)
{
    StackNode *temp;
    
    if (isEmpty())
    {
        cout << "The stack is empty.\n";
        return;
    }
    else        // Pop value off top of stack
    {
        val = top->value;
        temp = top;
        top = top->next;
        delete temp;
    }
}

//*******************************************************
//                  Stack::isEmpty                      *
// Member function isEmpty returns true if the stack    *
// is empty, or false otherwise.                        *
//*******************************************************
template <class T>
bool DynStack<T>::isEmpty()
{
    if (!top)
        return true;
    else return false;
}

int main()
{
   // Explain use of program 
   cout << "This program uses a stack to reverse the contents of one file into a second file.\n";

   // Get name of input file and open it
   string  file1Name, file2Name;
   cout << "Enter name of source file: ";  
   cin >> file1Name;
   fstream file1(file1Name.data(), ios::in);
   if (!file1)
   {
      cout << "Could not open " << file1Name;
      exit(1);
   }

   // Get name of output file and open it
   cout << "Enter name of destination file: "; 
   cin >> file2Name;  
   fstream file2(file2Name.data(), ios::out);
   if (!file2)
   {
      cout << "Could not open " << file1Name;
      exit(1);
   }

   // Create the stack and use it  to reverse the first file into the second,
   // Begin by copying the first file into a stack   
   DynStack<char> stack;
   char catchChar, ch;
   while (file1.get(catchChar))
   {
      stack.push(catchChar);
   }
   file1.close();

   // Now dump the stack, one character at a time, into the second file
   while (!stack.isEmpty())
   {
      stack.pop(ch);
      file2 << ch;
   }
   file2.close();

   // Echo the second file to the screen
   file2.open(file2Name.data(), ios::in);  
   while (file2.get(ch))
   {
      cout << ch;
   }
   file2.close();

   return 0;
}

