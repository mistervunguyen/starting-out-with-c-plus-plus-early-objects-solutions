// Chapter 17 - Assignment 5, List  Member Deletion
// This program adds a list deletion capability and a destructor to the 
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
    friend class LinkedList;         // LinkedList has friend status	
};

class LinkedList
{
public:
    void add(double x);
    bool isMember(double x);
    LinkedList( ) { head = NULL;}    
    void print();
    void rPrint(){ rPrint(head);}     // Recursive version of print
    ~LinkedList();                    // Destructor
    void remove(double x);        
private:
    ListNode * head;
    static void rPrint(ListNode *pList);
};

//***********************************
//        Destructor                *
//***********************************
LinkedList::~LinkedList( )
{
   ListNode *p = head;
   ListNode *q;  // Next pointer
   while (p != NULL)
   {
      q = p->next;
      delete p;
      p = q;
   }
}

//************************************************************
//              LinkedList::remove                           *
// Removes a value passes as parameter from the linked list. *
//************************************************************
void LinkedList::remove(double x)
{
    ListNode *garbage;             // Use to delete nodes
    if (head == NULL) return;

    // Is x in the head?
    if (head->value == x)
    {
        garbage = head;
        head = head->next;
        return;
    }

    // x not in the head, find it
    ListNode *p = head;
    while (p->next != NULL && p->next->value != x)
    {
       p = p->next;
    }

    // p->next == NULL or p->next->value is x
    if (p->next == NULL) return;    // Did not find it
    else
      {
        // Delete the x
        garbage = p->next;
        p->next = garbage->next;
        delete garbage;
      }
}

//******************************************************
//            Recursive print function                 *
//  Prints all elements on a list passed as parameter. *
//******************************************************
void LinkedList::rPrint(ListNode *pList)
{
  if (pList == NULL) return;
  else
   {
      cout << pList->value << "  ";
      rPrint(pList->next);
   }
}

//***********************************
//     LinkedList::print            *
// Prints all elements on the list. *
//***********************************
void LinkedList::print()
{
    ListNode *p = head;             // Use to walk down list
    while (p != NULL)
    {
        cout << p->value << " ";
        p = p->next;
    }
}

//**********************************
//     LinkedList::add             *
// Adds a given value to the list. *
//**********************************
void LinkedList::add(double x)
{
    head = new ListNode(x, head);
}

//***********************************************************
//            LinkedList::isMember                          *
// Checks to see if a given value is a member of the list.  *
//***********************************************************
bool LinkedList::isMember(double x)
{
    ListNode *p = head;              // Use p to walk through list
    while (p != NULL)
    {
        if (p->value == x) return true;
        else
            p = p->next;        
    }
    // List is exhausted without finding x
    return false;    
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
    list1.rPrint();
    cout << endl;   
 
    // Demonstrate removal
    for (int k = 1; k <= 5; k++)
    {
       int number;
       cout << "\nEnter a number to remove: ";
       cin >> number;
       list1.remove(number);
       cout << "Remaining list is: ";
       list1.rPrint();
     }

    return 0;    
}
