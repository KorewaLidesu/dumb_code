#include <string>
#include <iostream>
class Salesperson {
    private:
        int id;
        std::string name;
    public:
        Salesperson(int, std::string);
        void setId(int);
        void setName(std::string);
        void displayPerson();
};

Salesperson::Salesperson(int id = 0, std::string name = 0) {
    Salesperson::id = id;
    Salesperson::name = name;
}

void Salesperson::setId(int id) {
    Salesperson::id = id;
}

void Salesperson::setName(std::string name) {
    Salesperson::name = name;
}

void Salesperson::displayPerson() {
    std::cout << "Salesperson #" << id << " " << name << std::endl;
}