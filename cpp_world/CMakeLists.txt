cmake_minimum_required(VERSION 3.8)

project("cpp_world")

set(CMAKE_CXX_STANDARD 17)

set(GTest_DIR "~/vcpkg/packages/gtest_x64-linux/share/GTest/")

set(mkz84_commons_dir "${CMAKE_CURRENT_SOURCE_DIR}/../_mzk84_commons")

add_executable("cpp_world"
"${mkz84_commons_dir}/mzk84_commons.h"
"src/_main.cpp"
"src/_std_includes.h"
"src/BinarySearch.h"
"src/BinarySearch.cpp"
"src/BinarySearchTest.h"
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
"src/MyBinarySearchTree.h"
"src/MyBinarySearchTree.cpp"
"src/MyBinarySearchTreeTest.h"
"src/MyList.h"
"src/MyList.cpp"
"src/MyListTest.h"
"src/PatternExpansion.h"
"src/PatternExpansion.cpp"
"src/PatternExpansionTest.h"
"src/RecentItemsCache.h"
"src/RecentItemsCache.cpp"
"src/RecentItemsCacheTest.h"
"src/VisitingTree.h"
"src/VisitingTreeTest.h" "src/MyGraphStruct.h" "src/MyGraphStruct.cpp" "src/MyGraphStructTest.h")

find_package(GTest CONFIG REQUIRED)

enable_testing()

target_include_directories("cpp_world" PRIVATE "${mkz84_commons_dir}")

target_link_libraries("cpp_world" PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)

add_test(UnitTests cpp_world COMMAND cpp_world)