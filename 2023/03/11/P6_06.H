// 2023_03_17
// By Li

#include <iostream>

// P6_06.H
#ifndef P6_06_H
#define P6_06_H

class Complex
{
    friend std::ostream& operator<<(std::ostream&, const Complex&);
    friend std::istream& operator>>(std::istream&, Complex&);
    public:
        Complex(double = 0.0, double = 0.0);
        Complex operator+(Complex);
        Complex operator-(Complex);
        bool operator==(Complex);
        bool operator!=(Complex);
        void printComplex(void);
        void setComplexNumber(double, double);
    private:
        double realPart;
        double imaginaryPart;
};

Complex::Complex(double real, double img)
{
    realPart = real;
    imaginaryPart = img;
}

Complex Complex::operator+(Complex add)
{
    Complex temp(this->realPart + add.realPart, this->imaginaryPart + add.imaginaryPart);
    return temp;
}

Complex Complex::operator-(Complex sub)
{
    Complex temp(this->realPart - sub.realPart, this->imaginaryPart - sub.imaginaryPart);
    return temp;
}

bool Complex::operator==(Complex compare)
{
    return this->realPart == compare.realPart && this->imaginaryPart == compare.imaginaryPart;
}

bool Complex::operator!=(Complex compare)
{
    return this->realPart != compare.realPart || this->imaginaryPart != compare.imaginaryPart;
}

std::ostream& operator<<(std::ostream& out, const Complex& complex)
{
    out << std::noshowpos << complex.realPart;
    out << std::showpos << complex.imaginaryPart << "i" << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Complex& complex)
{
    std::cout << "Input real part: ";
    in >> complex.realPart;
    std::cout << "Input imaginary part: ";
    in >> complex.imaginaryPart;
    return in;
}

void Complex::printComplex(void)
{
    std::cout << std::noshowpos << this->realPart;
    std::cout << std::showpos << this->imaginaryPart << "i" << std::endl;
}

void Complex::setComplexNumber(double real, double img)
{
    this->realPart = real;
    this->imaginaryPart = img;
}

#endif

// 2023_03_17
// By Li