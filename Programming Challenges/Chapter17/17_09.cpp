// Chapter 17 - Assignment 9, Member Removal by Position
// This program adds the capability to delete nodes by position.
 
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
    friend class LinkedList;        // LinkedList has friend status	
};

class LinkedList
{
public:
    void add(double x);
    bool isMember(double x);
    LinkedList( ) { head = NULL;}    
    void print();
    void rPrint(){ rPrint(head);}
    ~LinkedList();
    void remove(double x);
    void reverse( );
    int search(double x);
    void insert(double x, int pos);
    void removeByPos(int pos);        
private:
    ListNode * head;
    static void rPrint(ListNode *pList);  
};

//**********************************************************
//           LinkedList::removeByPos                       *
// Removes and deletes the list node at a given position.  *
//**********************************************************
void LinkedList::removeByPos(int pos)
{
  // pos is number of nodes to skip   
  ListNode *p = head;
  if (p == NULL) return;
  while (pos > 0 && p)
  {
     // Skip
     p = p->next;
     pos--;
  }

  // p now points to the nod that should be deleted
  if (p == head)
     {
        head = head->next;
        delete p;
        return;
     }
  else
    {
      if (p == NULL) return; // Nothing to do: pos was too big

      // Need to delete p: Use trailer pointer to come up 
      // behind p and then delete it      
      ListNode *trailer = head;
      while (trailer->next != p)
         trailer = trailer->next;
      trailer->next = p->next;
      delete p;
    }
}

//**********************************************************
//              LinkedList::insert                         *
//  Insert a given value at a specified position.          *
//**********************************************************
void LinkedList::insert(double x, int pos)
{
    // Cases where the new value goes at the beginning
    // or when the list is empty are handled separately
    if (pos == 0 || head == NULL) 
    {
        head = new ListNode(x, head);
        return;
    }

    // Figure out how many nodes to skip before splicing
    // in a new node
    ListNode *p = head;                  // p is used to walk down the list
    int numberToSkip = 1;  
    while (numberToSkip <= pos)
    {
       if (p->next == NULL || numberToSkip == pos)
       {              
           p->next = new ListNode(x, p->next); 
           return;
       }
       // Not at end and have not skipped enough
       // So skip another one
       p = p->next;
       numberToSkip++;
    }
}

//*************************************************************
//               LinkedList::search                           *            
// Searches the linked list for a given value and returns     *
// its position in the list if found. Otherwise, it           *
// returns -1.                                                *
//*************************************************************
int LinkedList::search(double x)
{
  int position = 0;
  ListNode *p = head;   // Used to search through nodes
  while (p)
  {
    if (p->value == x) return position;
    p = p->next;
    position ++;
  }
  return -1;            // Not found
}

//********************************************************************
//                     LinkedList::reverse                           *
// Rearranges the elements of the list to put them in reverse order. *
//********************************************************************
void LinkedList::reverse()
{
  ListNode *rev = NULL; // Holds list being reversed
  ListNode *p = head;   // Traverses nodes of original list
  ListNode *mover;      // Used to move noded from original list to the new list

  while (p)
  {
    // Move node at p to the beginning of the new list rev being constructed
    mover = p;
    p = p->next;
    mover->next = rev;
    rev = mover;
  }
  head = rev;
}

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
    cout << "This program allows you to construct a list by specifying list member and positions.";
    cout << "\nYou can delete list items by position.";        
    cout << "\nYou can then remove items by postion.";

    // Create empty list
    LinkedList list1;     

    // Demonstrate insert by position        
    for (int k  = 1; k <= 5; k++)
    {
       cout << "\nEnter a number followed by a position: ";
       int x, pos;
       cin >> x >> pos;
       list1.insert(x, pos);
       cout << "\nCurrent list membership is: ";
       list1.rPrint();         
    }

    // Demonstrate delete by position.
    for (int k = 1; k <= 5; k++)
    {
        cout << "\nEnter a position to delete: ";
        int pos;
        cin >> pos;
        list1.removeByPos(pos);
        cout << "\nCurrent list membership is: ";
        list1.rPrint();
    }

    return 0;    
}
