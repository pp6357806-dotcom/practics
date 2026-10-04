#include "dynamic_array.h"
#include <iostream>

DynamicArray::DynamicArray(int size) : pointer(nullptr), size(size){
    if (size > 0) {
        pointer = new int[size]();
    }

}

DynamicArray::DynamicArray(const DynamicArray& other) : pointer(nullptr), size(other.size) {
    if (size > 0) {
        pointer = new int[size];
        for (size_t i = 0; i < size; ++i) {
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
        std::cout << "The index is out of the array bounds " << std::endl;
        return;
    }
    if (-100 > value|| value > 100){
        std::cout << "Value out of range " << std::endl;
        return;
    }
    pointer[index] = value;
}

int DynamicArray::get(int index) const{
    if (index >= size){
        std::cout << "The index is out of the array bounds " << std::endl;
        return 0;
    }
    return pointer[index];
}

void DynamicArray::push_back(int value){
    if (-100 > value|| value > 100){
        std::cout << "Value out of range " << std::endl;
        return;
    }
    int* NewPointer = new int[size+1];
    for (size_t i = 0; i < size; ++i) {
        NewPointer[i] = pointer[i];
    }
    NewPointer[size] = value;

    delete[] pointer;
    pointer = NewPointer;
    size += 1;

}