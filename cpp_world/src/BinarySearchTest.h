#pragma once
#include "BinarySearch.h"

#include "gtest/gtest.h"

TEST(BinarySearchTest, Test1) {
    std::vector<int> collection = { 2, 3, 4, 7, 8, 11, 14, 18 };
    std::optional<size_t> res = binarySearch(collection, 4);
    ASSERT_EQ(true, res.has_value());
    ASSERT_EQ(2, *res);
}

TEST(BinarySearchTest, Test2) {
    std::vector<int> collection = { 2, 3, 4, 7, 8, 11, 14, 18 };
    std::optional<size_t> res = binarySearch(collection, 5);
    ASSERT_EQ(false, res.has_value());
}

TEST(BinarySearchTest, Test3) {
    std::vector<int> collection = { 2, 3, 4, 7, 8, 11, 14, 18 };
    std::optional<size_t> res = binarySearch(collection, 14);
    ASSERT_EQ(true, res.has_value());
    ASSERT_EQ(6, *res);
}
