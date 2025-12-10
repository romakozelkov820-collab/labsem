#ifndef TWO_PHASE_MERGE_SORT_H
#define TWO_PHASE_MERGE_SORT_H

#include <vector>
#include <string>

template<typename T>
std::vector<T> two_phase_merge_sort(const std::vector<T>& input, size_t run_size = 4);

// file-based API: input file with one value per line (text), output file same.
template<typename T>
void two_phase_merge_sort_file(const std::string& input_path, const std::string& output_path, size_t run_size = 4);

#include "../src/two_phase_merge_sort.cpp"
#endif