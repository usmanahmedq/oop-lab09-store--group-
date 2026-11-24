#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    std::string name;
    double price;
    int quantity;

public:
    Product(std::string n = "", double p = 0, int q = 0)
        : name(n), price(p), quantity(q) {}

    std::string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    double stockValue() const {
        return price * quantity;
    }
};

#endif