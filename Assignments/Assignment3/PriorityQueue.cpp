/*
 * PriorityQueue.cpp
 *
 * Description: Priority Queue
 * Class Invariant: The elements stored in this Priority Queue are always sorted.
 *
 * Author: Inspired by Frank M. Carrano and Tim Henry (textbook).
 * Modified: February 2019
 *
 */

#include "PriorityQueue.h"  // Header file

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
        Node<T> newNode = new Node<T>;  // Create new node to add to pQueue
        curThis->next = newNode;        // Link prev Node to newNode
        curThis = newNode;              // Point to the newNode
        curThis->data = curRHS->data;   // Set Node data equal to RHS

        curRHS = curRHS->next;          // Move to next Node in RHS
    }
}



//  End of implementation file.