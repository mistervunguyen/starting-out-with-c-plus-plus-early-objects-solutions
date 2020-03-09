// Chapter  19 - Assignment 6, Tree Copy Constructor 
// This program adds a copy constructor  to the binary tree.
 
#include <iostream>
#include <vector>
#include <algorithm>  // For maximum of array
using namespace std;

// Node for the binary tree items
class BTreeNode
{
public:
    BTreeNode(double x, BTreeNode *leftp = NULL, 
                        BTreeNode *rightp = NULL)
    {
       value = x;
       left = leftp;
       right = rightp;
    }
private:
    double value;
    BTreeNode *left, *right;    
    friend class BST;               // BST has friend status
};


// Binary tree class itself
class BST
{
public:
    int height( ) {return height(tree);}
    bool search(double x) {return search (x, tree);}
    void insert(double x);
    void inorder(vector<double> & v){ inorder(v, tree);}
    int leafCounter( ) {return leafCounter(tree); }

    int width();
    BST() {tree = NULL;}
    BST(BST  &t);                  // Copy constructor
private:
    bool search(double x, BTreeNode *t);
    void inorder(vector<double>&tlist, BTreeNode *t);
    int leafCounter(BTreeNode *t);
    static int height(BTreeNode *t);

    // Helper function for getTreeWidth
    void registerLevel(BTreeNode *tree, int level, int registry[ ]);

    // Helper function for copy constructor
    static BTreeNode *BST::treeCopy(BTreeNode *tree);

    // Pointer to root of binary tree
    BTreeNode *tree;
};


//***************************
//      constructor         *
//***************************
BST::BST(BST &t)
{
  tree = treeCopy(t.tree);
}

//*************************************
//          BST::treeCopy             *
// Make a distinct copy of the tree.  *
//*************************************
BTreeNode *BST::treeCopy(BTreeNode *tree)
{
   if (tree == NULL)
      return NULL;
   else
      return new BTreeNode(tree->value,
                          treeCopy(tree->left),
                          treeCopy(tree->right));
}

// ******************************************************************
//                  BST::registerLevel                              *
// When this function is called, the node pointed to by tree        *
// knows that its level is level, and increments the count of       *
// nodes at that level in the registry.                             *
// ******************************************************************

void BST::registerLevel(BTreeNode *tree, int level,
                                  int registry[])
{
  if (tree)
  {
    registry[level]++;
    registerLevel(tree->left, level+1, registry);
    registerLevel(tree->right, level+1, registry);
  }
}

//*****************************************************************
//                      BST::width                                *
// To find the width of the tree, create a registry into          *
// which every node will increment the number of nodes at         *
// its level. The width of the tree is the maximum value in the   *
// registry.                                                      *
//*****************************************************************

int BST::width( )
{
   int TreeHeight = height(tree);

   // Create the registry and initialize
   int *registry = new int [TreeHeight];
   for (int level = 0; level < TreeHeight; level++)
        registry[level] = 0;

   // Populate the registry
   registerLevel(tree, 0, registry);

   // Use an STL algorithm to return the maximum value in the
   // The registry array
   int width1 = *max_element(registry, registry + TreeHeight);

   delete[ ]registry;
   return width1;
}

//*************************************************
//             BST::height                        *
// Determines the height of a binary tree.        *
//*************************************************
int BST::height(BTreeNode *t)
{
  if (t == NULL) 
     return 0;
  else
     return max(height(t->left), height(t->right)) + 1;
}

//************************************************
//           BST::leafCounter                    *
// Recursively counts the leaves in the tree.    *
//************************************************
int BST::leafCounter(BTreeNode *t )
{
    if (t == NULL) return 0;
    if (t->left == NULL && t->right == NULL) 
        return 1;
    else 
        return leafCounter(t->left) + leafCounter(t->right);    
}

//****************************************************
//              BST::search                          *
// Given a value x and a pointer to the root of a    *
// binary search tree, this function returns true    *
// is x is in the tree, and false otherwise.         *
//****************************************************
bool BST::search(double x, BTreeNode *t)
{
    if (t == NULL) return false;
    if (t->value == x) return true;
    if (t->value > x) return search(x, t->left);
    else
        return search(x, t->right);    
}

//*****************************************
//         BST::insert                    *
// Insert x into the binary search tree.  *
// Must be non-recursive.                 *
//*****************************************
void BST::insert(double x)
{
    if (tree == NULL) 
    {
        tree = new BTreeNode(x);
        return;
    }
   
    // Use p  to search for right place to insert
    // p will point to the node that will be the parent
    // of the node being added
    BTreeNode *p = tree; 
    while (p != NULL)
    {
        if (x <= p->value)
        {
            // x goes to left of p
            if (p->left == NULL)
            {                
                p->left = new BTreeNode(x);
                return;                
            }
            else
                p = p->left;            
        }
        else
        {
            // x goes to right of p
            if (p->right == NULL)
            {
                p->right = new BTreeNode(x);
                return;                
            }
            else
                p = p->right;
        }        
    }    
}

//********************************************************************
//                 BST::inorder                                      *
// This call to inorder appends all nodes in subtree rooted at t     *
// to the ordered list passed in as parameters.                      *
//********************************************************************
void BST::inorder(vector<double> & orderedList, BTreeNode *t)       
{
    if (t == NULL) return;
    inorder(orderedList, t->left);
    orderedList.push_back(t->value);
    inorder(orderedList, t->right);
}

int main( )
{

  // Create a binary search tree and store some numbers
  BST mytree;
  cout << "Enter 5 numbers:\n";
  double val;
  for (int k = 0; k < 5; k++)
    {
      cout << "?"; cin >>  val;
      mytree.insert(val);
    }
  
  // Compute  values in inorder
  vector<double> orderedList;
  orderedList.clear();
  mytree.inorder(orderedList);
   
  // Print the inorder list    
  cout << "Here is a sorted list of what you entered:\n";    
  for (unsigned int k = 0; k < orderedList.size(); k++)
        cout << orderedList[k] << "  ";
  
  // Make a copy of the tree
  cout << "\nA copy of the tree will now be made:\n";
  BST newtree(mytree);
  
  // Print the inorder list          
  orderedList.clear();
  newtree.inorder(orderedList);  
  cout << "Here is a traversal of the copy of the tree:\n";
  for (unsigned int k = 0; k < orderedList.size(); k++)
        cout << orderedList[k] << "  ";

  // Add an item to the new tree and then display the new tree in inorder
  cout << "\nEnter a value to add to the new tree:\n";
  cin >> val;
  newtree.insert(val);
  cout << "\nHere is a traversal of the new tree:\n";
  orderedList.clear();
  newtree.inorder(orderedList);
  // Print the inorder list        
  for (unsigned int k = 0; k < orderedList.size(); k++)
        cout << orderedList[k] << "  ";

  // Display the original tree
  cout << "\nHere is a traversal of the old tree:\n"; 
  orderedList.clear();
  mytree.inorder(orderedList);
  // Print the inorder list        
  for (unsigned int k = 0; k < orderedList.size(); k++)
        cout << orderedList[k] << "  "; 

  return 0;
}
