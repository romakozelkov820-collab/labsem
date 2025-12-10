#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../external_sorting/include/natural_merge_sort.h"
#include <algorithm>

TEST_CASE("Natural - empty") {
    std::vector<int> v;
    auto r = natural_merge_sort(v);
    REQUIRE(r.empty());
}

TEST_CASE("Natural - one element") {
    std::vector<int> v = {7};
    auto r = natural_merge_sort(v);
    REQUIRE(r.size() == 1 && r[0] == 7);
}

TEST_CASE("Natural - variant 7") {
    std::vector<int> v = {3,19,10,1,15,4,11,20};
    auto expected = v; std::sort(expected.begin(), expected.end());
    auto r = natural_merge_sort(v);
    REQUIRE(r == expected);
}