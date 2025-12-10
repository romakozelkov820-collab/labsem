#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../sorting/include/binary_insertion_sort.h"
#include <algorithm>

TEST_CASE("Binary: empty")
{
    std::vector<int> v;
    binary_insertion_sort(v);
    REQUIRE(v.empty());
}

TEST_CASE("Binary: one element")
{
    std::vector<int> v = {42};
    binary_insertion_sort(v);
    REQUIRE(v[0] == 42);
}

TEST_CASE("Binary: variant 7")
{
    std::vector<int> v = {3,19,10,1,15,4,11,20};
    std::vector<int> sorted = v;
    std::sort(sorted.begin(), sorted.end());

    binary_insertion_sort(v);

    REQUIRE(v == sorted);
}