#include "catch2/catch_amalgamated.hpp"
#include "../sorting/include/optimized_bubble_sort.h"

TEST_CASE("Optimized Bubble Sort - Basic functionality") {
    std::vector<int> arr = {3, 19, 10, 1, 15, 4, 11, 20};
    std::vector<int> expected = {1, 3, 4, 10, 11, 15, 19, 20};
    
    optimizedBubbleSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Optimized Bubble Sort - Empty array") {
    std::vector<int> arr = {};
    std::vector<int> expected = {};
    
    optimizedBubbleSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Optimized Bubble Sort - Single element") {
    std::vector<int> arr = {5};
    std::vector<int> expected = {5};
    
    optimizedBubbleSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Optimized Bubble Sort - Already sorted") {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    
    optimizedBubbleSort(arr);
    REQUIRE(arr == expected);
}
