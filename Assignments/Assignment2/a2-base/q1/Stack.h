/* 
 * Stack.h
 *
 * Description: Implementation of an int sequence with push/pop ...
 * Class Invariant: ... in a LIFO order
 *
 * Author:  Curtis Lui
 * Date:    January 26 2019
 */
 
class Stack 
{
    private:
        // Desc:  Nodes for a singly-linked list
        class StackNode
        {
            public:
                int data;
                StackNode * next;
        };
        
        // Desc:  head = ptr to the first StackNode (NULL if empty)
        //        tail = ptr to the last StackNode (NULL if empty)
        //  Inv:  Follows the A2 Spec, namely that the implementation 
        //        is a singly-linked list, with insert/remove 
        //        operations at the list's tail.
        StackNode * head;
        StackNode * tail;

    public:
        // Desc:  Default constructor
        // Post:  Stack is empty
        Stack();


        // Desc:  Destructor 
        // Post:  Deletes Stack information
        ~Stack();


        // Desc:  Insert element x to the top of the stack.
        // Post:  Element x is places at the top of the stack
        void push(int x);


        // Desc:  Remove and return element at the top of the stack.
        //  Pre:  Stack is not empty.
        // Post:  Top element is removed from the top of the stack.
        int pop();


        // Desc:  Return the topmost element of the stack.
        //  Pre:  Stack is not empty
        // Post:  Topmost element is returned
        int peek() const;


        // Desc:  Return true if stack is empty, else false.
        // Post:  Stack status returned
        bool isEmpty() const;
};