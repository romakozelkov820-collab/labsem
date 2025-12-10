#include <iostream>
#include "DoubleList.h"

int main() {
    DoubleList<int> lst;

    lst.push_back(5);
    lst.push_back(1);
    lst.push_back(3);
    lst.push_back(7);

    std::cout << "Исходный список: ";
    lst.print();

    lst.shell_sort();
    std::cout << "После Shell Sort: ";
    lst.print();

    lst.quick_sort();
    std::cout << "После Quick Sort: ";
    lst.print();

    return 0;
}