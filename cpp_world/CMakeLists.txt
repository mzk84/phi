cmake_minimum_required(VERSION 3.8)

project("cpp_world")

set(CMAKE_CXX_STANDARD 17)

set(GTest_DIR "~/vcpkg/installed/x64-linux/share/GTest")

set(mkz84_commons_dir "${CMAKE_CURRENT_SOURCE_DIR}/../_mzk84_commons")

find_package(GTest CONFIG REQUIRED)

enable_testing()

add_executable("cpp_world"
"${mkz84_commons_dir}/mzk84_commons.h"
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
"src/ListFunctionsTest.h"
"src/MaxNumOfUniqueChars.h"
"src/MaxNumOfUniqueChars.cpp"
"src/MaxNumOfUniqueCharsTest.h"
"src/RecentItemsCache.h"
"src/RecentItemsCache.cpp"
"src/RecentItemsCacheTest.h"
"src/VisitingTree.h"
"src/VisitingTreeTest.h")

target_include_directories("cpp_world" PRIVATE "${mkz84_commons_dir}")

target_link_libraries("cpp_world" PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)

add_test(UnitTests cpp_world COMMAND cpp_world)