// Chapter 16, Assignment 5, Rotate Left
#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

template <class T>
void rotateLeft(vector <T>& v)
{
    T temp = v[0];
    int size = v.size();
    for (int k = 1; k < size; k++)
        v[k-1] = v[k];    
    v[size-1] = temp;    
}

template <class T>
void output(vector <T> v)
{
    for (int k = 0; k < v.size(); k++) 
        cout << v[k] << "  " ;   
}

int main(int argc, char** argv) 
{
    vector <int> v;
    for (int k = 1; k < 5; k++)
        v.push_back(2*k-1);
    
    
   
    
    for (int k = 0; k < v.size(); k++)
    {
        cout << k << ": ";
        output(v);        
        cout << endl;
        rotateLeft(v);
    }
    
    cout << endl;
    
    vector<string> vs;
    string  as[] = {"a", "b", "c", "d", "e"};
    for (int k = 0; k < sizeof(as)/sizeof(string); k++)
        vs.push_back(as[k]);
    
    for (int k = 0; k < vs.size(); k++)
    {
        output(vs);
        cout << endl;
        rotateLeft(vs);
    }
    return 0;
}

