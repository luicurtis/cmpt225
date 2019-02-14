
#pragma once

#include "Complex.h"

#include <cstddef>

using namespace std;

// Desc:  A List of complex numbers.
class LL {
    class node {
        public:
            Complex data;
            node * next;

            node() : next(NULL) {};
            node(Complex data) : data(data), next(NULL) {};
            node(Complex data, node * next) : data(data), next(next) {};
    };

    private:
        node * head;
        node * tail;
        unsigned len;
    public:
        // Desc:  Constructor
        LL();
        bool isEmpty() const;
        const unsigned &getLength() const;


        // Desc:  Place x at tail end of list
        // Post:  Other elements unchanged
        void append(Complex x);


        // Desc:  Place x at head end of list
        // Post:  Other elements unchanged
        void prepend(Complex x);


        
        // Desc:  Access element i
        //  Pre:  i must be strictly less than the length of the list
        Complex get(unsigned i) const;



        // Desc:  Removes element before the tail element
        //  Pre:  List has at least two elements
        // Post:  Other elements unchanged
        Complex removeSecondLast();

};

