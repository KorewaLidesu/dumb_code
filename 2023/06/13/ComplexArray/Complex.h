// Li
// 2023 - 06 - 13

// Prevent conflict with other implementations
#ifndef LI_COMPLEX
#define LI_COMPLEX

#include <iostream>

class Complex
{
    public:
        Complex(double = 0.0, double = 0.0);
        void addition(const Complex &);
        void subtraction(const Complex &);
        void printComplex();
        void setComplexNumber(double, double);
    private:
        double realPart;
        double imaginaryPart;
};

Complex::Complex(double realPart, double imaginaryPart)
{
    this->realPart = realPart;
    this->imaginaryPart = imaginaryPart;
}

void Complex::addition(const Complex &complex)
{
    this->realPart += complex.realPart;
    this->imaginaryPart += complex.imaginaryPart;
}

void Complex::subtraction(const Complex &complex)
{
    this->realPart -= complex.realPart;
    this->imaginaryPart -= complex.imaginaryPart;
}

void Complex::printComplex()
{
    std::cout << "Complex number: z = " << realPart
        << " + " << imaginaryPart << "i" << std::endl;
}

void Complex::setComplexNumber(double realPart, double imaginaryPart)
{
    this->realPart = realPart;
    this->imaginaryPart = imaginaryPart;
}

#endif