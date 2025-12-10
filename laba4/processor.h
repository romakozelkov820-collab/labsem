#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <vector>
#include <algorithm>

// ----------------- Shell Sort -----------------
template<typename T>
void shell_sort_vector(std::vector<T>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            T tmp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > tmp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = tmp;
        }
    }
}

// ----------------- Partition (Quick Sort) -----------------
template<typename T>
int partition_vector(std::vector<T>& a, int low, int high) {
    T pivot = a[(low + high) / 2];
    int l = low, r = high;

    while (l <= r) {
        while (a[l] < pivot) l++;
        while (a[r] > pivot) r--;
        if (l <= r) {
            std::swap(a[l], a[r]);
            l++;
            r--;
        }
    }
    return l;
}

// ----------------- Quick Sort -----------------
template<typename T>
void quick_sort_recursive(std::vector<T>& a, int low, int high) {
    if (low >= high) return;
    int p = partition_vector(a, low, high);
    quick_sort_recursive(a, low, p - 1);
    quick_sort_recursive(a, p, high);
}

#endif