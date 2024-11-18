#pragma once

template <typename T>
class Vector {
private:
    T* data;
    int capacity;
    int size;

public:
    Vector(int capacity = 10);
    ~Vector();
    void push_back(const T& value);
    int getsize() const;
    T& operator[](int index);
    const T& operator[](int index) const;
};

#include "Vector.cpp"