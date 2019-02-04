/* 
 * Stack.cpp
 *
 * Description: Implementation of an int sequence with push/pop onto a stack
 * Class Invariant: Stack data collection in a LIFO order
 *
 * Author:  Curtis Lu
 * Date:    January 26 2019
 * 
 */
 
#include <cstddef>  // For NULL
#include <iostream>
#include "Stack.h"

using namespace std;

// Desc:  Default constructor
// Post:  Stack is empty
Stack::Stack()
{
    head = NULL;
    tail = NULL;

} // Stack()

// Desc:  Destructor 
// Post:  Deletes all the nodes in the stack and frees memory
Stack::~Stack()
{
    StackNode* current = head;

    while(current != NULL)
    {
        StackNode* next = current->next;
        delete current;
        current = next;
    }
    
    head = NULL;
    tail = NULL;

} // ~Stack()

// Desc:  Insert element x to the top of the stack.
// Post:  If the operation was successful, newEntry is at the top of the stack.
void Stack::push(int x)
{
    if (isEmpty())
    {
        StackNode* newNode =  new(StackNode);
        if (newNode == NULL)
        {
            cout << "ERROR: Memory for new node not allocated" << endl;
        }
        newNode->data = x;
        newNode->next = NULL;
        head = newNode;
        tail = newNode;
    }
    else
    {
        StackNode* newNode = new(StackNode);
        if (newNode == NULL)
        {
            cout << "ERROR: Memory for new node not allocated" << endl;
        }
        newNode->data = x;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }

} // push(int)

// Desc:  Remove and return element at the top of the stack.
//  Pre:  Stack is not empty.
// Post:  If the operation was successful, the top of the stack has been removed.
int Stack::pop()
{
    if (isEmpty())
    {
        cout << "ERROR: Cannot pop because stack is empty. Returning 0" << endl;
        return 0;
    }
    else
    {
        int nodeCount = 0;
        StackNode* prev = NULL;
        StackNode* cur = NULL;
        cur = head;
        prev = cur;

        // Traverse to one node before the tail
        while (cur->next!= NULL)
        {
            prev = cur;
            cur = cur->next;
            nodeCount++;
        }

        int returnVal = cur->data;
        tail = prev;
        prev->next = NULL;

        // If the stack is empty after deleting this node
        if (nodeCount == 0)
        {
            tail = NULL;
            head = NULL;
        }

        delete cur;
        return returnVal;
    }

} // pop()

// Desc:  Return the topmost element of the stack.
//  Pre:  Stack is not empty
// Post:  The top of the stack has been returned, and the stack is unchanged.
int Stack::peek() const
{
    if (isEmpty())
    {
        cout << "ERROR: Cannot peek because stack is empty. Returning 0" << endl;
        return 0;
    }
    else
    {
        return tail->data;
    }

} // peek()


// Desc:  Sees whether this stack is empty.
// Post:  True if the stack is empty, or false if not
bool Stack::isEmpty() const
{
    if(head == NULL && tail == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
} // isEmpty()







