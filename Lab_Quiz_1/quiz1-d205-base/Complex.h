
#pragma once 

#include <cassert>
#include <iostream>

using namespace std;

// Desc:  Represents a complex number
class Complex {
    private:
        float re;
        float im;
    public:
        // Desc:  Constructors
        Complex() : re(0), im(0) {};
        Complex(float re, float im) : re(re), im(im) {};

        // Desc:  Accessors
        const float &Im() const { 
            return im; 
        };
        const float &Re() const { 
            return re; 
        };
        float &Im() { 
            return im; 
        };
        float &Re() { 
            return re; 
        };

        // Desc:  Comparators
        bool operator==(const Complex &rhs) {
            return (re == rhs.re && im == rhs.im);
        };

        bool operator!=(const Complex &rhs) {
            return (re != rhs.re || im != rhs.im);
        };
};

