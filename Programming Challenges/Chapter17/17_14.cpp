//Chapter 17 - Assignment 14, Read, Merge, Sort
// This program reads in 2 sequences of numbers, stores them in linked lists,
// sorts the two lists, and then merges the resulting sorted lists to form one 
// long sorted linked list.


#include <iostream>
using namespace std;

struct ListNode
{
   double value;
   ListNode *next;
   ListNode(double v, ListNode *n) : value(v), next(n) {}
};

ListNode *read();
ListNode *sort(ListNode* list1);
ListNode *merge(ListNode* list1, ListNode* list2);
void print(ListNode *);


int main()
{
   // Enter first list
   cout << "Enter a list of space-separated positive numbers, terminate with -1:\n ";
   ListNode *list1 = read();
   cout << "You entered: ";
   print(list1);

   // sort first list
   list1 = sort(list1);
   cout << "The sorted list is: ";
   print(list1);


   // Enter second list
   cout << "Enter a list of number, terminate with -1: \n";
   ListNode *list2 = read();
   cout << "You entered: ";
   print(list2);

   // sort second list
   list2 = sort(list2);
   cout << "The sorted list is: ";
   print(list2);

   // merge the two lists
   ListNode *mergeList = merge(list1, list2);
   cout << "The merged list is:\n";
   print(mergeList);
   
}


//********************************************************
//                   read                                *
//     Reads a sequence of space-separated positive      *
//     integers and forms them into a linked list        *
//********************************************************
ListNode *read()
{
   double v;
   ListNode* result = nullptr;
   while (cin >> v)
   {
      if (v < 0) return result;
      result = new ListNode(v, result);
   }
   return result;
}


//************************************************************
//                print                                      *
//  prints a linked list of numbers                          *
//************************************************************
void print(ListNode *aList)
{
   while (aList)
   {
      cout << aList->value << " ";
      aList = aList->next;
   }
   cout << endl;
}

//***********************************************************
//                insert                                    *
//  inserts a node into a linked list list1 that is a       *
//  already stored so that the resulting list is sorted.    *
//  The function returns the resulting sorted list.         *
//***********************************************************
ListNode *insert(ListNode *list1, ListNode *node)
{
   if (list1 == nullptr) return node;
   if (node->value <= list1->value)
   {
      node->next = list1;
      return node;
   }

   list1->next = insert(list1->next, node);
   return list1;
}


//**********************************************************
//             sort                                        *
// Creates and returns a sorted list by repeatedly         *
// inserting nodes from list1 into an initially empty      *
// list, keeping the accumulator list in sorted form at    *
// all times.                                              *
//**********************************************************
ListNode *sort(ListNode *list1)
{
   ListNode *sortedList = nullptr;
   while (list1)
   {
      ListNode* aNode = list1;
      list1 = list1->next;
      aNode->next = nullptr;
      sortedList = insert(sortedList, aNode);
   }
   return sortedList;
}


//*****************************************************************************
//                    merge                                                   *
//  Takes nodes from list1 and list2, which are assumed to be sorted,         *
//  and successively adds them to an initially empty list mergeList, keeping  *
//  mergeList in sorted form at all times.                                    *
//*****************************************************************************
ListNode* merge(ListNode *list1, ListNode *list2)   
{
   ListNode *mergeList = nullptr;
   ListNode *last = nullptr;   // Where to add new node on mergeList

   if (!list1 && !list2) return nullptr;

   // Could one of the lists be empty?
   if (!list1)
   {
      return list2;
   }
  
   if (!list2)
   {
      return list1;
   }

   // Both lists not empty, so put the first node on mergelist
   if (list1->value <= list2->value)
   {
      mergeList = list1;
      last = mergeList;    
      list1 = list1->next;
      last->next = nullptr;
   }
   else
   {
      mergeList = list2;
      last = mergeList;  
      list2 = list2->next;
      last->next = nullptr;
   }

   while (true)
   {
      if (!list1)
      {
         last->next = list2;
         return mergeList;
      }
      if (!list2)
      {
         last->next = list1;
         return mergeList;
      }

      // list 1 nonempty and list2 non empty
      if (list1->value <= list2->value)
      {
         last->next = list1;
         list1 = list1->next;
         last = last->next;
         last->next = nullptr;
      }
      else
      {
         last->next = list2;
         list2 = list2->next;
         last = last->next;
         last->next = nullptr;
      }
   }
   return mergeList;
}