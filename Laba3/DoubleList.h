#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <stdexcept>

template<typename T>
class DoubleList {
public:
    struct Element {
        T data;
        Element* next;
        Element* prev;
        Element(const T& v) : data(v), next(nullptr), prev(nullptr) {}
    };

private:
    Element* head;
    Element* tail;
    size_t count;

public:
    DoubleList();
    ~DoubleList();

    void push_front(const T& val);
    void push_back(const T& val);
    void insert(int index, const T& val);

    void pop_front();
    void pop_back();
    void remove(const T& val);

    size_t size() const;
    bool empty() const;

    T& front();
    T& back();

    void clear();
    void reverse();


    class Iterator {
        DoubleList<T>* list;
        Element* cur;
    public:
        Iterator(DoubleList<T>* l = nullptr, Element* p = nullptr);
        T& operator*() const;
        T* operator->() const;

        bool operator==(const Iterator& o) const;
        bool operator!=(const Iterator& o) const;

        Iterator& operator++();
        Iterator operator++(int);

        Iterator& operator--();
        Iterator operator--(int);
    };

    Iterator begin();
    Iterator end();
};

#include "DoubleList.cpp" 

#endif