// Chapter  19 - Assignment 1, Simple Binary Search Tree Class
 
#include <iostream>
#include <vector>
using namespace std;

// Node for binary trees items.
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
    friend class BST;                    // BST has friend status	
};    

// Binary tree class itself
class BST
{
public:
    bool search(double x) {return search (x, tree);}
    void insert(double x);
    void inorder(vector<double> & v){ inorder(v, tree);}
    BST() {tree = NULL;}
private:
    bool search(double x, BTreeNode *t);
    void inorder(vector<double>&tlist, BTreeNode *t);
    BTreeNode *tree;
};

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
    if (t->value > x) 
      return search(x, t->left);
    else
      return search(x, t->right);    
}

//******************************************
//          BST::insert                    *
// Insert x into the binary search tree,   *
// must be non-recursive.                  *
//******************************************
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
//                       BST::inorder                                *
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

int main()
{
    // Tell user what program does
    cout << "This program allows you to insert some numbers in binary search tree.";    
    cout << "\nTt prints out the numbers in the tree in inorder.";
    cout << "\nIt then allows you to test various numbers for membership in the tree.";    
    
    // Tell user to enter numbers
    BST tree1;
    cout << "\nEnter 5 numbers: \n";
    for (int k = 1; k <= 5; k++)
    {
        double x;
        cin >> x;
        tree1.insert(x);
    }
    
    // Computer the inorder list from the binary search tree
    vector<double> orderedList;
    orderedList.clear();
    tree1.inorder(orderedList);

    // Print values in inorder
    cout << "\nThe items in the tree in inorder are: \n";
    for (unsigned int k = 0; k < orderedList.size(); k++)
        cout << orderedList[k] << "  ";
    
    // Demonstrate search capability
    cout << "\nYou can search for 5 numbers: ";
    for (int k = 0; k < 5; k++)
    {
        double x;
        cout << "\nEnter a number to search for: ";
        cin >> x;
        if (tree1.search(x))
            cout << x  << " is in the tree.";
        else 
            cout << x  << " is not in the tree.";        
    }    
    return 0;    
}
