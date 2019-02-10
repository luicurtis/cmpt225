
#include "Stack.h"


// Desc:  Constructor
Stack::Stack() {
    len = 0;
} // constructor



bool Stack::isEmpty() const {
    return len == 0;
} // isEmpty



// Desc:  Insert element x to the top of the stack.
void Stack::push(int x) {
    arr[len++] = x;
} // push



// Desc:  Remove and return element at the top of the stack.
int Stack::pop() {
    return arr[--len];
} // pop



// Desc:  Removes and returns the max element.
//        In case of duplicated max, take the one closest to the top.
//  Pre:  Stack nonempty
// Post:  Order of remaining elements is preserved
int Stack::removeMax() {
} // removeMax


