#include "vector.h"

template <typename T>
Vector<T>::Vector(int capacity) {
    data = new T[capacity];
    size = 0;
}

template <typename T>
Vector<T>::~Vector() {
    delete[] data;
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    data[size++] = value;
}

template <typename T>
int Vector<T>::getsize() const {
    return size;
}

template <typename T>
T& Vector<T>::operator[](int index) {
    return data[index];
}

template <typename T>
const T& Vector<T>::operator[](int index) const {
    return data[index];
}

template <typename T>
void Vector<T>::update(int index, const T& value) {
    data[index] = value;
}