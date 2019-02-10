
#include "Stack.h"
#include <iostream>

using namespace std;


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
int Stack::removeMax() 
{
    int max = arr[len-1];
    int maxIndex = len-1;
    
    // Search for the max element and it's index
    for (int i = len-1; i > 0; i--)
    {
        if (max < arr[i])
        {
            max = arr[i];
            maxIndex = i;
        }
        else if (max == arr[i])
        {
            continue;
        }
    }

    int tempArray[S_CAP];

    // Create a temp array with max element removed
    if (len > 0)
    {
        // Copy elements before the max element
        for (int i = 0; i < maxIndex; i++)
        {
            tempArray[i] = arr[i];
        }
        // Copy elements after the max element
        for (int i = maxIndex; i < len-1; i++)
        {
            tempArray[i] = arr[i + 1];
        }
    }

    len--;
    // Copy over temp array elements into arr
    for (int i = 0; i < len; i++)
    {
        arr[i] = tempArray[i];
    }

    return max;

} // removeMax


