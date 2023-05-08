class Rectangle
{
    private:
        int length;
        int width;
    public:
        Rectangle(int L = 0, int W = 0) : length(L), width(W) {}
        int area() { return length * width; }
        void display();
};

class Block: public Rectangle
{
    private:
        int height;
    public:
        Block(int L = 0, int W = 0, int H = 0) : Rectangle(L, W), height(H) {}
        int surfaceArea() { }
        int totalArea() {}
        void display();
};

