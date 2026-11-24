#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <iostream>
#include "DynamicArray.h"

template <typename T>
void printAll(DynamicArray<T>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << i + 1 << ". " << arr[i] << '\n';
    }
}

template <typename T>
int findIndex(DynamicArray<T>& arr, const T& value) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

template <typename T>
void sortAscending(DynamicArray<T>& arr) {
    for (int end = arr.size() - 1; end > 0; end--) {
        for (int i = 0; i < end; i++) {
            if (arr[i + 1] < arr[i]) {
                T temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}

template <typename T>
T maxItem(DynamicArray<T>& arr) {
    if (arr.isEmpty()) {
        return T{};
    }

    T largest = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

#endif