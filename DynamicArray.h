#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
using namespace std;

// A list of ANY type that grows by itself. Member A completes the TODOs.
// IMPORTANT: always pass a DynamicArray by reference (&), never by value.
template <typename T>
class DynamicArray {
private:
    T* data;        // dynamic array on the heap
    int count;      // how many items are stored
    int capacity;   // how many items fit before we must grow
    T invalidItem;  // returned by operator[] when the index is wrong

    void grow();    // double the capacity (new bigger array, copy, delete old)

public:
    DynamicArray(int cap = 2);
    ~DynamicArray();

    void add(const T& value);   // add at the end (grow first if full)
    bool removeAt(int index);   // remove and shift left; false if index is invalid
    T& operator[](int index);   // read/write an item; print "Invalid index" if wrong
    int size() const;
    bool isEmpty() const;
};

template <typename T>
DynamicArray<T>::DynamicArray(int cap) {
    if (cap <= 0) {
        cap = 2;
    }
    capacity = cap;
    count = 0;
    data = new T[capacity];
    invalidItem = T();
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
    data = nullptr;
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
        grow();
    }
    data[count] = value;
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
        cout << "Invalid index" << endl;
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
