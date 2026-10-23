#pragma once
#include <iostream>
#include <stdexcept>
#include <type_traits>

template <typename T>
class DynamicArray {
private:
    T* pointer;
    int size;

public:
    DynamicArray(int size);
    DynamicArray(const DynamicArray& other);
    ~DynamicArray();

    void print() const;
    void set(int index, const T& value);
    T get(int index) const;
    void push_back(const T& value);
    void add(const DynamicArray& other);
    void sub(const DynamicArray& other);
};