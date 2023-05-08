#include <iostream>

class Sale
{
    private:
        int receiptNum;
        double saleAmount;
    public:
        Sale(int, double);
        Sale operator+(Sale);
        void showSale();
};

Sale::Sale(int num, double sale)
{
    receiptNum = num;
    saleAmount = sale;
}

Sale Sale::operator+(Sale transaction)
{
    Sale temp(999, 0);
    temp.saleAmount = saleAmount + transaction.saleAmount;
    return temp;
}

void Sale::showSale()
{
    std::cout << "Sale #" << receiptNum <<
        " for $" << saleAmount << std::endl;
}

int main()
{
    Sale aShirt(1567, 39.95);
    Sale aTie(1568, 33.55);
    Sale pants(1569, 39.99);
    Sale total(0, 0);
    total = aShirt + aTie + pants;
    aShirt.showSale();
    aTie.showSale();
    pants.showSale();
    std::cout << std::endl << "Total:" << std::endl;
    total.showSale();
    return 0;
}