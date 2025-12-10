#include "DoubleList.h"

template<typename T>
DoubleList<T>::DoubleList() : head(nullptr), tail(nullptr), count(0) {}

template<typename T>
DoubleList<T>::~DoubleList() {
    Node* cur = head;
    while (cur) {
        Node* tmp = cur->next;
        delete cur;
        cur = tmp;
    }
}

template<typename T>
void DoubleList<T>::push_back(const T& value) {
    Node* n = new Node(value);
    if (!head) head = tail = n;
    else {
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
    count++;
}

template<typename T>
void DoubleList<T>::print() const {
    Node* cur = head;
    while (cur) {
        std::cout << cur->data << " ";
        cur = cur->next;
    }
    std::cout << "\n";
}

// ---------------- Shell Sort (через вектор) ----------------
template<typename T>
void DoubleList<T>::shell_sort() {
    if (count < 2) return;

    std::vector<T> v;
    v.reserve(count);

    for (Node* cur = head; cur; cur = cur->next)
        v.push_back(cur->data);

    shell_sort_vector(v);

    Node* cur = head;
    size_t i = 0;
    while (cur) {
        cur->data = v[i++];
        cur = cur->next;
    }
}

// ---------------- Quick Sort ----------------
template<typename T>
void DoubleList<T>::quick_sort() {
    if (count < 2) return;

    std::vector<T> v;
    v.reserve(count);

    for (Node* cur = head; cur; cur = cur->next)
        v.push_back(cur->data);

    quick_sort_recursive(v, 0, (int)v.size() - 1);

    Node* cur = head;
    size_t i = 0;
    while (cur) {
        cur->data = v[i++];
        cur = cur->next;
    }
}

template class DoubleList<int>;