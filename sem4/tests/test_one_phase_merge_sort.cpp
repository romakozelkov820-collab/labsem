#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../external_sorting/include/one_phase_merge_sort.h"
#include <algorithm>

TEST_CASE("One-phase - empty") {
    std::vector<int> v;
    auto r = one_phase_merge_sort(v, 3);
    REQUIRE(r.empty());
}

TEST_CASE("One-phase - sorted") {
    std::vector<int> v = {1,2,3,4,5};
    auto r = one_phase_merge_sort(v, 2);
    REQUIRE(r == v);
}

TEST_CASE("One-phase - variant 7") {
    std::vector<int> v = {3,19,10,1,15,4,11,20};
    auto expected = v; std::sort(expected.begin(), expected.end());
    auto r = one_phase_merge_sort(v, 3);
    REQUIRE(r == expected);
}