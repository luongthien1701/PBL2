#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Vector{
    private:
        T* data;
        int size;
    public:
        Vector(int);
        ~Vector();
        void push_back(const T &);
        int getsize()const;
        T& operator [](int);
        const T& operator[](int) const;
        void update (int,const T &);
};
#include "vector.cpp"