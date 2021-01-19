#pragma once
#include "CandyCrush1D.h"

#include "gtest/gtest.h"

TEST(CandyCrush1DTest, Test1) {
    std::string input = "abbcccbbbaaeefffre";
    std::string expected = "eere";
    ASSERT_EQ(expected, candyCrush1D((input)));
}

TEST(CandyCrush1DTest, Test2) {
    std::string input = "abbcaabadddaeeffft";
    std::string expected = "abbcaabaaeet";
    ASSERT_EQ(expected, candyCrush1D((input)));
}

TEST(CandyCrush1DTest, Test3) {
    std::string input = "abcdef";
    std::string expected = "abcdef";
    ASSERT_EQ(expected, candyCrush1D((input)));
}

TEST(CandyCrush1DTest, Test4) {
    std::string input = "abbaabgggffefee";
    std::string expected = "abbaabffefee";
    ASSERT_EQ(expected, candyCrush1D((input)));
}

TEST(CandyCrush1DTest, Test5) {
    std::string input;
    std::string expected;
    ASSERT_EQ(expected, candyCrush1D((input)));
}
