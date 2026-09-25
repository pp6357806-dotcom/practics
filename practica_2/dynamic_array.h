#pragma once
#include <iostream>

class DynamicArray{
private:
    int* pointer;
    int val;
public:
DynamicArray(int value){
}
~DynamicArray();

void print() const;

void set(int index, int value) const;
void get(int index, int value) const;
};