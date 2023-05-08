class InventoryItem {
    private:
        int number;
        double price;
    public:
        void setNum(int);
        void setPrice(double);
        void displayItem();
};

void InventoryItem::setNum(int number) {
    InventoryItem::number = number;
}

void InventoryItem::setPrice(double price) {
    InventoryItem::price = price;
}

void InventoryItem::displayItem() {
    
}