#include <iostream>
#include <string>
#include "DynamicArray.h"

int main() {
    DynamicArray<int> numbers(2);

    for (int value = 10; value <= 50; value += 10) {
        numbers.add(value);
    }

    std::cout << "Size: " << numbers.size() << '\n';

    numbers.removeAt(1);  // Index 1 par 20 hai
    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << ' ';
    }
    std::cout << '\n';

    numbers[0] = 99;
    std::cout << "First: " << numbers[0] << '\n';

    numbers[7];  // Galat index ko jaan-boojh kar test karo

        DynamicArray<std::string> words(1);
    words.add("template");
    words.add("works");

    std::cout << words[0] << ' ' << words[1] << '\n';
    
    return 0;
}