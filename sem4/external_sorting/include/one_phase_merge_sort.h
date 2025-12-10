#ifndef ONE_PHASE_MERGE_SORT_H
#define ONE_PHASE_MERGE_SORT_H

#include <vector>
#include <string>

template<typename T>
std::vector<T> one_phase_merge_sort(const std::vector<T>& input, size_t run_size = 4);

// file based
template<typename T>
void one_phase_merge_sort_file(const std::string& input_path, const std::string& output_path, size_t run_size = 4);

#include "../src/one_phase_merge_sort.cpp"
#endif