//  Chapter 18 --  Assignment 5, Dynamic queue Template (Error Testing)
// This program  handles out-of-memory errors by catching the bad_alloc
// exception thrown in the enqueue member function.
#include<iostream>
using namespace std;
 
template <class T>
class Dynque
{
private:
   struct QueueNode
   {
      T value;
      QueueNode *next;
      QueueNode(T val, QueueNode *nextp = NULL)
      {
         value = val; next = nextp;
      }
   };    
   QueueNode *front;
   QueueNode *rear;
   int numItems;
public:
   Dynque();
   ~Dynque();
   void enqueue(T);
   void dequeue(T &);
   bool isEmpty();
   bool isFull(); 
   void clear();
};

//************************
//     Constructor       *
//************************
template <class T>
Dynque<T>::Dynque()
{
    front = NULL;
    rear = NULL;
    numItems = 0;
}

//********************
//    Destructor     *
//********************
template <class T>
Dynque<T>::~Dynque()
{
     clear();
}

//***************************************************
//           Dynque::enqueue                        *
// Function enqueue inserts the value in val        *
// at the rear of the queue.                        *
//***************************************************
template <class T>
void Dynque<T>::enqueue(T val)
{
       // Catch bad_alloc exception if we run out of memory
       try
       {
          if (isEmpty())
             front = rear = new QueueNode(val);
          else
          {
            rear->next =  new QueueNode(val);
            rear = rear->next;
          }
          numItems++;
      }
      catch(bad_alloc)
      {
         cout << "Out of memory.";
         exit(1);
      }
}

//**************************************************
//               Dynque::dequeue                   *
// Function dequeue removes the value at the       *
// front of the queue, and copies it into val.     *
//**************************************************
template <class T>
void Dynque<T>::dequeue(T &val)
{
    QueueNode *temp;

    if (isEmpty())
    { 
        cout << "The queue is empty.\n";
        exit(1);
      }
    else
    {
       val = front->value;
       temp = front;
       front = front->next;
       delete temp;
       numItems--;
      }
}

//*************************************************
//               Dynque::isEmpty                  *
// Function isEmpty returns true if the queue     *
// is empty, and false otherwise.                 *
//*************************************************
template <class T>
bool Dynque<T>::isEmpty()
{
    if (numItems)
        return false;
    else
        return true;
}

//************************************************
//              Dynque::clear                    *
// Function clear dequeues all the elements      *
// in the queue.                                 *       
//************************************************
template <class T>
void Dynque<T>::clear()
{
    T value;    // Dummy variable for dequeue
    while(!isEmpty())
        dequeue(value);
}
int main()
{
    Dynque<double> queue;
    cout << "Enqueuing 5 items...\n";

    // Enqueue 5 items.
    for (int x = 1; x <= 5; x++)
        queue.enqueue(x * 1.1);

    // Deqeue and retrieve all items in the queue
    cout << "The values in the queue were:\n";
    while (!queue.isEmpty())
    {
        double value;
        queue.dequeue(value);
        cout << value << endl;
    }

    return 0;
}
