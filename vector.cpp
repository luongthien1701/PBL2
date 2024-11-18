#include "Vector.h"
#include <stdexcept>

template <typename T>
Vector<T>::Vector(int capacity) : capacity(capacity), size(0) {
    data = new T[capacity];
}

template <typename T>
Vector<T>::~Vector() {
    delete[] data;
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    if (size >= capacity) {
        throw std::out_of_range("Vector capacity exceeded");
    }
    data[size++] = value;
}

template <typename T>
int Vector<T>::getsize() const {
    return size;
}

template <typename T>
T& Vector<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
const T& Vector<T>::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}