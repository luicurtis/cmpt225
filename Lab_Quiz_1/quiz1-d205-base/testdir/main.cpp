
#include <iostream>
#include "LL.h"
#include "Complex.h"


using namespace std;

int main () {
    int N = 2;
    
    while (N--) {
        LL L;
        int i;
    
        float a[3] = { 1.0, -0.8660254, 0};
        float b[3] = { 0, 0.5, -1.0};
    
        for (i = 0; i < 3; i++) {
            L.append(Complex(a[(i+N)%3], b[(i+N)%3]));
        }
    
        Complex c(a[(1+N)%3], b[(1+N)%3]);
    
        if (c != L.removeSecondLast()) {
            cout << "Fail" << endl;
            return 0;
        }
    }
    cout << "Pass" << endl;

    return 0;
} // main

