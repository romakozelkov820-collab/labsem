#include "catch2/catch_amalgamated.hpp"
#include "../sorting/include/bubble_sort.h"

TEST_CASE("Bubble Sort - Basic functionality") {
    std::vector<int> arr = {3, 19, 10, 1, 15, 4, 11, 20};
    std::vector<int> expected = {1, 3, 4, 10, 11, 15, 19, 20};
    
    bubbleSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Bubble Sort - Empty array") {
    std::vector<int> arr = {};
    std::vector<int> expected = {};
    
    bubbleSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Bubble Sort - Single element") {
    std::vector<int> arr = {5};
    std::vector<int> expected = {5};
    
    bubbleSort(arr);
    REQUIRE(arr == expected);
}
