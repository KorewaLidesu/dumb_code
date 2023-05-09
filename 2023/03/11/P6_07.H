// 2023_03_17
// By Li

#include <iostream>
#include <math.h>
#include <algorithm>

// P6_06.H
#ifndef P6_07_H
#define P6_07_H

class Rational
{
    friend std::ostream& operator<<(std::ostream&, const Rational);
    friend std::istream& operator>>(std::istream&, Rational&);
    public:
        Rational(int = 0, int = 1);
        Rational operator+(Rational);
        Rational operator-(Rational);
        Rational operator*(Rational);
        Rational operator/(Rational);
        bool operator==(Rational);
        bool operator!=(Rational);
        void printRational();
        void printRationalAsDouble();
    private:
        double numerator;
        double denominator;
        void reduction();
};

Rational::Rational(int numerator, int denominator)
{
    this->numerator = numerator;
    // Simple demominator check ( Don't try 0 on me :/ )
    if (denominator == 0) {
        std::cout << "Rational Checker: Detect demominator input incorrect."
            << std::endl << "Using default (1)" << std::endl;
        denominator = 1;
    }
    this->denominator = denominator;
    this->reduction();
}

void Rational::reduction()
{
    if (abs(numerator) == abs(denominator))
    {
        if (numerator == -denominator)
            numerator = -1;
        else
            numerator = 1;
        denominator = 1; // Always after so that the reduction apply correctly
        return;
    }
    else if (numerator == 0)
    {
        denominator = 1;
        return;
    }

    if (denominator < 0) // make sure denominator always > 0
    {
        numerator = -numerator;
        denominator = -denominator;
    }

    // Retrieve GCD
    int gcd = std::__gcd((int) abs(numerator), (int) abs(denominator));

    // Reduction using GCD
    numerator /= gcd;
    denominator /= gcd;
}

Rational Rational::operator+(Rational obj)
{
    Rational temp;
    temp.numerator = this->numerator * obj.denominator + obj.numerator * this->denominator;
    temp.denominator = this->denominator * obj.denominator;
    temp.reduction();
    return temp;
}

Rational Rational::operator-(Rational obj)
{
    Rational temp;
    temp.numerator = this->numerator * obj.denominator - obj.numerator * this->denominator;
    temp.denominator = this->denominator * obj.denominator;
    temp.reduction();
    return temp;
}

Rational Rational::operator*(Rational obj)
{
    Rational temp;
    temp.numerator = this->numerator * obj.numerator;
    temp.denominator = this->denominator * obj.denominator;
    temp.reduction();
    return temp;
}

Rational Rational::operator/(Rational obj)
{
    Rational temp;
    temp.numerator = this->numerator * obj.denominator;
    temp.denominator = this->denominator * obj.numerator;
    temp.reduction();
    return temp;
}

bool Rational::operator==(Rational compare)
{
    this->reduction();  // Always make sure we get reduction first before the comparation
    compare.reduction();
    return this->numerator == compare.numerator && this->denominator == compare.denominator;
}

bool Rational::operator!=(Rational compare)
{
    this->reduction();  // Always make sure we get reduction first before the comparation
    compare.reduction();
    return this->numerator != compare.numerator || this->denominator != compare.denominator;
}

std::ostream& operator<<(std::ostream& out, const Rational rational)
{
    std::cout << "Display as Rational: " << rational.numerator << "/" << rational.denominator << std::endl;
    std::cout << "Display as Double: " << (double) (rational.numerator / rational.denominator) << std::endl;
}

std::istream& operator>>(std::istream& in, Rational& rational)
{
    std::cout << "Input numerator: ";
    in >> rational.numerator;
    std::cout << "Input denominator: ";
    in >> rational.denominator;
    return in;
}

void Rational::printRational()
{
    std::cout << numerator << "/" << denominator;
}

void Rational::printRationalAsDouble()
{
    std::cout << (double) (numerator / denominator);
}

#endif

// 2023_03_17
// By Li