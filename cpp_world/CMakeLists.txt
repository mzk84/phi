cmake_minimum_required(VERSION 3.8)

project("cpp_world")

set(CMAKE_CXX_STANDARD 17)

add_executable("cpp_world"
"src/_includes.h"
"src/_main.cpp"
"src/_mzk84_utils.h"
"src/CandyCrush1D.h"
"src/CandyCrush1D.cpp"
"src/CandyCrush1DTest.h"
"src/MaxNumOfUniqueChars.h"
"src/MaxNumOfUniqueChars.cpp"
"src/MaxNumOfUniqueCharsTest.h"
"src/RecentItemsCache.h"
"src/RecentItemsCache.cpp"
"src/RecentItemsCacheTest.h"
"src/VisitingTree.h"
"src/VisitingTreeTest.h")
