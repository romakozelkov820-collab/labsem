#include "catch2/catch_amalgamated.hpp"
#include "../sorting/include/insertion_sort.h"

TEST_CASE("Insertion Sort - Basic functionality") {
    std::vector<int> arr = {3, 19, 10, 1, 15, 4, 11, 20};
    std::vector<int> expected = {1, 3, 4, 10, 11, 15, 19, 20};
    
    insertionSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Insertion Sort - Empty array") {
    std::vector<int> arr = {};
    std::vector<int> expected = {};
    
    insertionSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Insertion Sort - Single element") {
    std::vector<int> arr = {5};
    std::vector<int> expected = {5};
    
    insertionSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Insertion Sort - Already sorted") {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    
    insertionSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Insertion Sort - Reverse sorted") {
    std::vector<int> arr = {5, 4, 3, 2, 1};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    
    insertionSort(arr);
    REQUIRE(arr == expected);
}
