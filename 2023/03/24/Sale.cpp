#include <iostream>

class Sale
{
    friend std::ostream& operator<<(std::ostream&, const Sale&);
    friend std::istream& operator>>(std::istream&, Sale&);
    private:
        int receiptNum;
        double saleAmount;
    public:
        Sale(int num, double sale) : receiptNum(num), saleAmount(sale) {}
};

std::ostream& operator<<(std::ostream& out, const Sale& aSale)
{
    out << "Sale #" << aSale.receiptNum <<
        " for $" << aSale.saleAmount << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Sale& aSale)
{
    std::cout << std::endl;
    std::cout << "Enter receipt number ";
    in >> aSale.receiptNum;
    std::cout << "Enter the amount of the same ";
    in >> aSale.saleAmount;
    std::cout<< std::endl << "\tThank you!" << std::endl;
    return in;
}

int main()
{
    Sale aShirt(0,0);
    std::cin >> aShirt;
    std::cout << aShirt;
    return 0;
}