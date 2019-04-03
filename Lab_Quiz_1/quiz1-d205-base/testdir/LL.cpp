
#include "LL.h"
#include <iostream>

using namespace std;


// Desc:  Constructor
LL::LL() : head(NULL), tail(NULL), len(0) {
} // constructor


bool LL::isEmpty() const {
    return head == NULL;
} // isEmpty


const unsigned &LL::getLength() const {
    return len;
} // getLength


// Desc:  Place x at head end of list
// Post:  Other elements unchanged
void LL::prepend(Complex x) {
    node * newnode = new node(x, head);

    if (head == NULL) {
        // empty list
        tail = newnode;
    }

    head = newnode;

    len++;
} // prepend


// Desc:  Place x at tail end of list
// Post:  Other elements unchanged
void LL::append(Complex x) {
    node * newnode = new node(x, NULL);

    if (tail) {
        tail->next = newnode;
        tail = newnode;
    } else {
        // empty list
        head = newnode;
        tail = newnode;
    }

    len++;
} // append


// Desc:  Access element i
//  Pre:  i must be strictly less than the length of the list
Complex LL::get(unsigned i) const {
    node * curr;

    curr = head;

    while (curr && i) {
        curr = curr->next;
        i--;
    }

    if (curr) {
        return curr->data;
    }
} // get




// Desc:  Removes element before the tail element
//  Pre:  List has at least two elements
// Post:  Other elements unchanged
Complex LL::removeSecondLast() {

    node* cur = NULL;
    node* prev = NULL;
    node* toRemove = NULL;
    Complex value;
    
    cur = head;
    
    int i = 1;

    // Find the node we want to delete
    while (i != (len - 1))
    {
        prev = cur;
        cur = cur->next;
        i++;
    }

    // Cur should be pointing at the node we want to delete
    toRemove = cur;
    cur = cur->next;
    value = toRemove->data;
    delete toRemove;
    toRemove = NULL;
    len--;
    

    prev->next = cur;

    return value;

} // removeSecondLast

