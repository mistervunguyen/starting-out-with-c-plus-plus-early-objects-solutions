//  Chapter 16 -- Assignment 9, Sortable Vector Class Template
 
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

template <class T>
class SimpleVector
{
private:
    T *Aptr;
    int ArraySize;
    void SubError(void);                      // Handles subscripts out of range
 public:                                 
    SimpleVector(void)                        // Default constructor
       { Aptr = 0; ArraySize = 0;}
    SimpleVector(int);                        // Constructor
    SimpleVector(const SimpleVector &);       // Copy constructor
    ~SimpleVector(void);                      // Destructor
    int Size(void)
        { return ArraySize; }
    T &operator[](const int &);               // Overloaded [] operator

};

//***********************************************************
//         Constructor for SimpleVector class               *
// Sets the size of the array and allocates memory for it.  *
//***********************************************************
template <class T>
SimpleVector<T>::SimpleVector(int s)
{
    ArraySize = s;
    Aptr = new T [s];
    for (int count = 0; count < ArraySize; count++)
        *(Aptr + count) = 0;
}

//*********************************************
// Copy Constructor for SimpleVector class    *
//*********************************************
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &Obj)
{
    ArraySize = Obj.ArraySize;
    Aptr = new T [ArraySize];
   
    for(int count = 0; count < ArraySize; count++)
        *(Aptr + count) = *(Obj.Aptr + count);
}

//******************************************
// Destructor for SimpleVector class       *
//******************************************
template <class T>
SimpleVector<T>::~SimpleVector(void)
{
    if (ArraySize > 0)
        delete [] Aptr;
}

//***************************************************************
//                      SubError                                *
// Displays an error message and terminates the program when a  * 
// subscript is out of range.                                   *
// **************************************************************
template <class T>
void SimpleVector<T>::SubError(void)
{
    cout << "ERROR: Subscript out of range.\n";
    exit(0);
}

//*************************************************************
//             Overloaded [] operator                         *
// This function returns a reference to the element           *
// indexed by the subscript passed as parameter.              *
//*************************************************************
template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
    if (sub < 0 || sub >= ArraySize)
        SubError();
    return Aptr[sub];
}


// Sortable vector class
template <class T>
class SortableVector : public SimpleVector<T>
{
 public:
    SortableVector(int s) : SimpleVector<T>(s)           // Constructor
       { }
       SortableVector(SortableVector &);                 // Copy constructor
       SortableVector(SimpleVector<T> &Obj): SimpleVector<T>(Obj)
       { }
       void Sort();
};

//********************************
//     Copy constructor          *
//********************************
template <class T>
SortableVector<T>::SortableVector(SortableVector &Obj) : 
SimpleVector<T>(Obj.size())
{
    for(int count = 0; count < this->Size(); count++)
        this->operator[](count) = Obj[count];
}

//******************************
//  Selection sort             *
//******************************
template <class T>  
void SortableVector<T>::Sort()
{
    int StartScan, MinIndex;
    T MinValue;

    for (StartScan = 0; StartScan < (this->Size() - 1); StartScan++)
    {
        MinIndex = StartScan;
        MinValue = this->operator[](StartScan);
        for(int Index = StartScan + 1; Index < this->Size(); Index++)
        {
            if (this->operator[](Index) < MinValue)
            {
                MinValue = this->operator[](Index);
                MinIndex = Index;
            }
        }
        this->operator[](MinIndex) = this->operator[](StartScan);
        this->operator[](StartScan) = MinValue;
    }
}

int main(void)
{
    int Elems = 5;        // Arbitrary array size of 5
    SortableVector<int> intTable(Elems); 
    SortableVector<double> doubleTable(Elems); 
    
    // Store the  values in descending order
    for (int x = 0; x < Elems ; x++)
    {
        intTable[x] = Elems - x;
        doubleTable[x]= Elems - (x * 1.1f);
    }

    // Display the values
    cout << "\nBefore sorting, these values are in intTable:\n";
    for (int x = 0; x < Elems; x++)
        cout << intTable[x] << "  ";
    cout << endl;
    cout << "Before sorting, these values are in doubleTable:\n";
    for (int x = 0; x < Elems; x++)
        cout << doubleTable[x] << "  ";
    cout << endl;
    
    // Sort 
    intTable.Sort();
    doubleTable.Sort();

    // Display the values 
    cout << "\nAfter sorting, these values are in intTable:\n";
    for (int x = 0; x < Elems; x++)
        cout << intTable[x] << "  ";
    cout << endl;
    cout << "After sorting, these values are in doubleTable:\n";
    for (int x = 0; x < Elems; x++)
        cout << doubleTable[x] << "  ";
    cout << endl;

    return 0;
}
