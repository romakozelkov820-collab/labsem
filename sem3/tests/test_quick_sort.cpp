#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../sorting/include/quick_sort.h"
#include <algorithm>

TEST_CASE("Quick: empty")
{
    std::vector<int> v;
    quick_sort(v);
    REQUIRE(v.empty());
}

TEST_CASE("Quick: sorted")
{
    std::vector<int> v = {1,2,3,4,5};
    quick_sort(v);
    REQUIRE(std::is_sorted(v.begin(), v.end()));
}

TEST_CASE("Quick: variant 7")
{
    std::vector<int> v = {3,19,10,1,15,4,11,20}; // вариант 7
    std::vector<int> sorted = v;
    std::sort(sorted.begin(), sorted.end());

    quick_sort(v);

    REQUIRE(v == sorted);
}

TEST_CASE("Quick: duplicates")
{
    std::vector<int> v = {5,1,5,3,5,2,1};
    quick_sort(v);
    REQUIRE(std::is_sorted(v.begin(), v.end()));
}