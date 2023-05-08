template <class T>
void repeatValue(T& val, int times)
{
    int x;
    for(x = 0; x < times; ++x)
        val++;
}

#include <iostream>
#include <string>

class Store
{
    friend std::ostream& operator<<(std::ostream&, Store);
    private:
        int storeNumber;
        std::string streetAddress;
        std::string manager;
    public:
        Store(int = 0, std::string = "", std::string = "");
        Store operator++(int);
        Store operator++();
};

Store::Store(int num, std::string add, std::string mgr)
{
    storeNumber = num;
    streetAddress = add;
    manager = mgr;
}

std::ostream& operator<<(std::ostream& out, Store store)
{
    out << "Store #" << store.storeNumber <<
        " Address: " << store.streetAddress <<
        " Manager name: " << store.manager;
    return out;
}

Store Store::operator++(int input)
{
    storeNumber++;
    return *this;
}

Store Store::operator++()
{
    ++storeNumber;
    return *this;
}

int main()
{
    int a = 7;
    double b = 4.5;
    // char c = 'C';
    // string name = "Alice";
    Store store(718, "47 Pine Avenue", "Julia Winters");
    repeatValue(a, 3);
    repeatValue(b, 4);
    // repeatValue(c, 5);
    // repeatValue(name, 6);
    repeatValue(store, 3);
    std::cout << a << std::endl
        << b << std::endl
        << store << std::endl;
}
