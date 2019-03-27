/* 
 * Stack.h
 *
 * Description: Implementation of an int sequence with push/pop onto a stack
 * Class Invariant: Stack data collection in a LIFO order
 *
 * Author:  Curtis Lui
 * Date:    January 26 2019
 * 
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
        // Post:  Deletes all the nodes in the stack and frees memory
        ~Stack();


        // Desc:  Insert element x to the top of the stack.
        // Post:  If the operation was successful, newEntry is at the top of the stack.
        void push(int x);


        // Desc:  Remove and return element at the top of the stack.
        //  Pre:  Stack is not empty.
        // Post:  If the operation was successful, the top of the stack has been removed.
        int pop();


        // Desc:  Return the topmost element of the stack.
        //  Pre:  Stack is not empty
        // Post:  The top of the stack has been returned, and the stack is unchanged.
        int peek() const;


        // Desc:  Sees whether this stack is empty.
        // Post:  True if the stack is empty, or false if not
        bool isEmpty() const;
};