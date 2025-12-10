#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <vector>

// Partition

template<typename T>
int partition_vector(std::vector<T>& a, int low, int high) {
    T pivot = a[(low + high) / 2];
    int l = low, r = high;
    while (l <= r) {
        while (a[l] < pivot) l++;
        while (a[r] > pivot) r--;
        if (l <= r) {
            std::swap(a[l], a[r]);
            l++; r--;
        }
    }
    return l;
}

// Quick Sort recursive

template<typename T>
void quick_sort_recursive(std::vector<T>& a, int low, int high) {
    if (low >= high) return;
    int p = partition_vector(a, low, high);
    quick_sort_recursive(a, low, p - 1);
    quick_sort_recursive(a, p, high);
}

#endif