//  Chapter 18 - Assignment 2, Dynamic Stack Template.
 
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
    DynStack<double> stack;
    double catchVar;

    // Demonstrate the stack
    cout << "Pushing 5.0\n";
    stack.push(5.0f);
    cout << "Pushing 10.1\n";
    stack.push(10.1f);
    cout << "Pushing 15.2\n";
    stack.push(15.2f);
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

