#include <iostream>

#define EMPLOYEE_H
#ifdef EMPLOYEE_H

class Employee
{
    friend std::istream& operator>>(std::istream&, Employee&);
    friend std::ostream& operator<<(std::ostream&, Employee&);
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

std::ostream &operator<<(std::ostream &out, Employee &employee)
{
    out << "Employee #" << employee.idNum << ", salary: " << employee.salary;
    return out;
}

std::istream& operator>>(std::istream &in, Employee &employee)
{
    std::cout << "Employee id num: "; in >> employee.idNum;
    std::cout << "Employee salary: "; in >> employee.salary;
    return in;
}

#endif