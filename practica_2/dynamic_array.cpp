#include "dynamic_array.h"
#include <iostream>

DynamicArray::DynamicArray(int size) : pointer(0), val(size){
    if (size > 0) {
        pointer = new int[val]();
    }
}
DynamicArray::~DynamicArray(){
    delete[] pointer;
}

void DynamicArray::print() const{
    std::cout << "[";
    for(int i = 0; i < val; i++){
        std::cout << pointer[i];
        if (i != val){
            std::cout << ",";
        }
        std::cout << "]";
    }
}

void DynamicArray::set(int index, int value) const{
    if (index >= value){
        std::cout << "Индекс выходит за границу массива, предельное значение: " << value;
        return;
    }
    if (-100 > value|| value > 100){
        std::cout << "Значение вне диапазона" << std::endl;
        return;
    }
    pointer[index] = value;
}

void DynamicArray::get(int index, int value) const{
    if (index >= value){
        std::cout << "Индекс выходит за границу массива, предельное значение: " << value;
        return;
    }
}