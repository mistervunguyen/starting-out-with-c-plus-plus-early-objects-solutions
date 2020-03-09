//  Chapter 18 -  Assignment 3, Static Queue Template
 
#include<iostream>
using namespace std;

template <class T>
class Queue
{
private:
    T *queueArray;
    int queueSize;
    int front;
    int rear;
    int numItems;
public:
    Queue(int capacity);     
    ~Queue();
    void enqueue(T);
    void dequeue(T &);
    bool isEmpty();
    bool isFull();
    void clear();
};

//*******************
//   Constructor    *
//*******************
template <class T>
Queue<T>::Queue(int capacity)
{
    queueArray = new T[capacity];
    queueSize = capacity;
    front = -1;
    rear = -1;
    numItems = 0;
}

//*******************
//   Destructor     *
//*******************
template <class T>
Queue<T>::~Queue()
{
    delete [] queueArray;
}

//***********************************************
//         Queue::enqueue                       *
// Function enqueue adds the given value at     *
// the rear of the queue.                       *
//***********************************************
template <class T>
void Queue<T>::enqueue(T val)
{
    if (isFull())
    {  cout << "The queue is full.\n";
         exit(1);
      }
    else
    {
      // Calculate the new rear position
      rear = (rear + 1) % queueSize;
      // Insert new item
      queueArray[rear] = val;
      // Update item count
      numItems++;
     }
}

//************************************************
//            Queue::dequeue                     *
// Function dequeue removes the value at the     * 
// Front of the queue, and copies t into val.    *
//************************************************
template <class T>
void Queue<T>::dequeue(T &val)
{
  if (isEmpty())
  {
      cout << "The queue is empty.\n";
      exit(2);
  }
  else
  {
    // Move front
    front = (front + 1) % queueSize;
    // Retrieve the front item
    val = queueArray[front];
    // Update item count
    numItems--;
  }
}

//****************************************************
//           Queue::isEmpty                          *
// Function isEmpty returns true if the queue        *
// Is empty, and false otherwise.                    *
//****************************************************
template <class T>
bool Queue<T>::isEmpty()
{
    if (numItems == 0)
        return true;
    else
        return false;
}

//************************************************
//          Queue::isFull                        *
// Function isFull returns true if the queue     *
// is full, and false otherwise.                 *
//************************************************
template <class T>
bool Queue<T>::isFull()
{
    if (numItems < queueSize)
        return false;
    else
        return true;
}

//**********************************************
//         Queue::clear                        *
// Function clear resets the front and rear    *
// Indices, and sets numItems to 0.            *
//**********************************************
template <class T>
void Queue<T>::clear()
{
    front =  - 1;
    rear = - 1;
    numItems = 0;
}

int main()
{
    Queue<double> Queue(5);

    // Enqueue 5 items.
    cout << "Enqueuing 5 items...\n";  
    for (int x = 1; x <= 5; x++)
        Queue.enqueue(x * 1.1f);  

    // Deqeue and retrieve all items in the queue
    cout << "The values in the queue were:\n";
    while (!Queue.isEmpty())
    {
        double value;
        Queue.dequeue(value);
        cout << value << endl;
    }

    return 0;
}
