#ifndef NATURAL_MERGE_SORT_H
#define NATURAL_MERGE_SORT_H

#include <vector>
#include <string>

template<typename T>
std::vector<T> natural_merge_sort(const std::vector<T>& input);

// file-based
template<typename T>
void natural_merge_sort_file(const std::string& input_path, const std::string& output_path);

#include "../src/natural_merge_sort.cpp"
#endif