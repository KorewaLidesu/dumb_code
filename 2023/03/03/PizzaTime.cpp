#include <string>
#include <iostream>

class Pizza
{
    private:
        std::string topping;
        int diameter;
        double price;
        const static std::string STDTOP;
        const static int STDSIZE;
        const static double STDPRICE;
    public:
        Pizza(std::string = STDTOP, int = STDSIZE, double = STDPRICE);
        void setValues();
        void displayValues();
};

const std::string Pizza::STDTOP = "cheese";
const int Pizza::STDSIZE = 12;
const double Pizza::STDPRICE = 8.99;

Pizza::Pizza(const std::string top, const int size, const double price)
{
    topping = top;
    diameter = size;
    this -> price = price;
}

void Pizza::displayValues() {
    std::cout << "a " << diameter << " inch " 
        << topping << " pizza. Prize $" << price << std::endl;
}

void Pizza::setValues() {
    const double TOPPINGPREMIUM = 1.00;
    const double SIZEPREMIUM = 1.50;
    std::cout << "Enter topping ";
    std::cin >> topping;
    if (topping != STDTOP)
        price = STDPRICE + TOPPINGPREMIUM;
    std::cout << "Enter size ";
    std::cin >> diameter;
    if (diameter > STDSIZE)
        price += SIZEPREMIUM;
}

int main()
{
    Pizza stdPizza;
    Pizza special("pineapple");
    Pizza deluxeSpecial("sausage", 16);
    Pizza veryDeluxeSpecial("lobster", 20, 17.99);
    std::cout << "The standard pizza is: ";
    stdPizza.displayValues();
    std::cout << "Today's special is ";
    special.displayValues();
    std::cout << "The deluxe special is ";
    deluxeSpecial.displayValues();
    std::cout << "The very deluxe special is ";
    veryDeluxeSpecial.displayValues();
}