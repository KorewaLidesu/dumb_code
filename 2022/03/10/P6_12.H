#ifndef p6_12_H
#define p6_12_H

class Rectangle
{
    public:
        Rectangle(double = 1.0, double = 1.0);
        double perimeter();
        double area();
        void setWidth(double w);
        void setLength(double l);
        double getWidth();
        double getLength();
    private:
        double length;
        double width;
};



#endif