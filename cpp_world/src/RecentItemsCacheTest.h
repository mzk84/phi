#pragma once
#include "RecentItemsCache.h"

#include "gtest/gtest.h"

TEST(RecentItemsCacheTest, Test1) {

    RecentItemsCache cache(5);

    cache.addItem("string 1");
    cache.addItem("string 2");
    cache.addItem("string 3");

    auto storedCache = cache.getItems();
    auto iter = storedCache.begin();

    ASSERT_EQ(3, cache.getItems().size());
    ASSERT_EQ("string 3", (*iter++)->getValue());
    ASSERT_EQ("string 2", (*iter++)->getValue());
    ASSERT_EQ("string 1", (*iter++)->getValue());

    cache.addItem("string 2");

    storedCache = cache.getItems();
    iter = storedCache.begin();

    ASSERT_EQ(3, cache.getItems().size());
    ASSERT_EQ("string 2", (*iter++)->getValue());
    ASSERT_EQ("string 3", (*iter++)->getValue());
    ASSERT_EQ("string 1", (*iter++)->getValue());

    cache.addItem("string 4");
    cache.addItem("string 5");
    cache.addItem("string 6");

    storedCache = cache.getItems();
    iter = storedCache.begin();

    ASSERT_EQ(5, cache.getItems().size());
    ASSERT_EQ("string 6", (*iter++)->getValue());
    ASSERT_EQ("string 5", (*iter++)->getValue());
    ASSERT_EQ("string 4", (*iter++)->getValue());
    ASSERT_EQ("string 2", (*iter++)->getValue());
    ASSERT_EQ("string 3", (*iter++)->getValue());

    cache.addItem("string 1");
    cache.addItem("string 2");

    storedCache = cache.getItems();
    iter = storedCache.begin();

    ASSERT_EQ(5, cache.getItems().size());
    ASSERT_EQ("string 2", (*iter++)->getValue());
    ASSERT_EQ("string 1", (*iter++)->getValue());
    ASSERT_EQ("string 6", (*iter++)->getValue());
    ASSERT_EQ("string 5", (*iter++)->getValue());
    ASSERT_EQ("string 4", (*iter++)->getValue());
}
