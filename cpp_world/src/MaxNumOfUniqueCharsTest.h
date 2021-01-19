#pragma once
#include "MaxNumOfUniqueChars.h"

#include "gtest/gtest.h"

TEST(MaxNumOfUniqueCharsTest, Test1) {
    std::string input = "abcdefgh";
    std::string expected = "0";
    ASSERT_EQ(expected, maxNumOfUniqueChars((input)));
}

TEST(MaxNumOfUniqueCharsTest, Test2) {
    std::string input = "abcffghijjcd";
    std::string expected = "5";
    ASSERT_EQ(expected, maxNumOfUniqueChars((input)));
}

TEST(MaxNumOfUniqueCharsTest, Test3) {
    std::string input;
    std::string expected = "0";
    ASSERT_EQ(expected, maxNumOfUniqueChars((input)));
}

