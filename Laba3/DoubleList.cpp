#include "DoubleList.h"

// Constructor / Destructor
template<typename T>
DoubleList<T>::DoubleList() : head(nullptr), tail(nullptr), count(0) {}

template<typename T>
DoubleList<T>::~DoubleList() { clear(); }

// push_front
template<typename T>
void DoubleList<T>::push_front(const T& val) {
    Element* e = new Element(val);
    e->next = head;
    e->prev = nullptr;
    if (head) head->prev = e;
    head = e;
    if (!tail) tail = e;
    ++count;
}

// push_back
template<typename T>
void DoubleList<T>::push_back(const T& val) {
    Element* e = new Element(val);
    e->prev = tail;
    e->next = nullptr;
    if (tail) tail->next = e;
    tail = e;
    if (!head) head = e;
    ++count;
}

// insert at index 0..count
template<typename T>
void DoubleList<T>::insert(int index, const T& val) {
    if (index < 0 || index > (int)count) throw std::out_of_range("insert index");
    if (index == 0) { push_front(val); return; }
    if (index == (int)count) { push_back(val); return; }

    Element* cur = head;
    for (int i = 0; i < index; ++i) cur = cur->next;
    Element* e = new Element(val);
    e->prev = cur->prev;
    e->next = cur;
    cur->prev->next = e;
    cur->prev = e;
    ++count;
}

template<typename T>
void DoubleList<T>::pop_front() {
    if (!head) return;
    Element* d = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    delete d;
    --count;
}

template<typename T>
void DoubleList<T>::pop_back() {
    if (!tail) return;
    Element* d = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;
    delete d;
    --count;
}

template<typename T>
void DoubleList<T>::remove(const T& val) {
    Element* cur = head;
    while (cur) {
        if (cur->data == val) {
            Element* toDel = cur;
            Element* p = cur->prev;
            Element* n = cur->next;
            if (p) p->next = n; else head = n;
            if (n) n->prev = p; else tail = p;
            cur = n;
            delete toDel;
            --count;
        } else cur = cur->next;
    }
}

template<typename T>
size_t DoubleList<T>::size() const { return count; }

template<typename T>
bool DoubleList<T>::empty() const { return count == 0; }

template<typename T>
T& DoubleList<T>::front() { if (!head) throw std::runtime_error("front on empty"); return head->data; }

template<typename T>
T& DoubleList<T>::back() { if (!tail) throw std::runtime_error("back on empty"); return tail->data; }

template<typename T>
void DoubleList<T>::clear() {
    Element* cur = head;
    while (cur) {
        Element* n = cur->next;
        delete cur;
        cur = n;
    }
    head = tail = nullptr;
    count = 0;
}

// reverse by swapping next/prev pointers
template<typename T>
void DoubleList<T>::reverse() {
    Element* cur = head;
    Element* tmp = nullptr;
    while (cur) {
        tmp = cur->prev;
        cur->prev = cur->next;
        cur->next = tmp;
        cur = cur->prev; // moved to original next
    }
    if (tmp) {
        // tmp is prev of last processed element, new head is tmp->prev
        head = tmp->prev;
        // recompute tail
        tail = head;
        while (tail && tail->next) tail = tail->next;
    }
}

// ---------------- Iterator ----------------

template<typename T>
DoubleList<T>::Iterator::Iterator(DoubleList<T>* l, Element* p) : list(l), cur(p) {}

template<typename T>
T& DoubleList<T>::Iterator::operator*() const { return cur->data; }

template<typename T>
T* DoubleList<T>::Iterator::operator->() const { return &(cur->data); }

template<typename T>
bool DoubleList<T>::Iterator::operator==(const Iterator& o) const { return cur == o.cur; }

template<typename T>
bool DoubleList<T>::Iterator::operator!=(const Iterator& o) const { return cur != o.cur; }

template<typename T>
typename DoubleList<T>::Iterator& DoubleList<T>::Iterator::operator++() {
    if (cur) cur = cur->next;
    return *this;
}

template<typename T>
typename DoubleList<T>::Iterator DoubleList<T>::Iterator::operator++(int) {
    Iterator tmp = *this;
    ++(*this);
    return tmp;
}

template<typename T>
typename DoubleList<T>::Iterator& DoubleList<T>::Iterator::operator--() {
    if (cur) cur = cur->prev;
    else if (list) cur = list->tail;
    return *this;
}

template<typename T>
typename DoubleList<T>::Iterator DoubleList<T>::Iterator::operator--(int) {
    Iterator tmp = *this;
    --(*this);
    return tmp;
}

template<typename T>
typename DoubleList<T>::Iterator DoubleList<T>::begin() { return Iterator(this, head); }

template<typename T>
typename DoubleList<T>::Iterator DoubleList<T>::end() { return Iterator(this, nullptr); }