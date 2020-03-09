//  Chapter 19--  Assignment 8, Employee Tree
 
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure for Employee class
struct Employee
{
    int id;
    string name;        
    Employee(int id = 0, string name = "")
    {
        this->id = id; 
        this->name = name;
    }
};

//*****************************************************************
//         operator<(Employee, Employee)                          *
// Overload the less than operator to allow Employee to be used   *
// with the binary tree template.                                  *
//*****************************************************************
bool operator <(Employee x, Employee y)
{
    return x.id < y.id;
}

//*******************************************************************
//        operator==(Employee x, Employee y)                        *
// Overload the equality testing operator to allow the search       *
// member function of the binary tree to work with Employee.        *
//*******************************************************************
bool operator ==(Employee x, Employee y)
{
    return x.id == y.id;
}

//*****************************************************************
//          operator << (ostream &, Employee                      *
// Overload the stream insertion operator so we can do IO.        *
//*****************************************************************
ostream & operator<<(ostream &out , Employee e)
{
    out << "id: " << e.id <<  "\tName: " << e.name;
    return out;
}        

// Binary tree class itself. The node is defined inside the binary
// search tree for better integration with templates

// Note:  search has been modified to return the address of the value
// found in the tree.
template <class T>
class BST
{    
    // The node class
    class BTreeNode
    {
    public:
        BTreeNode(T x, BTreeNode *leftp = NULL, 
                  BTreeNode *rightp = NULL)
        {
            value = x;
            left = leftp;
            right = rightp;
        }
        T value;
        BTreeNode *left, *right; 
    };   
// The rest of the binary search tree declaratiion   
public:
    T *search(int  key) {return search (key, tree);}
    void insert(T x);
    void inorder(vector<T> & v){ inorder(v, tree);}
    BST() {tree = NULL;}
private:
    T *search(int key, BTreeNode *t);
    void inorder(vector<T>&tlist, BTreeNode *t);
    BTreeNode *tree;
};

// Here is the "database of Employees
Employee emp [ ] = { Employee(1021, "John Williams"),
                     Employee(1057, "Bill Witherspoon"),
                     Employee(2487, "Jennifer Twain"),
                     Employee(3769, "Sophia Lancaster"),
                     Employee(1017, "Debbie Reece"),
                     Employee(1275, "George McMullen"),
                     Employee(1899, "Ashley Smith"),
                     Employee(4218, "Josh Plemmons"),
                   };

int main()
{
    // Create the treee of employees
    BST<Employee> employee_tree;
    
    // Add all the employees originally in the emp array to the tree
    int numberOfEmployees = sizeof(emp)/sizeof(emp[0]);
    for (int k = 0; k < numberOfEmployees; k++)
        employee_tree.insert(emp[k]);   
    
    // Tell user what the program does
    cout << "This program has an internal database of employees, " << endl
         << "with each employee having a name and an integer id." << endl
         << "The program will tell you an employee's name if you give it the " 
         << endl << "employee's number.";
    
    // Display the employees stored in the tree
    vector<Employee> emp_vector;
    employee_tree.inorder(emp_vector);
    cout << endl;
    for (int k = 0; k < emp_vector.size(); k++)
        cout << emp_vector[k] << endl;
    
    // Allow user to search for employees based on id
    cout << "Enter employee id  as prompted to see the name, "
         << "enter -1 to terminate.\n";   
    while (true)
    {
        cout << "id? ";
        int id;
        cin >> id;
        if (id < 0)  exit(0);        
        Employee *p_emp = employee_tree.search(id);
        if (p_emp == NULL)
            cout << "There is no employee with id " << id << endl;
        else
            cout << *p_emp << endl;        
    }
    
    return 0;    
}

// Implementation of Binary Search Tree member functions

//**********************************************************************
//                            BST::search                              *
// Given a value x and a pointer to the root of a  binary search tree, *
// this function returns the address of the data item with key x if    *
// it finds a data item with key x, it returns NULL otherwise.         *
// is x is in the tree, and false otherwise.                           *
//**********************************************************************
template<class T>
T *BST<T>::search(int x, BTreeNode *t)
{
    if (t == NULL) return NULL;
    if (t->value == x) return &t->value;
    if (x < t->value) 
      return search(x, t->left);
    else
      return search(x, t->right);    
}

//******************************************
//          BST::insert                    *
// Insert x into the binary search tree,   *
// must be non-recursive.                  *
//******************************************
template <class T>
void BST<T>::insert(T x)
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
        if (x < p->value)
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
template <class T>
void BST<T>::inorder(vector<T> & orderedList, BTreeNode *t)       
{
    if (t == NULL) return;
    inorder(orderedList, t->left);
    orderedList.push_back(t->value);
    inorder(orderedList, t->right);
}
