#include "dynamic_array.h"
#include <iostream>

int main() {
    DynamicArray arr(5);
    arr.print();

    arr.set(0, 1);
    arr.set(1, -2);
    arr.set(2, 3);
    arr.set(3, -4);
    arr.set(4, 5);
    arr.print();

    // тестирование 1 задания
    std::cout << "\n1 excercise\n" << std::endl;
    arr.set(0, 999);
    arr.set(100, 5);// должны быть ошибки

    arr.get(2);
    arr.get(100);// должна быть ошибка

    // тестирование 2 задания
    std::cout << "\n2 excercise\n" << std::endl;
    DynamicArray copy_arr(arr);
    copy_arr.set(0, 58);
    copy_arr.set(1, 86);
    std::cout << "Original: ";
    arr.print();
    std::cout << "Copy: ";
    copy_arr.print();

    // тестирование 3 задания
    std::cout << "\n3 excercise\n" << std::endl;
    arr.push_back(53);
    std::cout << "New array: ";
    arr.print();
    arr.push_back(800);// должна быть ошибка

    // тестирование 4 задания
    std::cout << "\n4 excercise\n" << std::endl;
    std::cout << "arr: ";
    arr.print();
    std::cout << "copy: ";
    copy_arr.print();

    arr.add(copy_arr);
    std::cout << "arr plus copy_arr: ";
    arr.print();
    //std::cout << std::endl;

    copy_arr.add(copy_arr);
    std::cout << "copy_arr plus copy_arr: ";
    copy_arr.print();
    copy_arr.sub(arr);
    std::cout << "copy_arr minus arr: ";
    copy_arr.print();



    return 0;
}