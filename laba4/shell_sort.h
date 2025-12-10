#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include <vector>

// Shell Sort

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

#endif