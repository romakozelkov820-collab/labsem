#ifndef EXCHANGE_SORT_H
#define EXCHANGE_SORT_H

#include <vector>

template <typename T>
void exchangeSort(std::vector<T>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

#endif
