#include <iostream>
#include <sstream>
#include "IntBinaryTree.h"
using namespace std;

//**************************************************
// This version of insert inserts a number into    *
// a given subtree of the main binary search tree. *
//**************************************************
void IntBinaryTree::insert(TreeNode * &tree, int num)
{
   // If the tree is empty, make a new node and make it 
   // the root of the tree.
   if (!tree)
   {
      tree = new TreeNode(num);
      return;
   }

   // If num is already in tree: return.
   if (tree->value == num)
      return;

   // The tree is not empty: insert the new node into the
   // left or right subtree.
   if (num < tree->value)
      insert(tree->left, num);
   else
      insert(tree->right, num);
}

//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree.                   *
//***************************************************
void IntBinaryTree::destroySubtree(TreeNode *tree)
{
   if (!tree) return;
   destroySubtree(tree->left);
   destroySubtree(tree->right);
   // Delete the node at the root.
   delete tree;
}

//***************************************************
// searchNode determines if a value is present in   *
// the tree. If so, the function returns true.      *
// Otherwise, it returns false.                     *
//***************************************************
bool IntBinaryTree::search(int num) const
{
   TreeNode *tree = root;

   while (tree)
   {
      if (tree->value == num)
         return true;
      else if (num < tree->value)
         tree = tree->left;
      else
         tree = tree->right;
   }
   return false;
}

//********************************************
// remove deletes the node in the given tree *
// that has a value member the same as num.  *
//********************************************
void IntBinaryTree::remove(TreeNode *&tree, int num)
{
   if (tree == nullptr) return;
   if (num < tree->value)
      remove(tree->left, num);
   else if (num > tree->value)
      remove(tree->right, num);
   else
      // We have found the node to delete.
      makeDeletion(tree);
}

//***********************************************************
// makeDeletion takes a reference to a tree whose root      *
// is to be deleted. If the tree has a single child, the    *
// the tree is replaced by the single child after the       *    
// removal of its root node. If the tree has two children   *
// the left subtree of the deleted node is attached at      *
// an appropriate point in the right subtree, and then      *
// the right subtree replaces the original tree.            *
//***********************************************************
void IntBinaryTree::makeDeletion(TreeNode *&tree)
{
   // Used to hold node that will be deleted.
   TreeNode *nodeToDelete = tree;

   // Used to locate the  point where the 
   // left subtree is attached.
   TreeNode *attachPoint;

   if (tree->right == nullptr)
   {
      // Replace tree with its left subtree. 
      tree = tree->left;
   }
   else if (tree->left == nullptr)
   {
      // Replace tree with its right subtree.
      tree = tree->right;
   }
   else
      //The node has two children
   {
      // Move to right subtree.
      attachPoint = tree->right;

      // Locate the smallest node in the right subtree
      // by moving as far to the left as possible.
      while (attachPoint->left != nullptr)
         attachPoint = attachPoint->left;

      // Attach the left subtree of the original tree
      // as the left subtree of the smallest node 
      // in the right subtree.
      attachPoint->left = tree->left;

      // Replace the original tree with its right subtree.
      tree = tree->right;
   }

   // Delete root of original tree
   delete nodeToDelete;
}

//*********************************************************
// This function displays the values  stored in a tree    *  
// in inorder.                                            *
//*********************************************************
void IntBinaryTree::displayInOrder(TreeNode *tree) const
{
   if (tree)
   {
      displayInOrder(tree->left);
      cout << tree->value << "  ";
      displayInOrder(tree->right);
   }
}

//*********************************************************
// This function displays the values stored in a tree     *
// in inorder.                                            *
//*********************************************************
void IntBinaryTree::displayPreOrder(TreeNode *tree) const
{
   if (tree)
   {
      cout << tree->value << "  ";
      displayPreOrder(tree->left);
      displayPreOrder(tree->right);
   }
}

//*********************************************************
// This function displays the values  stored  in a tree   *
// in postorder.                                          * 
//*********************************************************
void IntBinaryTree::displayPostOrder(TreeNode *tree) const
{
   if (tree)
   {
      displayPostOrder(tree->left);
      displayPostOrder(tree->right);
      cout << tree->value << "  ";
   }
}


//*********************************************************
// This function displays the values  stored  in a tree   *
// in prefix type display.                                * 
//*********************************************************
void IntBinaryTree::treePrint(TreeNode *tree,  ostream& out) const
{
   if (!tree) { out << "_"; return; }
   else
   {
      ostringstream left_strstream;
      ostringstream right_strstream;

      treePrint(tree->left, left_strstream);
      treePrint(tree->right, right_strstream);
      out << "(" << tree->value << left_strstream.str() <<"," << right_strstream.str() << ")";
   }
}
