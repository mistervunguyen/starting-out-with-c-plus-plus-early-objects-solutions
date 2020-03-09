// Chapter 19 - Assignment 10, Prefix Representation of Binary Trees.
// This program builds a binary tree with 5 nodes.
// The deleteNode function is used to remove 2 of them.
#include <iostream>
#include "IntBinaryTree.h"
using namespace std;

int main()
{
   IntBinaryTree tree;

   cout << "Here is the tree in prefix tree form:\n";
   tree.treePrint();
   cout << endl;
   

   cout << "Inserting the numbers 5 8 3 12 9.";
   tree.insert(5);
   cout << "\nHere is the tree in prefix tree form:\n";
   tree.treePrint();
   cout << endl;
 
   tree.insert(8);
   cout << "\nHere is the tree in prefix tree form:\n";
   tree.treePrint();
   cout << endl;

   tree.insert(3);
   cout << "\nHere is the tree in prefix tree form:\n";
   tree.treePrint();
   cout << endl;

   tree.insert(12);
   cout << "\nHere is the tree in prefix tree form:\n";
   tree.treePrint();
   cout << endl;

   tree.insert(9);  
   cout << "\nHere is the tree in prefix tree form:\n";
   tree.treePrint();
   cout << endl;

   cout << "\nDeleting 8...\n";
   tree.remove(8);

   cout << "\nHere is the tree in prefix tree form:\n";
   tree.treePrint();
   cout << endl;

   cout << "Deleting 12...\n";
   tree.remove(12);

   cout << "\nHere is the tree in prefix tree form:\n";
   tree.treePrint();
   cout << endl;   

   cout << endl;
   return 0;
}