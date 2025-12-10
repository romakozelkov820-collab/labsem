#ifndef TWO_PHASE_MERGE_SORT_CPP
#define TWO_PHASE_MERGE_SORT_CPP

#include <fstream>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <queue>
#include <tuple>
#include <filesystem>

// Helper: write vector<T> to binary file
template<typename T>
static void write_bin(const std::string& fname, const std::vector<T>& v) {
    std::ofstream ofs(fname, std::ios::binary);
    size_t n = v.size();
    ofs.write(reinterpret_cast<const char*>(&n), sizeof(n));
    if (n) ofs.write(reinterpret_cast<const char*>(v.data()), sizeof(T) * n);
}

// Helper: read vector<T> from binary file
template<typename T>
static std::vector<T> read_bin(const std::string& fname) {
    std::ifstream ifs(fname, std::ios::binary);
    size_t n;
    ifs.read(reinterpret_cast<char*>(&n), sizeof(n));
    std::vector<T> v(n);
    if (n) ifs.read(reinterpret_cast<char*>(v.data()), sizeof(T) * n);
    return v;
}

// split input into runs (in-memory chunks) of size run_size, sort each run and write to temp file names returned
template<typename T>
static std::vector<std::string> make_initial_runs(const std::vector<T>& input, size_t run_size) {
    std::vector<std::string> run_files;
    size_t total = input.size();
    size_t pos = 0;
    int idx = 0;
    while (pos < total) {
        size_t sz = std::min(run_size, total - pos);
        std::vector<T> run(input.begin() + pos, input.begin() + pos + sz);
        std::sort(run.begin(), run.end());
        std::string fname = "tmp_run_" + std::to_string(idx++) + ".bin";
        write_bin(fname, run);
        run_files.push_back(fname);
        pos += sz;
    }
    return run_files;
}

// merge two binary run files into new file
template<typename T>
static std::string merge_two_runs(const std::string& f1, const std::string& f2, int out_idx) {
    auto v1 = read_bin<T>(f1);
    auto v2 = read_bin<T>(f2);
    std::vector<T> merged;
    merged.reserve(v1.size() + v2.size());
    size_t i=0,j=0;
    while (i<v1.size() && j<v2.size()) {
        if (v1[i] <= v2[j]) merged.push_back(v1[i++]);
        else merged.push_back(v2[j++]);
    }
    while (i<v1.size()) merged.push_back(v1[i++]);
    while (j<v2.size()) merged.push_back(v2[j++]);
    std::string out = "tmp_run_merged_" + std::to_string(out_idx) + ".bin";
    write_bin(out, merged);
    return out;
}

// Two-phase merge: repeatedly merge pairwise until single file
template<typename T>
std::vector<T> two_phase_merge_sort(const std::vector<T>& input, size_t run_size) {
    if (input.empty()) return {};
    auto runs = make_initial_runs<T>(input, run_size);
    // pairwise merge
    int pass = 0;
    while (runs.size() > 1) {
        std::vector<std::string> next;
        int idx = 0;
        for (size_t i = 0; i+1 < runs.size(); i += 2) {
            std::string merged = merge_two_runs<T>(runs[i], runs[i+1], (pass<<16) + idx);
            next.push_back(merged);
            // remove old files
            std::filesystem::remove(runs[i]);
            std::filesystem::remove(runs[i+1]);
            ++idx;
        }
        if (runs.size() % 2 == 1) {
            // carry last file
            next.push_back(runs.back());
        }
        runs.swap(next);
        ++pass;
    }
    // final result is in runs[0]
    auto result = read_bin<T>(runs[0]);
    std::filesystem::remove(runs[0]);
    return result;
}

// file-based: read all values from text file into vector<T>, run algorithm, write output to text file
template<typename T>
void two_phase_merge_sort_file(const std::string& input_path, const std::string& output_path, size_t run_size) {
    std::ifstream ifs(input_path);
    std::vector<T> v;
    T x;
    while (ifs >> x) v.push_back(x);
    auto res = two_phase_merge_sort<T>(v, run_size);
    std::ofstream ofs(output_path);
    for (auto &val : res) ofs << val << '\n';
}

#endif