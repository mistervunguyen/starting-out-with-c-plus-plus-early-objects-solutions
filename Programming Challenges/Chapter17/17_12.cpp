// Chapter 17, Assignment 12, Recursive Generation of Subsets
#include <cstdlib>
#include <list>
#include <vector>
#include <iostream>

using namespace std;

// Prototypes
// Function for computing list of subsets
list<vector<int> > getSubsets(int n);
// Overloaded stream insertion operator
ostream &operator <<(ostream &out, vector<int> v);
// Overloaded stream insertion operator for outputting a list of a generic type
template <class T>
ostream &operator <<(ostream &out, list<T> alist);

int main (int argc, char** argv)
{ 
  int size;
  while (true)
  {
     cout << "Enter an integer in the range 0..4, outside this range to terminate:";
     cin >> size;
     if (size < 0 || size > 4) break;
     list<vector<int> > slist = getSubsets(size);
     cout << "The list of subsets of 1.." << size << " is:" << endl;
     cout << slist << endl;
  } 
  return 0;
}

//*********************************************************
// Overloaded stream insertion operator for vector of int *
//*********************************************************
ostream &operator <<(ostream &out, vector<int> v)
{
  out << "[";
  for (int k = 0; k < v.size(); k++)
    {
      out << v[k] ;
      if (k < v.size()-1) out << ", ";
    }
   out << "]";
  return out;
}

//***********************************************************
// Overloaded insertion operator for a list of generic type *
//***********************************************************
template <class T>
ostream &operator <<(ostream &out, list<T> alist)
{
  out << "[";
  typename  list<T>::iterator it = alist.begin();
  while ( it != alist.end() )
    {
      out << *it ;
      it ++;
      if (it != alist.end()) out << ", ";  
    }
  out << "]";
  return out;
}

//************************************************
// Compute and return the list of all subsets of *
// the set 1..n where n is a parameter.          *
//************************************************
list<vector<int> > getSubsets(int n)
{ 
  list<vector<int> > subsetList;   // list of subsets
  if (n == 0)
  {   
      subsetList.push_back(vector<int>()); 
      return  subsetList;
  }
  // Non base case: first get list of all subsets of 1..(n-1)
  subsetList = getSubsets(n-1);
  
  // Create an extended list of subsets  of 1..n
  list<vector<int> > biggerList;   
  list<vector<int> >::iterator it = subsetList.begin ();
  while (it != subsetList.end())
  {
     // for each subset *it, create subsets x and x1 
     // to exclude and include k, and add them to biggerList
     vector<int> x = *it;
     vector<int> x1 = *it;
     x1.push_back(n);
     biggerList.push_back(x);
     biggerList.push_back(x1);
     it ++;         
  }
  return biggerList;  
}

