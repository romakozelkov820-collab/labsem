#ifndef SHELL_SORT_CPP
#define SHELL_SORT_CPP

#include <vector>

template<typename T>
void shell_sort(std::vector<T>& arr)
{
    int n = arr.size();
    // Шаги Шелла — классическая последовательность n/2, n/4...
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            T temp = arr[i];
            int j = i;

            // вставка с шагом
            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

#endif