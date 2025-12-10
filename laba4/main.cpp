#include <iostream>
#include "include/double_list.h"

int main() {
    DoubleList<int> lst;

    lst.push_back(7);
    lst.push_back(2);
    lst.push_back(9);
    lst.push_back(1);

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