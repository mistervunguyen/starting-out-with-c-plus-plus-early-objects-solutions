//  Chapter 18 - Assignment 1, Static Stack Template.
 
#include<iostream>
using namespace std;

template <class T>
class Stack
{
private:
    T *stackArray;
    int stackSize;
    int top;

public:
    Stack(int);
    void push(T);
    void pop(T &);
    bool isFull();
    bool isEmpty();
};

//*********************	
//   Constructor      *
//*********************
template <class T>
Stack<T>::Stack(int size)
{
    stackArray = new T[size]; 
    stackSize = size; 
    top = -1;
}

//**************************************************
//                  Stack::push                    *
// Member function push pushes the argument onto   *
// the stack.                                      *
//**************************************************
template <class T>
void Stack<T>::push(T num)
{
    if (isFull())
    {
        cout << "The stack is full.\n";
        exit(1);
    }
    else
    {
        top++;
        stackArray[top] = num;
    }
}

//*********************************************************
//                     Stack::pop                         *
// Member function pop pops the value at the top          *
// of the stack off, and copies it into the variable      *
// passed as an argument.                                 *
//*********************************************************
template <class T>
void Stack<T>::pop(T &num)
{
    if (isEmpty())
    {
        cout << "The stack is empty.\n";
        exit(2);
    }
    else
    {
        num = stackArray[top];
        top--;
    }
}

//*******************************************************
//               Stack::isFull                          *
// Member function isFull returns true if the stack     *
// is full, or false otherwise.                         *
//*******************************************************
template <class T>
bool Stack<T>::isFull()
{
    if (top == stackSize - 1)
        return true;
    else 
        return false;
}

//*******************************************************
//                  Stack::isEmpty                      *
// Member function isEmpty returns true if the stack    *
// Is empty, or false otherwise.                        *
//*******************************************************
template <class T>
bool Stack<T>::isEmpty()
{
    if (top == -1)
        return true;
    else 
        return false;
}

int main()
{
    Stack<double> Stack(5);
    double catchVar;

    // Demonstrate adding items to the stack
    cout << "Pushing 5.0\n";
    Stack.push(5.0);
    cout << "Pushing 10.1\n";
    Stack.push(10.1);
    cout << "Pushing 15.2\n";
    Stack.push(15.2);
    cout << "Pushing 20.3\n";
    Stack.push(20.3);
    cout << "Pushing 25.4\n";
    Stack.push(25.4);

    // Demonstrate removing items from the stack
    cout << "Popping...\n";
    Stack.pop(catchVar);
    cout << catchVar << endl;
    Stack.pop(catchVar);
    cout << catchVar << endl;
    Stack.pop(catchVar);
    cout << catchVar << endl;
    Stack.pop(catchVar);
    cout << catchVar << endl;
    Stack.pop(catchVar);
    cout << catchVar << endl;
    return 0;
}
