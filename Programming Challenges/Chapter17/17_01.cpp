// Chapter 17 - Assignment 1, Simple Linked List Class
// This program creates and uses a simple linked list 
// class with member functions for adding items to the list
// and checking items for membership.
 
#include <iostream>
using namespace std;

// The Node for the list items
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
    friend class LinkedList;    // LinkedList  has friend status	
};

// The linked list class itself
class LinkedList
{
public:
    void add(double x);
    bool isMember(double x);
    LinkedList( ) { head = NULL;}
    ~LinkedList();
private:
    ListNode * head;    
};

//*************************************
//        LinkedList::add             *
//  Adds a given value to the list.   *
//*************************************
void LinkedList::add(double x)
{
    head = new ListNode(x, head);
}

//***********************************************************
//          LinkedList::isMember                            *
// Checks to see if a given value is a member of the list.  *
//***********************************************************
bool LinkedList::isMember(double x)
{
    ListNode *p = head;     // Use p to walk through list
    while (p != NULL)
    {
        if (p->value == x) 
            return true;
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
    cout << "This program constructs a list of numbers and then allows the user "
         <<  "\nto check if various numbers are on the list.";

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

    // Allow user to test membership
    for (int k = 1; k <= 5; k++)
    {   
        double x;
        cout << "Enter a number to test membership for: ";
        cin >> x;
        if (list1.isMember(x))
            cout << "\n" << x << " is on the list." << endl;
        else
            cout << "\n" << x << " is not on the list." << endl;        
    }

    return 0;    
}
