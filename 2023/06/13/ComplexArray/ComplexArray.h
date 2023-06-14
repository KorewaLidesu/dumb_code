// Li
// 2023 - 06 - 13

// Prevent conflict with other implementations
#ifndef LI_COMPLEXARRAY
#define LI_COMPLEXARRAY

#include "Complex.h"

class ComplexArray {
    private:
        Complex* array;
        int capacity = 100;
        int size = 0;
    public:
        void add(const Complex&);
        void add(const Complex&, int);
        const Complex* remove(int);
        void removeAll();

};

void ComplexArray::add(const Complex& element) {
    if (size == capacity) {
        std::cout << "Array is full, please free slot before add element!";
    }
    array[size] = element;
    size++;
}

void ComplexArray::add(const Complex& element, int index) {
    if (index >= 0 && index <= size) {
        //Reallocate if necessary.
        if (index >= capacity || size == capacity) {
            std::cout << "Array is full, please free slot before add element!";
        }

        //Shift elements to the right.
        for (int i = size; i > index; i--) {
            array[i] = array[i - 1];
        }

        array[index] = element;
        size++;
    }
}

const Complex* ComplexArray::remove(int index) {
    Complex* removed = NULL;

    if (index < size && index >= 0) {
        for (int i = index; i < size; i++) {
            array[i] = array[i + 1];
        }
        removed = array + index;
        size--;
    }

    return removed;
}

void ComplexArray::removeAll() {
    delete[] array;
    array = new Complex[capacity];
    size = 0;
}

#endif