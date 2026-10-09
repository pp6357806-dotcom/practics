#include "dynamic_array.h"
#include <iostream>
#include <string>

DynamicArray::DynamicArray(int size) : pointer(nullptr), size(size){
    if (size > 0) {
        pointer = new int[size]();
    }

}

DynamicArray::DynamicArray(const DynamicArray& other) : pointer(nullptr), size(other.size) {
    if (size > 0) {
        pointer = new int[size];
        for (int i = 0; i < size; ++i) {
            pointer[i] = other.pointer[i];
        }
    }
}

DynamicArray::~DynamicArray(){
    delete[] pointer;
}

void DynamicArray::print() const{
    std::cout << "[";
    for(int i = 0; i < size; i++){
        std::cout << pointer[i];
        if (i != size-1){
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

void DynamicArray::set(int index, int value){
    if (index >= size){
        throw std::out_of_range("the index " + std::to_string(index) + " is out of the array bounds");
    }
    if (-100 > value|| value > 100){
        throw std::invalid_argument("the value of " + std::to_string(value) + " is out of range [-100, 100]");
    }
    pointer[index] = value;
}

int DynamicArray::get(int index) const{
    if (index >= size){
        throw std::out_of_range("the index " + std::to_string(index) + " is out of the array bounds");
    }
    return pointer[index];
}

void DynamicArray::push_back(int value){
    if (-100 > value|| value > 100){
        throw std::invalid_argument("the value of " + std::to_string(value) + " is out of range [-100, 100]");
    }
    int* NewPointer = new int[size+1];
    for (int i = 0; i < size; ++i) {
        NewPointer[i] = pointer[i];
    }
    NewPointer[size] = value;

    delete[] pointer;
    pointer = NewPointer;
    size += 1;

}
void DynamicArray::add(const DynamicArray& other){
    for (int i = 0; i < size; i++){
        int cur = pointer[i];
        if (i < other.size){
            cur = pointer[i] + other.pointer[i];
        }
        if (-100 <= cur && cur <= 100){
            pointer[i] = cur;
        }
    }
}
void DynamicArray::sub(const DynamicArray& other){
    for (int i = 0; i < size; i++){
        int cur = pointer[i];
        if (i < other.size){
            cur = pointer[i] - other.pointer[i];
        }
        if (-100 <= cur && cur <= 100){
            pointer[i] = cur;
        }
    }
}