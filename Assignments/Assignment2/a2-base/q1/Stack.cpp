/* 
 * Stack.cpp
 *
 * Description: Implementation of an int sequence with push/pop ...
 * Class Invariant: ... in a LIFO order
 *
 * Author:
 * Date:
 */
 
#include <cstddef>  // For NULL
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
// Post:  Deletes Stack information
Stack::~Stack()
{
    // TODO

} // ~Stack()

// Desc:  Insert element x to the top of the stack.
// Post:  Element x is places at the top of the stack
void Stack::push(int x)
{
    StackNode newNode;
    newNode.data = x;
    newNode.next = tail;
    tail = &newNode;

} // push(int)

// Desc:  Remove and return element at the top of the stack.
//  Pre:  Stack is not empty.
// Post:  Top element is removed from the top of the stack.
int Stack::pop()
{

} // pop()


// Desc:  Return the topmost element of the stack.
//  Pre:  Stack is not empty
// Post:  Topmost element is returned
int Stack::peek() const
{

} // peek()


// Desc:  Return true if stack is empty, else false.
// Post:  Stack status returned
bool Stack::isEmpty() const
{

} // isEmpty()







