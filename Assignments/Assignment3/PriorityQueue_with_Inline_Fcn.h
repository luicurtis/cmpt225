/*
 * PriorityQueue.h
 *
 * Description: Priority Queue
 * Class Invariant: The elements stored in this Priority Queue are always sorted.
 *
 * Author: Inspired by Frank M. Carrano and Tim Henry (textbook).
 * Modified: February 2019
 *
 */

/* None of the current content of this file can be modified. */

#pragma once

#include <iostream> // <- You will need this!
#include "Node.h"
#include "EmptyDataCollectionException.h"

using namespace std;

template <class T> // We can use T, ElementType or other names as a placeholder
class PriorityQueue
{

 private:
   Node<T> *head;    // Pointer to first node in the chain
   int elementCount; // Current count of list items

   /* You can add private methods to this class */

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
   T peek() const throw(EmptyDataCollectionException);

   // For Testing Purposes
   // Description: Prints the content of "this".
   void printPriorityQueue() const;

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