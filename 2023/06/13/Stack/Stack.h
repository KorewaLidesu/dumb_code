// Li
// 2023 - 06 - 02

// Prevent conflict with other implementations
#ifndef LI_STACK
#define LI_STACk

#include <stdexcept>

class Stack {
    private:
        int* array;
        int size = 0;
        int capacity;
    public:
        void push(int value);
        int pop();
        bool isFull();
        bool isEmpty();
};

void Stack::push(int value) {
    if (isFull())
        throw std::overflow_error("Failed to push value to stack due to reached full size.");
    
    array[size++] = value;
}

int Stack::pop() {
    if (isEmpty())
        throw std::out_of_range("Failed to pop value out due to stack is empty");
    int result = array[size - 1];
    array[size--] = NULL;
    return result;
}

bool Stack::isFull() {
    return size == capacity;
}

bool Stack::isEmpty() {
    return size == 0;
}

#endif