#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../sorting/include/shaker_sort.h"
#include <algorithm>

TEST_CASE("Shaker: empty")
{
    std::vector<int> v;
    shaker_sort(v);
    REQUIRE(v.empty());
}

TEST_CASE("Shaker: sorted")
{
    std::vector<int> v = {1,2,3,4,5};
    shaker_sort(v);
    REQUIRE(std::is_sorted(v.begin(), v.end()));
}

TEST_CASE("Shaker: variant 7")
{
    std::vector<int> v = {3,19,10,1,15,4,11,20};
    std::vector<int> sorted = v;
    std::sort(sorted.begin(), sorted.end());

    shaker_sort(v);

    REQUIRE(v == sorted);
}