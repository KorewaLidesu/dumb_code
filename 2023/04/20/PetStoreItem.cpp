class PetStoreItem
{
protected:
    int stockNum;
    double price;
public:
    PetStoreItem(int, double);
};

PetStoreItem::PetStoreItem(int stock, double pr)
{
    stockNum = stock;
    price = pr;
}

class PetStoreAnimal : public PetStoreItem
{
    protected:
        int petAge;
    public:
        PetStoreAnimal(int, double, int);
};

PetStoreAnimal::PetStoreAnimal(int stock, double pr, int age) : PetStoreItem(stock, pr)
{
    petAge = age;
}

int main()
{
    PetStoreAnimal pet(111, 45.00, 1);
}