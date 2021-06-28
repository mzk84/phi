#pragma once
#include "PatternExpansion.h"

#include "gtest/gtest.h"

TEST(PatternExpansionTest, Test1) {
    std::string input = "110?1?";
    std::vector<std::string> output;
    expandPattern(output, input, 0);
    ASSERT_EQ(4, output.size());
    std::cout << "Input: " << input << "\n";
    std::cout << "Output: " << "\n";
    for (const auto& o : output) {
        std::cout << o << "\n";
    }
}

