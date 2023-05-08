

#include <iostream>
#include "P6_06.H"

int main() {
    Complex test (3, -30), test2 (3, 30);
    test.printComplex();
    test2.printComplex();

    test = test + test2;
    test.printComplex();

    test2 = test2 - test;
    test2.printComplex();
}