#include <iostream>

class Rectangle
{
    protected:
        int length;
        int width;
    public:
        Rectangle(int length = 0, int width = 0) : length(length), width(width) {}
        int area() { return length * width; }
        void display();
};

void Rectangle::display()
{
    std::cout << "Rectangle:" << std::endl
        << "- Length: " << length << std::endl
        << "- Width: " << width << std::endl
        << "- Area: " << area() << std::endl;
}

class Block: public Rectangle
{
    private:
        int height;
    public:
        Block(int length = 0, int width = 0, int height = 0) : Rectangle(length, width), height(height) {}
        int surfaceArea() { return (length + width) * 2 * height; }
        int totalArea() { return surfaceArea() + 2 * area(); }
        void display();
};

void Block::display()
{
    std::cout << "Block:" << std::endl
        << "- Length: " << length << std::endl
        << "- Width: " << width << std::endl
        << "- Height: " << height << std::endl
        << "- Surface Area: " << surfaceArea() << std::endl
        << "- Total Area: " << totalArea() << std::endl;
}

