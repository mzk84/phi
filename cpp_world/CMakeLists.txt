cmake_minimum_required(VERSION 3.8)

project("cpp_world")

set(CMAKE_CXX_STANDARD 17)

add_executable("cpp_world"
"${CMAKE_CURRENT_SOURCE_DIR}/../_mzk84_commons/mzk84_commons.h"
"src/_main.cpp"
"src/_std_includes.h"
"src/CandyCrush1D.h"
"src/CandyCrush1D.cpp"
"src/CandyCrush1DTest.h"
"src/LargeFileSorting.h"
"src/LargeFileSorting.cpp"
"src/LargeFileSortingTest.h"
"src/ListElem.h"
"src/ListElemImpl.h"
"src/ListElemImpl.cpp"
"src/ListFunctions.h"
"src/ListFunctions.cpp"
"src/ListTestSuite.h"
"src/MaxNumOfUniqueChars.h"
"src/MaxNumOfUniqueChars.cpp"
"src/MaxNumOfUniqueCharsTest.h"
"src/RecentItemsCache.h"
"src/RecentItemsCache.cpp"
"src/RecentItemsCacheTest.h"
"src/VisitingTree.h"
"src/VisitingTreeTest.h")

find_package(GTest CONFIG REQUIRED)

target_include_directories("cpp_world" PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../_mzk84_commons")

target_link_libraries("cpp_world" PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
