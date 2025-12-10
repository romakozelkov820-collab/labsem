#include "OneList.h"

// ------------------ Конструкторы ------------------

template<typename T>
OneList<T>::OneList() : head(nullptr), tail(nullptr), count(0) {}

template<typename T>
OneList<T>::~OneList() { clear(); }

// ------------------ Основные методы ------------------

template<typename T>
void OneList<T>::push_front(const T& val) {
    Element* e = new Element(val);
    e->next = head;
    head = e;
    if (!tail) tail = e;
    ++count;
}

template<typename T>
void OneList<T>::push_back(const T& val) {
    Element* e = new Element(val);
    if (!head) {
        head = tail = e;
    } else {
        tail->next = e;
        tail = e;
    }
    ++count;
}

template<typename T>
void OneList<T>::insert(int index, const T& val) {
    if (index < 0 || index > count)
        throw std::out_of_range("insert");

    if (index == 0) return push_front(val);
    if (index == count) return push_back(val);

    Element* prev = head;
    for (int i = 0; i < index - 1; i++)
        prev = prev->next;

    Element* e = new Element(val);
    e->next = prev->next;
    prev->next = e;
    ++count;
}

template<typename T>
void OneList<T>::pop_front() {
    if (!head) return;
    Element* d = head;
    head = head->next;
    delete d;
    --count;
    if (!head) tail = nullptr;
}

template<typename T>
void OneList<T>::pop_back() {
    if (!head) return;
    if (head == tail) {
        delete head;
        head = tail = nullptr;
        count = 0;
        return;
    }
    Element* cur = head;
    while (cur->next != tail) cur = cur->next;
    delete tail;
    tail = cur;
    tail->next = nullptr;
    --count;
}

template<typename T>
void OneList<T>::remove(const T& val) {
    while (head && head->data == val) {
        Element* d = head;
        head = head->next;
        delete d;
        --count;
    }
    if (!head) { tail = nullptr; return; }

    Element* prev = head;
    while (prev->next) {
        if (prev->next->data == val) {
            Element* d = prev->next;
            prev->next = d->next;
            if (d == tail) tail = prev;
            delete d;
            --count;
        } else prev = prev->next;
    }
}

template<typename T>
size_t OneList<T>::size() const { return count; }

template<typename T>
bool OneList<T>::empty() const { return count == 0; }

template<typename T>
T& OneList<T>::front() { return head->data; }

template<typename T>
T& OneList<T>::back() { return tail->data; }

template<typename T>
void OneList<T>::clear() {
    while (head) pop_front();
}

template<typename T>
void OneList<T>::reverse() {
    Element* prev = nullptr;
    Element* cur = head;
    tail = head;
    while (cur) {
        Element* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}

// ------------------ Итератор ------------------

template<typename T>
OneList<T>::Iterator::Iterator(OneList<T>* l, Element* p) : list(l), cur(p) {}

template<typename T>
T& OneList<T>::Iterator::operator*() const { return cur->data; }

template<typename T>
bool OneList<T>::Iterator::operator==(const Iterator& o) const { return cur == o.cur; }

template<typename T>
bool OneList<T>::Iterator::operator!=(const Iterator& o) const { return cur != o.cur; }

template<typename T>
typename OneList<T>::Iterator& OneList<T>::Iterator::operator++() {
    if (cur) cur = cur->next;
    return *this;
}

template<typename T>
typename OneList<T>::Iterator OneList<T>::Iterator::operator++(int) {
    Iterator tmp = *this;
    ++(*this);
    return tmp;
}

template<typename T>
typename OneList<T>::Iterator& OneList<T>::Iterator::operator--() {
    if (cur == list->head) { cur = nullptr; return *this; }
    auto* p = list->head;
    auto* prev = nullptr;
    while (p != cur) { prev = p; p = p->next; }
    cur = prev;
    return *this;
}

template<typename T>
typename OneList<T>::Iterator OneList<T>::Iterator::operator--(int) {
    Iterator tmp = *this;
    --(*this);
    return tmp;
}

template<typename T>
typename OneList<T>::Iterator OneList<T>::begin() { return Iterator(this, head); }

template<typename T>
typename OneList<T>::Iterator OneList<T>::end() { return Iterator(this, nullptr); }