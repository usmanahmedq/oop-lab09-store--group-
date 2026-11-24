#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>

template <typename T>
class DynamicArray {
private:
    T* data;
    int count;
    int capacity;
    T invalidItem{};

    void grow();

public:
    DynamicArray(int cap = 2);
    ~DynamicArray();

    DynamicArray(const DynamicArray&) = delete;
    DynamicArray& operator=(const DynamicArray&) = delete;

    void add(const T& value);
    bool removeAt(int index);
    T& operator[](int index);
    int size() const;
    bool isEmpty() const;
};

template <typename T>
DynamicArray<T>::DynamicArray(int cap) {
    capacity = (cap < 1) ? 1 : cap;
    count = 0;
    data = new T[capacity];
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

template <typename T>
void DynamicArray<T>::grow() {
    int newCapacity = capacity * 2;
    T* newData = new T[newCapacity];

    for (int i = 0; i < count; i++) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    capacity = newCapacity;
}

template <typename T>
void DynamicArray<T>::add(const T& value) {
    if (count == capacity) {
        // Save the value in case it refers to an item in this array.
        T savedValue = value;
        grow();
        data[count] = savedValue;
    } else {
        data[count] = value;
    }

    count++;
}

template <typename T>
bool DynamicArray<T>::removeAt(int index) {
    if (index < 0 || index >= count) {
        return false;
    }

    for (int i = index; i < count - 1; i++) {
        data[i] = data[i + 1];
    }

    count--;
    return true;
}

template <typename T>
T& DynamicArray<T>::operator[](int index) {
    if (index < 0 || index >= count) {
        std::cout << "Invalid index " << index << '\n';
        return invalidItem;
    }

    return data[index];
}

template <typename T>
int DynamicArray<T>::size() const {
    return count;
}

template <typename T>
bool DynamicArray<T>::isEmpty() const {
    return count == 0;
}

#endif