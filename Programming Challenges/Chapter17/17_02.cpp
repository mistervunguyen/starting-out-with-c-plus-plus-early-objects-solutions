// Chapter 17 - Assignment 2, List Copy Constructor
 
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
    friend class LinkedList; // LinkedList  has friend status	
};

// The linked list class itself
class LinkedList
{
public:
    LinkedList(LinkedList &list1);
    void add(double x);
    bool isMember(double x);
    LinkedList( ) { head = NULL;}
    ~LinkedList( );            // Destructor
private:
    ListNode * head;
    static ListNode *makeCopy(ListNode *pList);
};

//*********************************************
//        LinkedList::makeCopy                *
//  makeCopy creates  distinct copy of list.  *
//*********************************************
ListNode  *LinkedList::makeCopy(ListNode *pList)
{
  if (pList == NULL) return NULL;
  else
    return new ListNode(pList->value, makeCopy(pList->next));
}

//****************************
//     Copy constructor      *
//****************************
LinkedList::LinkedList(LinkedList &list1)
{
   head = makeCopy(list1.head);
}

//***************************
//    LinkedList::add       *
//***************************
void LinkedList::add(double x)
{
    head = new ListNode(x, head);
}

//****************************
//   LinkedList::isMember    *
//****************************
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
    cout << "This program constructs a list of numbers, then constructs a copy, and allows "
         <<  "\nto check if various numbers are on copy of the list.";

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

    // Make a copy using copy constructor  
    LinkedList list2(list1);

    // Allow user to test membership
    for (int k = 1; k <= 5; k++)
    {   
        double x;
        cout << "Enter a number to test membership for: ";
        cin >> x;
        if (list2.isMember(x))
            cout << "\n" << x << " is on the copy of the list." << endl;
        else
            cout << "\n" << x << " is not on the copy of the  list." << endl;        
    }
    return 0;    
}
