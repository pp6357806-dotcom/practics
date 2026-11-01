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

    T& operator[](int index);
    bool operator==(const DynamicArray<T>& arr) const;
    bool operator!=(const DynamicArray<T>& arr) const;
    DynamicArray& operator+=(const DynamicArray<T>& arr);
    DynamicArray& operator-=(const DynamicArray<T>& arr);
    DynamicArray& operator+=(const T& var);
    DynamicArray& operator-=(const T& var);

    T* begin(){return pointer;}
    T* end(){return pointer+size;}
    const T* begin() const {return pointer;}
    const T* end() const {return pointer+size;}


    friend std::ostream& operator<<<T>(std::ostream& os, const DynamicArray<T>& arr);
    friend double distance<T>(const DynamicArray<T>& arr1, const DynamicArray<T>& arr2);

};