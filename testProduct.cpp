#include <iostream>
#include "Product.h"
#include "Algorithms.h"

int main() {
    Product pen("Pen", 50, 100);
    Product bag("Bag", 900, 10);

    std::cout << pen << '\n';
    std::cout << bag << '\n';
    std::cout << "Pen < Bag (by price)? " << (pen < bag) << '\n';
    std::cout << "Bag > Pen (by price)? " << (bag > pen) << '\n';
    std::cout << "Pen == Pen (by name)? " << (pen == Product("Pen")) << '\n';
    std::cout << "Pen stock value: " << pen.stockValue() << '\n';

    DynamicArray<int> numbers;
    numbers.add(30);
    numbers.add(10);
    numbers.add(20);

    sortAscending(numbers);
    printAll(numbers);
    std::cout << "Max: " << maxItem(numbers)
              << ", index of 20: " << findIndex(numbers, 20) << '\n';

    return 0;
}