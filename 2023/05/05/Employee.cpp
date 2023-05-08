#include <iostream>
#include <vector>
#include "Employee.h"

int main()
{
    std::vector<Employee> myVector;
    unsigned count;
    Employee enteredVal;
    const char QUIT = 'n';
    char quitChar;
    int position;
    std::cout << "Do you want to enter a value? y or n ";
    std::cin >> quitChar;
    while (quitChar != QUIT)
    {
        std::cout << "Enter employee info" << std::endl;
        std::cin >> enteredVal;
        myVector.push_back(enteredVal);
        std::cout << "Do you want to enter a value? y or n ";
        std::cin >> quitChar;
    }
    std::cout << "Size of the list is " << myVector.size() << std::endl;
    std::cout << "The list: " << std::endl;
    for (count = 0; count < myVector.size() ; ++count)
        std::cout << "  " << myVector[count] << std::endl;
    std::cout << "Enter a position to display ";
    std::cin >> position;
    std::cout << "The item at position " << position << " is: ";
    std::cout << myVector.at(position) << std::endl;
}