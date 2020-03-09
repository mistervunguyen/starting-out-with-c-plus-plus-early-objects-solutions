// Chapter 16, Assignment 6,  Template Reversal
#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>   // Needed for swap in reverse
using namespace std;

//********************************************************
// Rotates the vector circularly one place to the left.  *
//********************************************************
template <class T>
void rotateLeft(vector <T>& v)
{
    T temp = v[0];
    int size = v.size();
    for (int k = 1; k < size; k++)
        v[k-1] = v[k];    
    v[size-1] = temp;    
}

//**********************************************************
// Output the contents of the vector                       *
//**********************************************************
template <class T>
void output(vector <T> v)
{
    for (int k = 0; k < v.size(); k++) 
        cout << v[k] << "  " ;   
}

//**********************************************************
// Reverse the contents of the vector                       *
//**********************************************************
template <class T>
void reverse(vector <T>& v)
{
    int size = v.size();
    int middle = size / 2;
    for (int k = 0; k < middle; k++) 
    {
      swap(v[k], v[size-1-k]);
    }
}

int main(int argc, char** argv) 
{
    // Initialize a vector of 5 integers
    vector <int> v;
    for (int k = 1; k < 5; k++)
    {    
       v.push_back(2*k-1); 
    }
    // Reverse the vector and output
    cout << "Original vector is " ;
    output(v);
    reverse(v);
    cout << "\nReversed vector is ";
    output(v);
    cout << endl;  
    // Initialize a vector of strings
    vector<string> vs;
    string  as[] = {"a", "b", "c", "d", "e"};
    for (int k = 0; k < sizeof(as)/sizeof(as[0]); k++)
    {
       vs.push_back(as[k]);
    }
    // Reverse the vector and output
    cout << "Original vector is " ;
    output(vs);
    reverse(vs);
    cout << "\nReversed vector is ";
    output(vs);
    cout << endl;      
    return 0;
}

