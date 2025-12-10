#ifndef QUICK_SORT_CPP
#define QUICK_SORT_CPP

#include <vector>
#include <algorithm>

template<typename T>
int partition(std::vector<T>& arr, int low, int high)
{
    T pivot = arr[(low + high) / 2];
    int left = low;
    int right = high;

    while (left <= right)
    {
        while (arr[left] < pivot) left++;
        while (arr[right] > pivot) right--;

        if (left <= right)
        {
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    return left;
}

template<typename T>
void quick_sort_recursive(std::vector<T>& arr, int low, int high)
{
    if (low >= high) return;

    int index = partition(arr, low, high);
    quick_sort_recursive(arr, low, index - 1);
    quick_sort_recursive(arr, index, high);
}

template<typename T>
void quick_sort(std::vector<T>& arr)
{
    if (!arr.empty())
        quick_sort_recursive(arr, 0, arr.size() - 1);
}

#endif