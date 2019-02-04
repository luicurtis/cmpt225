/* 
 * Queue.cpp
 *
 * Description: Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order
 *
 * Author:  Curtis Lui
 * Date:    February 3 2019
 */
 
#include <iostream>
#include "Queue.h"

using namespace std;

const double QUARTER_FULL = 0.25;

// Desc:  Constructor
Queue::Queue() : elementCount(0), capacity(INITIAL_SIZE), frontindex(0), backindex(0) 
{
    elements = NULL;
    elements = new int[INITIAL_SIZE];

} // constructor

// Desc: Destructor
Queue::~Queue()
{
    delete [] elements;
    elements = NULL;

} // Destructor

// Desc:  Inserts element x at the back (O(1))
void Queue::enqueue(int x)
{
    // Check if array is full
    if (elementCount == capacity)
    {
        // Create a new array that is twice the orignal size
        int * newArray = new int[capacity * 2];
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
        newArray[elementCount] = x;

        // Update private memebers
        elementCount++;
        capacity = capacity * 2;
        frontindex = 0;
        backindex = elementCount;

        // Delete old array
        delete [] elements;
        elements = newArray;
        newArray = NULL;

    }
    else
    {
        elementCount++;
        elements[backindex] = x;
        backindex = (backindex + 1) % capacity;
    }

} // enqueue

// Desc:  Removes the frontmost element (O(1))
//  Pre:  Queue not empty
void Queue::dequeue() 
{
    // dequeue element first
    elementCount--;
    frontindex = (frontindex + 1) % capacity;

    //Check to see if the array is 1/4 full and if halving the capacity is greater
    //than the initial size
    double fullness = 1.0 * elementCount / capacity;

    cout << "ELEMENT COUNT " << elementCount << endl;
    cout << "CAPACITY " << capacity << endl;
    cout << "FULLNESS: " << fullness << endl;
    if (fullness < QUARTER_FULL && ((capacity / 2) >= INITIAL_SIZE))
    {
        // Create new array that is half the original size
        int * newArray = new int[capacity / 2];
        
        // Copy elements of old array into newArray
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

        // Update private memebers
        capacity = capacity / 2;
        frontindex = 0;
        backindex = elementCount;

        // Delete old array
        delete [] elements;
        elements = newArray;
        newArray = NULL;
    }

} // dequeue

// Desc:  Returns a copy of the frontmost element (O(1))
//  Pre:  Queue not empty
int Queue::peek() const 
{
   
    // for (int i = 0; i < elementCount; i ++)
    //     {
    //         cout << elements[i] << endl;
    //     }
    //     cout << endl;

    return elements[frontindex];
} // top

// Desc:  Returns true if and only if queue empty (O(1))
bool Queue::isEmpty() const 
{
    return elementCount == 0;
} // isempty




