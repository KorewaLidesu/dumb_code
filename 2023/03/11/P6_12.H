// 2023_03_17
// By Li

#include <iostream>
#include <math.h>

// P6_12.H
#ifndef P6_12_H
#define P6_12_H

class Rectangle
{
    public:
        Rectangle(double = 1.0, double = 1.0);
        bool operator==(Rectangle);
        bool operator!=(Rectangle);
        double perimeter(void);
        double area(void);
        void setWidth(double w) { width = w; };
        void setLength(double l) { length = l; };
        double getWidth(void);
        double getLength(void);
    private:
        double length;
        double width;
};

Rectangle::Rectangle(double length, double width)
{
    this->length = length;
    this->width = width;
}

bool Rectangle::operator==(Rectangle compare)
{
    return this->length == compare.length && this->width == compare.width;
}

bool Rectangle::operator!=(Rectangle compare)
{
    return this->length != compare.length || this->width != compare.width;
}

double Rectangle::perimeter(void)
{
    return 2 * (length + width);
}

double Rectangle::area(void)
{
    return length * width;
}

double Rectangle::getWidth(void)
{
    return width;
}

double Rectangle::getLength(void)
{
    return length;
}

#endif

// 2023_03_17
// By Li