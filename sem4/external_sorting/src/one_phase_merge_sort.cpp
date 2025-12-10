#ifndef ONE_PHASE_MERGE_SORT_CPP
#define ONE_PHASE_MERGE_SORT_CPP

#include <algorithm>
#include <filesystem>
#include <fstream>

// One-phase merge: produce runs and merge them in single k-way merge using a min-heap.
// For simplicity write runs to files as in two-phase, but perform a single k-way merge of all runs.

template<typename T>
static std::string write_run_and_get_file(const std::vector<T>& run, int idx) {
    std::string fname = "tmp_run_one_" + std::to_string(idx) + ".bin";
    std::ofstream ofs(fname, std::ios::binary);
    size_t n = run.size();
    ofs.write(reinterpret_cast<const char*>(&n), sizeof(n));
    if (n) ofs.write(reinterpret_cast<const char*>(run.data()), sizeof(T)*n);
    return fname;
}

template<typename T>
static std::vector<T> read_bin_small(const std::string& fname) {
    std::ifstream ifs(fname, std::ios::binary);
    size_t n; ifs.read(reinterpret_cast<char*>(&n), sizeof(n));
    std::vector<T> v(n);
    if (n) ifs.read(reinterpret_cast<char*>(v.data()), sizeof(T)*n);
    return v;
}

template<typename T>
std::vector<T> one_phase_merge_sort(const std::vector<T>& input, size_t run_size) {
    if (input.empty()) return {};
    // create runs
    std::vector<std::string> run_files;
    int idx = 0;
    for (size_t pos=0; pos<input.size(); pos += run_size) {
        size_t sz = std::min(run_size, input.size()-pos);
        std::vector<T> run(input.begin()+pos, input.begin()+pos+sz);
        std::sort(run.begin(), run.end());
        run_files.push_back(write_run_and_get_file<T>(run, idx++));
    }

    // k-way merge all runs using heap
    struct Node { T val; size_t run_idx; size_t pos; };
    struct Cmp { bool operator()(const Node& a, const Node& b) const { return a.val > b.val; } };
    std::priority_queue<Node, std::vector<Node>, Cmp> heap;

    // load all runs into memory buffers (since runs small; for true external we'd stream)
    std::vector<std::vector<T>> buffers;
    buffers.reserve(run_files.size());
    for (auto &f : run_files) buffers.push_back(read_bin_small<T>(f));

    for (size_t i=0;i<buffers.size();++i) {
        if (!buffers[i].empty()) heap.push(Node{buffers[i][0], i, 0});
    }

    std::vector<T> out;
    out.reserve(input.size());
    while (!heap.empty()) {
        Node cur = heap.top(); heap.pop();
        out.push_back(cur.val);
        size_t r = cur.run_idx;
        size_t p = cur.pos + 1;
        if (p < buffers[r].size()) heap.push(Node{buffers[r][p], r, p});
    }

    // cleanup files
    for (auto &f: run_files) std::filesystem::remove(f);
    return out;
}

template<typename T>
void one_phase_merge_sort_file(const std::string& input_path, const std::string& output_path, size_t run_size) {
    std::ifstream ifs(input_path);
    std::vector<T> v;
    T x;
    while (ifs >> x) v.push_back(x);
    auto res = one_phase_merge_sort<T>(v, run_size);
    std::ofstream ofs(output_path);
    for (auto &val : res) ofs << val << '\n';
}

#endif