#pragma once
#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <cmath>

template <typename T>
class DynamicArray;
template <typename T>
std::ostream& operator<<(std::ostream& os, const DynamicArray<T>& arr);

template <typename T>
double distance(const DynamicArray<T>& arr1, const DynamicArray<T>& arr2);

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

    friend std::ostream& operator<<<T>(std::ostream& os, const DynamicArray<T>& arr);
    friend double distance<T>(const DynamicArray<T>& arr1, const DynamicArray<T>& arr2);

};