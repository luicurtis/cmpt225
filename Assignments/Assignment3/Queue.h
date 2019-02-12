/* 
 * Queue.h
 *
 * Description: Implementation of an int sequence with enqueue/dequeue 
 * Class Invariant: Queue data collection in a FIFO order
 *
 * Author:  Curtis Lui
 * Date:    February 12 2019
 * 
 */

#include "EmptyDataCollectionException.h"

const double QUARTER_FULL = 0.25;

template <class ElementType>
class Queue
{
  private:
    static unsigned const INITIAL_SIZE = 6;
    int *elements;
    unsigned elementCount; // number of elements in the queue
    unsigned capacity;     // number of cells in the array
    unsigned frontindex;   // index the topmost element
    unsigned backindex;    // index where the next element will be placed

  public:
    // Desc:    Default constructor
    // Post:    Initializes elementCount, frontindex, and backindex to 0.
    //          capacity to INITIAL_SIZE
    Queue();

    // Desc: Default Destructor
    // Post: Frees memory and points pointers to NULL
    ~Queue();

    // Description: Returns "true" is this Queue is empty, otherwise "false".
    // Time Efficiency: O(1)
    bool isEmpty() const;

    // Description: Inserts newElement at the "back" of this Queue
    //              (not necessarily the "back" of its data structure) and
    //              returns "true" if successful, otherwise "false".
    // Time Efficiency: O(1)
    bool enqueue(const ElementType &newElement);

    // Description: Removes the element at the "front" of this Queue
    //              (not necessarily the "front" of its data structure) and
    //              returns "true" if successful, otherwise "false".
    // Precondition: This Queue is not empty.
    // Time Efficiency: O(1)
    bool dequeue();

    // Description: Returns the element located at the "front" of this Queue.
    // Precondition: This Queue is not empty.
    // Postcondition: This Queue is unchanged.
    // Exceptions: Throws EmptyDataCollectionException if this Queue is empty.
    // Time Efficiency: O(1)
    ElementType &peek() const throw(EmptyDataCollectionException);
};

// Implementation

// Desc:    Default constructor
// Post:    Initializes elementCount, frontindex, and backindex to 0.
//          capacity to INITIAL_SIZE
template <class ElementType>
Queue<ElementType>::Queue() : elementCount(0), capacity(INITIAL_SIZE), frontindex(0), backindex(0)
{
    elements = NULL;
    elements = new int[INITIAL_SIZE];

} // constructor

// Desc: Default Destructor
// Post: Frees memory and points pointers to NULL
template <class ElementType>
Queue<ElementType>::~Queue()
{
    delete[] elements;
    elements = NULL;

} // Destructor

// Description: Returns "true" is this Queue is empty, otherwise "false".
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::isEmpty() const
{
    return (elementCount == 0);

} // isempty

// Desc:    Inserts element x at the back (O(1))
// Post:    Element x is inserted in the back and backindex is updated
template <class ElementType>
bool Queue<ElementType>::enqueue(const ElementType &newElement)
{
    // Check if array is full
    if (elementCount == capacity)
    {
        // Create a new array that is twice the orignal size
        int *newArray = new int[capacity * 2];

        if (newArray == NULL)
        {
            return false;
        }

        int j = 0;

        for (int i = frontindex; i < capacity; i++)
        {
            newArray[j] = elements[i];
            j++;
        }
        // Copy elements of old array into newArray
        if (frontindex != 0)
        {
            for (int i = 0; i < frontindex; i++)
            {
                newArray[j] = elements[i];
                j++;
            }
        }

        //Insert the new element
        newArray[elementCount] = newElement;

        // Update private memebers
        elementCount++;
        capacity = capacity * 2;
        frontindex = 0;
        backindex = elementCount;

        // Delete old array
        delete[] elements;
        elements = newArray;
        newArray = NULL;
    }
    else
    {
        elementCount++;
        elements[backindex] = newElement;
        backindex = (backindex + 1) % capacity;
    }

    return true;

} // enqueue

// Desc:    Removes the frontmost element (O(1))
//  Pre:    Queue not empty
// Post:    Frontmost element is removed and frontindex is updated
template <class ElementType>
bool Queue<ElementType>::dequeue()
{
    // dequeue element first
    elementCount--;
    frontindex = (frontindex + 1) % capacity;

    //Check to see if the array is 1/4 full and if halving the capacity is greater
    //than the initial size
    double fullness = 1.0 * elementCount / capacity;

    if (fullness < QUARTER_FULL && ((capacity / 2) >= INITIAL_SIZE))
    {
        // Create new array that is half the original size
        int halfCap = capacity / 2;
        int *newArray = new int[halfCap];

        if (newArray == NULL)
        {
            return false;
        }

        // Copy elements of old array into newArray
        int j = 0;

        for (int i = frontindex; i < capacity; i++)
        {
            newArray[j] = elements[i];
            j++;
            if (j == elementCount)
            {
                break;
            }
        }
        // Copy elements of old array into newArray
        if (frontindex != 0 && j < elementCount)
        {
            for (int i = 0; i < frontindex; i++)
            {
                newArray[j] = elements[i];
                j++;
            }
        }

        // Update private memebers
        capacity = capacity / 2;
        frontindex = 0;
        backindex = elementCount;

        // Delete old array
        delete[] elements;
        elements = newArray;
        newArray = NULL;
    }

    return true;

} // dequeue

// Desc:  Returns a copy of the frontmost element (O(1))
//  Pre:  Queue not empty
template <class ElementType>
ElementType &Queue<ElementType>::peek() const throw(EmptyDataCollectionException)   // ASK ABOUT THIS
{
    return &elements[frontindex];

} // top
