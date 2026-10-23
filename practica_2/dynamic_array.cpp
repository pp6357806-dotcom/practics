#include "dynamic_array.h"
#include <iostream>
#include <string>

template <typename T>
DynamicArray<T>::DynamicArray(int size) : pointer(nullptr), size(size) {
    if (size > 0) {
        pointer = new T[size]();
    }
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other) : pointer(nullptr), size(other.size) {
    if (size > 0) {
        pointer = new T[size];
        for (int i = 0; i < size; ++i) {
            pointer[i] = other.pointer[i];
        }
    }
}

template <typename T>
DynamicArray<T>::~DynamicArray(){
    delete[] pointer;
}

template <typename T>
void DynamicArray<T>::print() const{
    std::cout << "[";
    for(int i = 0; i < size; i++){
        std::cout << pointer[i];
        if (i != size-1){
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

template <typename T>
void DynamicArray<T>::set(int index, const T& value){
    if (index >= size){
        throw std::out_of_range("the index " + std::to_string(index) + " is out of the array bounds");
    }
    if constexpr (std::is_integral_v<T>) {
        if (value < -100 || value > 100){
            throw std::invalid_argument("the value of " + std::to_string(value) + " is out of range [-100, 100]");
        }
    }
    pointer[index] = value;
}

template <typename T>
T DynamicArray<T>::get(int index) const{
    if (index >= size){
        throw std::out_of_range("the index " + std::to_string(index) + " is out of the array bounds");
    }
    return pointer[index];
}

template <typename T>
void DynamicArray<T>::push_back(const T& value){
    if constexpr (std::is_integral_v<T>) {
        if (value < -100 || value > 100){
            throw std::invalid_argument("the value of " + std::to_string(value) + " is out of range [-100, 100]");
        }
    }
    T* NewPointer = new T[size+1];
    for (int i = 0; i < size; ++i) {
        NewPointer[i] = pointer[i];
    }
    NewPointer[size] = value;

    delete[] pointer;
    pointer = NewPointer;
    size += 1;

}

template <typename T>
void DynamicArray<T>::add(const DynamicArray& other){
    for (int i = 0; i < size; i++){
        T cur = pointer[i];
        if (i < other.size){
            cur = pointer[i] + other.pointer[i];
        }
        if constexpr (std::is_integral_v<T>) {
            if (cur > 100 || cur < -100) {
                throw std::invalid_argument("Value out of range in sub");
            }
        }
        pointer[i] = cur;
    }
}

template <typename T>
void DynamicArray<T>::sub(const DynamicArray& other){
    if constexpr (std::is_integral_v<T>) {
        for (int i = 0; i < size; i++){
            T cur = pointer[i];
            if (i < other.size){
                cur = pointer[i] - other.pointer[i];
            }
            if (-100 <= cur && cur <= 100){
                pointer[i] = cur;
            }
        }
    }
}

template class DynamicArray<int>;
template class DynamicArray<double>;
template class DynamicArray<char>;
template class DynamicArray<std::string>;
