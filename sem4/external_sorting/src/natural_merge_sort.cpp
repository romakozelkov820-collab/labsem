#ifndef NATURAL_MERGE_SORT_CPP
#define NATURAL_MERGE_SORT_CPP

#include <fstream>
#include <filesystem>
#include <algorithm>

// natural merge: find natural increasing runs in input, write each run into temp file, then k-way merge runs (similar to one-phase)
template<typename T>
static std::vector<std::string> make_natural_runs(const std::vector<T>& v) {
    std::vector<std::string> files;
    if (v.empty()) return files;
    int idx = 0;
    size_t pos = 0, n = v.size();
    while (pos < n) {
        size_t j = pos + 1;
        while (j < n && v[j-1] <= v[j]) ++j;
        std::vector<T> run(v.begin()+pos, v.begin()+j);
        std::string fname = "tmp_natural_" + std::to_string(idx++) + ".bin";
        std::ofstream ofs(fname, std::ios::binary);
        size_t sz = run.size();
        ofs.write(reinterpret_cast<const char*>(&sz), sizeof(sz));
        if (sz) ofs.write(reinterpret_cast<const char*>(run.data()), sizeof(T)*sz);
        files.push_back(fname);
        pos = j;
    }
    return files;
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
std::vector<T> natural_merge_sort(const std::vector<T>& input) {
    if (input.empty()) return {};
    auto run_files = make_natural_runs<T>(input);
    // k-way merge similar to one-phase
    struct Node { T val; size_t run_idx; size_t pos; };
    struct Cmp { bool operator()(const Node& a, const Node& b) const { return a.val > b.val; } };
    std::priority_queue<Node, std::vector<Node>, Cmp> heap;

    std::vector<std::vector<T>> buffers;
    for (auto &f : run_files) buffers.push_back(read_bin_small<T>(f));
    for (size_t i=0;i<buffers.size();++i)
        if (!buffers[i].empty()) heap.push(Node{buffers[i][0], i, 0});

    std::vector<T> out; out.reserve(input.size());
    while (!heap.empty()) {
        Node cur = heap.top(); heap.pop();
        out.push_back(cur.val);
        size_t r = cur.run_idx;
        size_t p = cur.pos + 1;
        if (p < buffers[r].size()) heap.push(Node{buffers[r][p], r, p});
    }
    for (auto &f: run_files) std::filesystem::remove(f);
    return out;
}

template<typename T>
void natural_merge_sort_file(const std::string& input_path, const std::string& output_path) {
    std::ifstream ifs(input_path);
    std::vector<T> v;
    T x;
    while (ifs >> x) v.push_back(x);
    auto res = natural_merge_sort<T>(v);
    std::ofstream ofs(output_path);
    for (auto &val : res) ofs << val << '\n';
}

#endif