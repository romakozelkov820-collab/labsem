#include "catch2/catch_amalgamated.hpp"
#include "../sorting/include/selection_sort.h"

TEST_CASE("Selection Sort - Basic functionality") {
    std::vector<int> arr = {3, 19, 10, 1, 15, 4, 11, 20};
    std::vector<int> expected = {1, 3, 4, 10, 11, 15, 19, 20};
    
    selectionSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Selection Sort - Empty array") {
    std::vector<int> arr = {};
    std::vector<int> expected = {};
    
    selectionSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Selection Sort - Single element") {
    std::vector<int> arr = {5};
    std::vector<int> expected = {5};
    
    selectionSort(arr);
    REQUIRE(arr == expected);
}
