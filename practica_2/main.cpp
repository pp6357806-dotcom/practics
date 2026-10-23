#include "dynamic_array.h"
#include <iostream>
#include <string>

int main() {
    // try {
    //     DynamicArray<int> arr(5);
    // }
    // catch(std::bad_alloc& e){
    //     std::cout << e.what() << std::endl;
    // }
    DynamicArray<int> arr(5);
    std::cout << arr << std::endl;

    arr.set(0, 1);
    arr.set(1, -2);
    arr.set(2, 3);
    arr.set(3, -4);
    arr.set(4, 5);
    std::cout << arr << std::endl;

    // тестирование 1.1 задания
    std::cout << "\n1.1 excercise\n" << std::endl;
    try {
        arr.set(0, 999);
    }
    catch(std::out_of_range& e){
        std::cout << e.what() << std::endl;
    } catch(std::invalid_argument& e){
        std::cout << e.what() << std::endl;
    } catch(std::bad_alloc& e){
        std::cout << e.what() << std::endl;
    }

    try {
        arr.set(100, 5);// должны быть ошибки
    }
    catch(std::out_of_range& e){
        std::cout << e.what() << std::endl;
    } catch(std::invalid_argument& e){
        std::cout << e.what() << std::endl;
    } catch(std::bad_alloc& e){
        std::cout << e.what() << std::endl;
    }

    try {
        arr.get(2);
    }
    catch(std::out_of_range& e){
        std::cout << e.what() << std::endl;
    } catch(std::invalid_argument& e){
        std::cout << e.what() << std::endl;
    } catch(std::bad_alloc& e){
        std::cout << e.what() << std::endl;
    }

    try {
        arr.get(100);// должна быть ошибка
    }
    catch(std::out_of_range& e){
        std::cout << e.what() << std::endl;
    } catch(std::invalid_argument& e){
        std::cout << e.what() << std::endl;
    } catch(std::bad_alloc& e){
        std::cout << e.what() << std::endl;
    }

    // тестирование 1.2 задания
    std::cout << "\n1.2 excercise\n" << std::endl;
    DynamicArray<int> copy_arr(arr);
    try {
        copy_arr.set(0, 58);
    }
    catch(std::out_of_range& e){
        std::cout << e.what() << std::endl;
    } catch(std::invalid_argument& e){
        std::cout << e.what() << std::endl;
    } catch(std::bad_alloc& e){
        std::cout << e.what() << std::endl;
    }
    try {
        copy_arr.set(1, 86);
    }
    catch(std::out_of_range& e){
        std::cout << e.what() << std::endl;
    } catch(std::invalid_argument& e){
        std::cout << e.what() << std::endl;
    } catch(std::bad_alloc& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << "Original: " << arr;
    std::cout << "Copy: " << copy_arr << std::endl;

    // тестирование 1.3 задания
    std::cout << "\n1.3 excercise\n" << std::endl;
    try {
        arr.push_back(53);
    }
    catch(std::out_of_range& e){
        std::cout << e.what() << std::endl;
    } catch(std::invalid_argument& e){
        std::cout << e.what() << std::endl;
    } catch(std::bad_alloc& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << "New array: " << arr << std::endl;
    try {
        arr.push_back(800);// должна быть ошибка
    }
    catch(std::out_of_range& e){
        std::cout << e.what() << std::endl;
    } catch(std::invalid_argument& e){
        std::cout << e.what() << std::endl;
    } catch(std::bad_alloc& e){
        std::cout << e.what() << std::endl;
    }

    // тестирование 1.4 задания
    std::cout << "\n1.4 excercise\n" << std::endl;
    std::cout << "arr: " << arr;
    std::cout << "copy: " << copy_arr << std::endl;

    try {
        arr.add(copy_arr);
        std::cout << "arr plus copy_arr: " << arr;
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        copy_arr.add(copy_arr);
        std::cout << "copy_arr plus copy_arr: " << copy_arr;
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
    
    try {
        copy_arr.sub(arr);
        std::cout << "copy_arr minus arr: "<< copy_arr << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    //тестирование 3.1
    std::cout << "\n3.1 excercise\n" << std::endl;

    DynamicArray<std::string> arr_new(5);

    arr_new.set(0, std::string("apple"));
    arr_new.set(1, std::string("pear"));
    arr_new.set(2, std::string("lemon"));
    arr_new.set(3, std::string("orange"));
    arr_new.set(4, std::string("banana"));
    std::cout << "string test: " << arr_new << std::endl;

    return 0;
}