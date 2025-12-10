#ifndef ONELIST_H
#define ONELIST_H

#include <stdexcept>

template<typename T>
class OneList {
public:
    struct Element {
        T data;
        Element* next;
        Element(const T& v) : data(v), next(nullptr) {}
    };

private:
    Element* head;
    Element* tail;
    size_t count;

public:
    OneList();
    ~OneList();

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
        OneList<T>* list;
        Element* cur;
    public:
        Iterator(OneList<T>* l = nullptr, Element* p = nullptr);
        T& operator*() const;

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

#include "OneList.cpp"   // шаблон → реализация подключается здесь

#endif