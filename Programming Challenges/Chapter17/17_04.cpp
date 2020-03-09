// Chapter 17 - Assignment 4,Recursive  Member  Check
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
    friend class LinkedList;           // LinkedList has friend status	
};

class LinkedList
{
public:
    void add(double x);   
    LinkedList( ) { head = NULL;}    
    void print();
    bool isMember(double x){ return rIsMember(head, x);}   
    ~LinkedList();                     // Destructor     
private:
    ListNode * head;
    bool rIsMember(ListNode *pList, double x);
};

//*************************************
//     Recursive Member Check         *
//*************************************
bool LinkedList::rIsMember(ListNode *pList, double x)
{  
  if (pList == NULL) return false;
  if (pList->value == x) 
	  return true;
  else
      return rIsMember(pList->next, x);   
}

//**********************************
//      LinkedList.print           *
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

//*************************
//   LinkedList::add      *
//*************************
void LinkedList::add(double x)
{
    head = new ListNode(x, head);
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
	cout << "\nEnter numbers to test for list membership as prompted." << endl;
	for (int k = 1; k <= 6; k++)
	{
      double x;
	  cout << "?: ";
	  cin >> x;
	  if (list1.isMember(x))
		  cout << "Member" << endl;
	  else 
		  cout << "Not a member" << endl;
	}
    
    return 0;    
}
