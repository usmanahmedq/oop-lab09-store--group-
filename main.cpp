#include <iostream>
#include <string>
#include "DynamicArray.h"
#include "Product.h"
#include "Algorithms.h"

void addProduct(DynamicArray<Product>& store) {
    std::string name;
    double price;
    int quantity;

    std::cout << "Name, price, quantity: ";
    if (std::cin >> name >> price >> quantity) {
        store.add(Product(name, price, quantity));
        std::cout << name << " added\n";
    }
}

void removeProduct(DynamicArray<Product>& store) {
    std::string name;
    std::cout << "Name to remove: ";
    std::cin >> name;

    int index = findIndex(store, Product(name));
    if (store.removeAt(index)) {
        std::cout << name << " removed\n";
    } else {
        std::cout << "Product not found\n";
    }
}

void showProducts(DynamicArray<Product>& store) {
    if (store.isEmpty()) {
        std::cout << "Store is empty\n";
    } else {
        printAll(store);
    }
}

int main() {
    DynamicArray<Product> store;
    store.add(Product("Pen", 50, 100));
    store.add(Product("Notebook", 120, 40));
    store.add(Product("Bag", 900, 10));

    int choice;
    while (true) {
        std::cout << "\n1.Add 2.Remove 3.Show 4.Sort "
                     "5.Most expensive 6.Total value 0.Exit\nChoice: ";

        if (!(std::cin >> choice)) {
            return 0;
        }

        switch (choice) {
            case 0:
                std::cout << "Goodbye\n";
                return 0;
            case 1:
                addProduct(store);
                break;
            case 2:
                removeProduct(store);
                break;
            case 3:
                showProducts(store);
                break;
            default:
                std::cout << "Option unavailable\n";
        }
    }
}