#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../external_sorting/include/two_phase_merge_sort.h"
#include <algorithm>

TEST_CASE("Two-phase - empty") {
    std::vector<int> v;
    auto r = two_phase_merge_sort(v, 3);
    REQUIRE(r.empty());
}

TEST_CASE("Two-phase - single") {
    std::vector<int> v = {42};
    auto r = two_phase_merge_sort(v, 3);
    REQUIRE(r.size() == 1);
    REQUIRE(r[0] == 42);
}

TEST_CASE("Two-phase - variant 7") {
    std::vector<int> v = {3,19,10,1,15,4,11,20};
    auto expected = v; std::sort(expected.begin(), expected.end());
    auto r = two_phase_merge_sort(v, 3);
    REQUIRE(r == expected);
}