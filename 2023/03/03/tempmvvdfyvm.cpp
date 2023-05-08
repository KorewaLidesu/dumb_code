#include <string>
#include <iostream>

class Pizza
{
    private:
        string name;
        int price;
        double discount;
    public:
        Pizza(std::string, int, double);
        void displayValues();
}

Pizza::Pizza(std::string name = "", int price = , double discount = )
{
    Pizza::name = name;
    Pizza::price = price;
    Pizze::discount = discount;
}

void Pizza::displayValues() {
    std::cout << "Test";
}

int main()
{
    Pizza stdPizza;
    Pizza special("pineapple");
    Pizza deluxeSpecial("sausage", 16);
    Pizza veryDeluxeSpecial("lobster", 20, 17.99);
    cout << "The standard pizza is: "
    stdPizza.displayValues();
    cout << "Today's special is "
    special.displayValues();
    cout << "The deluxe special is "
    deluxeSpecial.displayValues();
    cout << "The very deluxe special is "
    veryDeluxeSpecial.displayValues();
}