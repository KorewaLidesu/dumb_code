#include <iostream>

class Employee
{
    private:
        int idNum;
        double salary;
    public:
        Employee(int = 0, double = 0.00);
        double operator+(Employee);
        Employee operator+(double);
        double operator-(Employee);
};

Employee::Employee(int id, double sal)
{
    idNum = id;
    salary = sal;
}

double Employee::operator+(Employee emp)
{
    double total;
    total = salary + emp.salary;
    return total;
}

Employee Employee::operator+(double raise)
{
    Employee temp;
    temp.idNum = idNum;
    temp.salary = salary + raise;
    return temp;
}

double Employee::operator-(Employee emp)
{
    double difference;
    difference = salary - emp.salary;
    return difference;
}

int main()
{
    Employee clerk(1234, 400.00);
    Employee driver(3456, 650.00);
    double sum;
    sum = clerk.operator+(driver);
    std::cout << "Using operator+() function - Sum is $" <<
    sum << std::endl;
    sum = clerk + driver;
    std::cout << "Adding clerk to driver - Sum is $" <<
    sum << std::endl;
    return 0;
}