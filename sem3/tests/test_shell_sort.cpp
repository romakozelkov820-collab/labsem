#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../sorting/include/shell_sort.h"
#include <algorithm>

TEST_CASE("Shell: empty")
{
    std::vector<int> v;
    shell_sort(v);
    REQUIRE(v.empty());
}

TEST_CASE("Shell: one element")
{
    std::vector<int> v = {42};
    shell_sort(v);
    REQUIRE(v[0] == 42);
}

TEST_CASE("Shell: variant 7")
{
    std::vector<int> v = {3,19,10,1,15,4,11,20};  // вариант 7
    std::vector<int> sorted = v;
    std::sort(sorted.begin(), sorted.end());

    shell_sort(v);

    REQUIRE(v == sorted);
}

TEST_CASE("Shell: reverse")
{
    std::vector<int> v = {9,8,7,6,5,4,3,2,1};
    shell_sort(v);
    REQUIRE(std::is_sorted(v.begin(), v.end()));
}