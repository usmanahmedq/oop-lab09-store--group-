#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
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

    bool operator<(const Product& other) const {
        return price < other.price;
    }

    bool operator>(const Product& other) const {
        return price > other.price;
    }

    bool operator==(const Product& other) const {
        return name == other.name;
    }

    friend std::ostream& operator<<(std::ostream& out, const Product& product) {
        out << product.name << " | Rs. " << product.price
            << " | qty " << product.quantity;
        return out;
    }
};

#endif