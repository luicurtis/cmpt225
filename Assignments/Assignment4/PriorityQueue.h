/*
 * PriorityQueue.h
 *
 * Description: Priority Queue
 * Class Invariant: The elements stored in this Priority Queue are always sorted.
 *
 * Author: Inspired by Frank M. Carrano and Tim Henry (textbook).
 * Modified: March 2019, Curtis Lui
 *
 */

#pragma once

#include <iostream>
#include "Node.h"
#include "EmptyDataCollectionException.h"

using namespace std;

template <class T>
class PriorityQueue
{
  private:
    Node<T> *head;    // Pointer to first node in the chain
    int elementCount; // Current count of list items

  public:
    // Default Constructor
    PriorityQueue();

    // Copy Constructor
    PriorityQueue(const PriorityQueue &rhsPriorityQueue);

    // Destructor
    ~PriorityQueue();

    // Description: Returns the number of elements in the Priority Queue.
    // Time Efficiency: O(1)
    int getElementCount() const;

    // Description: Returns "true" is this Priority Queue is empty, otherwise "false".
    // Time Efficiency: O(1)
    bool isEmpty() const;

    // Description: Inserts newElement in sort order.
    //              It returns "true" if successful, otherwise "false".
    // Precondition: This Priority Queue is sorted.
    // Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
    // Time Efficiency: O(n)
    bool enqueue(const T &newElement);

    // Description: Removes the element with the "highest" priority.
    //              It returns "true" if successful, otherwise "false".
    // Precondition: This Priority Queue is not empty.
    // Time Efficiency: O(1)
    bool dequeue();

    // Description: Returns the element with the "highest" priority.
    // Precondition: This Priority Queue is not empty.
    // Postcondition: This Priority Queue is unchanged.
    // Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
    // Time Efficiency: O(1)
    T &peek() const throw(EmptyDataCollectionException);

    // To deal with the warning regarding template and friend function:
    // I used the first "Introvert" solution described in
    // https://stackoverflow.com/questions/4660123/overloading-friend-operator-for-template-class
    // The idea: only declare a particular instantiation of the << operator as a friend
    // by inlining the operator.
    friend ostream &operator<<(ostream &os, const PriorityQueue<T> &rhs)
    {
        Node<T> *current = rhs.head;

        os << "elementCount = " << rhs.elementCount;

        // Traverse the list
        while (current != NULL)
        {
            cout << current->data;   // Print data
            current = current->next; // Go to next Node
        }

        return os;
    } // end of operator <<

}; // end PriorityQueue

// Implementation
// Default Constructor
template <class T>
PriorityQueue<T>::PriorityQueue() : head(NULL), elementCount(0)
{

} // End of PriorityQueue()

// Copy Constructor
template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue &rhsPriorityQueue)
{
    Node<T> *curRHS = rhsPriorityQueue.head;
    Node<T> *curThis = NULL;
    Node<T> newNode = new Node<T>;
    head = newNode;
    head->data = curRHS->data;
    curThis = head;

    while (curRHS != NULL)
    {
        Node<T> newNode = new Node<T>; // Create new node to add to pQueue
        curThis->next = newNode;       // Link prev Node to newNode
        curThis = newNode;             // Point to the newNode
        curThis->data = curRHS->data;  // Set Node data equal to RHS
        elementCount++;

        curRHS = curRHS->next; // Move to next Node in RHS
    }
} // End of PriorityQueue(PriorityQueue&)

// Destructor
template <class T>
PriorityQueue<T>::~PriorityQueue()
{
    Node<T> *cur = head;
    Node<T> *temp = NULL;

    while (cur != NULL)
    {
        temp = cur;
        cur = cur->next;
        delete temp;
        elementCount--;
    }

    head = NULL;

} // End of ~PriorityQueue()

// Description: Returns the number of elements in the Priority Queue.
// Time Efficiency: O(1)
template <class T>
int PriorityQueue<T>::getElementCount() const
{
    return elementCount;

} // End of getElementCount()

// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
// Time Efficiency: O(1)
template <class T>
bool PriorityQueue<T>::isEmpty() const
{
    if (elementCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

} // End of isEmpty()

// Description: Inserts newElement in sort order.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is sorted.
// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
// Time Efficiency: O(n)
template <class T>
bool PriorityQueue<T>::enqueue(const T &newElement)
{
    Node<T> *newNode = new Node<T>;
    if (newNode == NULL)
    {
        return false;
    }
    
    newNode->data = newElement;
    
    // If queue is empty
    if (head == NULL || newElement < head->data)
    {
        newNode->next = head;
        head = newNode;
        elementCount++;

        return true;
    }
    // Queue contains nodes
    else
    {
        Node<T> *cur = head;
        Node<T> *prev = NULL;

        // Find place to insert node
        while (cur->next != NULL && cur->next->data <= newElement)
        {
            cur = cur->next;
        }

        newNode->next = cur->next;
        cur->next = newNode;

        elementCount++;

        return true;
    }

} // End of enqueue(const T&)

// Description: Removes the element with the "highest" priority.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is not empty.
// Time Efficiency: O(1)
template <class T>
bool PriorityQueue<T>::dequeue()
{
    Node<T> *temp = head;
    head = head->next;
    delete temp;
    elementCount--;

    return true;

} // End of dequeue()

// Description: Returns the element with the "highest" priority.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template <class T>
T &PriorityQueue<T>::peek() const throw(EmptyDataCollectionException)
{
    return head->data; // Does not need & for return argument

} // End of peek()

//  End of implementation file.