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
        Rectangle(double length = 1.0, double width = 1.0)
            : length(length), width(width) {}
        bool operator==(Rectangle);
        bool operator!=(Rectangle);
        double perimeter() { return 2 * (length + width); }
        double area() { return length * width; }
        void setWidth(double w) { width = w; }
        void setLength(double l) { length = l; }
        double getWidth() { return width; }
        double getLength() { return length; }
    private:
        double length;
        double width;
};

bool Rectangle::operator==(Rectangle compare)
{
    return this->length == compare.length && this->width == compare.width;
}

bool Rectangle::operator!=(Rectangle compare)
{
    return this->length != compare.length || this->width != compare.width;
}

#endif

// 2023_03_17
// By Li