// Chapter 17 - Assignment 3,  List  Print
// This program adds a print member function to the Simple
// Linked List Class.
#include <iostream>
using namespace std;
 
class ListNode
{
public:
    ListNode(double v, ListNode *p)
    {
        value = v; next = p;
    }
private:    
    double value;
    ListNode *next;
    friend class LinkedList;   // LinkedList has friend status	
};

class LinkedList
{
public:
    void add(double x);
    bool isMember(double x);
    LinkedList( ) { head = NULL;}    
    void print();        
    ~LinkedList();             // Destructor
private:
    ListNode * head;
    static void rPrint(ListNode *pList);  
};

//**********************************
//    LinkedList.print             *
// Prints all values in the list.  *
//**********************************
void LinkedList::print()
{
    ListNode *p = head; // Use to walk down list
    while (p != NULL)
    {
        cout << p->value << " ";
        p = p->next;
    }
}

//**********************************
//       LinkedList::add           *
// Adds a give value to the list.  *
//**********************************
void LinkedList::add(double x)
{
    head = new ListNode(x, head);
}

//***********************************************************
//              LinkedList::isMember                        *
// Checks to see if a given value is a member of the list.  *
//***********************************************************
bool LinkedList::isMember(double x)
{
    ListNode *p = head; // Use p to walk through list
    while (p != NULL)
    {
        if (p->value == x) return true;
        else
            p = p->next;        
    }
    // List is exhausted without finding x
    return false;    
}

//******************************************
//         Destructor                      *
// Deallocates memory for the list.        *
//******************************************
LinkedList::~LinkedList()
{
   while (head != 0)
   {
       ListNode * p = head;
       head = head->next;
       delete p;
   }
}

int main( )
{
    // Explain program to user
    cout << "This program constructs a list of numbers and then prints the list.";

    // Create empty list
    LinkedList list1;
    // Get input from user and add them to list
    cout << "\nEnter 5 numbers: ";
    for (int k = 1; k <= 5; k++)
    {   
        double x;
        cin >> x;
        list1.add(x);
    }

    // Print the list
    cout << "The list you entered is : " << endl;
    list1.print();
    cout << endl;    
    
    return 0;    
}
