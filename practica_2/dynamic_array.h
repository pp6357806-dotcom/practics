#pragma once
#include <iostream>

class DynamicArray{
private:
    int* pointer;
    int size;
public:
DynamicArray(int size);
DynamicArray(const DynamicArray& other);
~DynamicArray();

void print() const;

void set(int index, int value);
int get(int index) const;
void push_back(int value);
};