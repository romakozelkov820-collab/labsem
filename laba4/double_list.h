#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#include <iostream>
#include <vector>

// Вперёд объявляем сортировки
#include "shell_sort.h"
#include "quick_sort.h"

template<typename T>
class DoubleList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& d) : data(d), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t count;

public:
    DoubleList() : head(nullptr), tail(nullptr), count(0) {}
    ~DoubleList();

    void push_back(const T& value);
    void print() const;

    // Методы сортировки
    void shell_sort();
    void quick_sort();
};

#include "../src/double_list.cpp"

#endif