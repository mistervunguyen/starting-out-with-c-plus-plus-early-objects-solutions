//  Chapter 18 --  Assignment 5, Dynamic Stack Template (Error Testing).
// This program handles an out of memory error by catching the bad_alloc
// exception in the push stack operation.
 
#include<iostream>
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
   DynStack(){ top = NULL; }
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
   // Catch bad_alloc exception if out of memory
   try
    {
        top = new  StackNode(val, top);
    }
   catch(bad_alloc)
   {
     cout << "Out of memory.";
     exit(1);
   }  
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
    DynStack<double> stack;
    double catchVar;

    // Demonstrate 
    cout << "Pushing 5.0\n";
    stack.push(5.0);
    cout << "Pushing 10.1\n";
    stack.push(10.1);
    cout << "Pushing 15.2\n";
    stack.push(15.2);
    cout << "Popping...\n";
    stack.pop(catchVar);
    cout << catchVar << endl;
    stack.pop(catchVar);
    cout << catchVar << endl;
    stack.pop(catchVar);
    cout << catchVar << endl;

    cout << "\nAttempting to pop again... ";
    stack.pop(catchVar);
    return 0;
}

