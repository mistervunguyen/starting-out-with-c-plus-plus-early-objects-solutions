//  Chapter 16 -- Assignment 8:  SearchableVector Class Modification

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
 
template <class T>
class SimpleVector
{
private:
    T *aptr;
    int arraySize;
    void subError();                        // Handles subscripts out of range.
 public:
    SimpleVector()                          // Default constructor
       { aptr = 0; arraySize = 0;}
    SimpleVector(int);                      // Constructor
    SimpleVector(const SimpleVector &);     // Copy constructor
    ~SimpleVector();                        // Destructor
    int size()
        { return arraySize; }
    T &operator[](const int &);             // Overloaded [] operator

};
//***************************************************************
//      Constructor for SimpleVector class                      * 
// Sets the size of the array and allocates memory for it.      *   
//***************************************************************
template <class T>
SimpleVector<T>::SimpleVector(int s)
{
    arraySize = s;
    aptr = new T [s];
    for (int count = 0; count < arraySize; count++)
        *(aptr + count) = 0;
}
//***********************************************************
// Copy Constructor for SimpleVector class                  *
//***********************************************************
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
    arraySize = obj.arraySize;
    aptr = new T [arraySize];
    if (aptr == 0)
        memError();
    for(int count = 0; count < arraySize; count++)
        *(aptr + count) = *(obj.aptr + count);
}

//******************************************
// Destructor for SimpleVector class       *
//******************************************
template <class T>
SimpleVector<T>::~SimpleVector()
{
    if (arraySize > 0)
        delete [] aptr;
}

//*************************************************************
//                SubError function                           *
// Displays an error message and terminates the program when  *
// a subscript is out of range.                               *
//*************************************************************
template <class T>
void SimpleVector<T>::subError()
{
    cout << "ERROR: Subscript out of range.\n";
    exit(0);
}

//***********************************************************
//                Overloaded [] operator                    *                  
// The argument is a subscript. his function returns a      *
// reference to the element in the array indexed by the     *
// subscript.                                               *
//***********************************************************
template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
    if (sub < 0 || sub >= arraySize)
        subError();
    return aptr[sub];
}

// //////////////////////////////////
// Sortable vector class
// //////////////////////////////////

template <class T>
class SortableVector : public SimpleVector<T>
{
 public:
    SortableVector(int s) : SimpleVector<T>(s) // Constructor
       { }
       SortableVector(SortableVector &);       // Copy constructor
       SortableVector(SimpleVector<T> &obj): SimpleVector<T>(obj)
       { }
       void sort();
};

//*********************
// Copy Constructor   *
//*********************
template <class T>
SortableVector<T>::SortableVector(SortableVector &obj) : 
SimpleVector<T>(obj.size())
{
    for(int count = 0; count < this->size(); count++)
        this->operator[](count) = obj[count];
}

//***********************
// Selection sort       *
//***********************
template <class T> 
void SortableVector<T>::sort()
{
    int startScan, minIndex;
    T minValue;

    for (startScan = 0; startScan < (this->size() - 1); startScan++)
    {
        minIndex = startScan;
        minValue = this->operator[](startScan);
        for(int index = startScan + 1; index < this->size(); index++)
        {
            if (this->operator[](index) < minValue)
            {
                minValue = this->operator[](index);
                minIndex = index;
            }
        }
        this->operator[](minIndex) = this->operator[](startScan);
        this->operator[](startScan) = minValue;
    }
}

////////////////////////////////////
// Searchable vector class
////////////////////////////////////

template <class T>
class SearchableVector : public SortableVector<T>
{
 public:
    SearchableVector(int s) : SortableVector<T>(s)    // Constructor
       { }
       SearchableVector(SearchableVector &);          // Copy constructor
       SearchableVector(SimpleVector<T> &obj): SortableVector<T>(obj)
       { }
       int sortAndSearch(T);
};

template <class T>
SearchableVector<T>::SearchableVector(SearchableVector &obj) : 
SortableVector<T>(obj.size())
{
    for(int count = 0; count < this->size(); count++)
        this->operator[](count) = obj[count];
}

//****************************************
//          sortAndSearch                *
// Selection sort and binary search.     *
//****************************************
template <class T>  
int SearchableVector<T>::sortAndSearch(T item)
{
    SortableVector<T>::sort();
    int first = 0;
    int last = this->size() - 1;
    int middle;

    while (first <= last)
    {
        middle = first + (last - first) / 2;
        if (this->operator[](middle) == item)
            return middle;
        else if (this->operator[](middle) > item)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return -1;  
}

int main()
{
    int elems = 5;  // Arbitrary array size of 5
    SearchableVector<int> intTable(elems); 
    SearchableVector<double> doubleTable(elems); 
    int x, result1, result2;

    // Place values into the arrays in descending order
    for (x = 0; x < elems ; x++)
    {
        intTable[x] = elems - x;
        doubleTable[x]= elems - (x * 1.0f);
    }

    // Display the values in the arrays.
    cout << "\nBefore calling SortAndSearch(), these values are in IntTable:\n";
    for (x = 0; x < elems; x++)
        cout << intTable[x] << "  ";
    cout << endl;
    cout << "Before calling SortAndSearch(),these values are in doubleTable:\n";
    for (x = 0; x < elems; x++)
        cout << doubleTable[x] << "  ";
    cout << endl;
    
    // Call the function -- search for 5 and 3.0
    result1 = intTable.sortAndSearch(5);
    result2 = doubleTable.sortAndSearch(3.0);

    // Display results of sort
    cout << "\nAfter calling SortAndSearch(), these values are in IntTable:\n";
    for (x = 0; x < elems; x++)
        cout << intTable[x] << "  ";
    cout << endl;
    cout << "After calling SortAndSearch(),these values are in doubleTable:\n";
    for (x = 0; x < elems; x++)
        cout << doubleTable[x] << "  ";
    cout << endl;

    // Display results of search
    cout << "\nThe value 5 was found in vector position " << result1 << endl;
    cout << "\nThe value 3.0 was found in vector position " << result2 << endl << endl;

    return 0;
}
