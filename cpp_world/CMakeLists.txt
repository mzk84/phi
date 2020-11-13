cmake_minimum_required(VERSION 3.8)

project("cpp_world")

set(CMAKE_CXX_STANDARD 17)

add_executable("cpp_world"
"../_mzk84_utils/_mzk84_utils.h"
"../_mzk84_utils/_std_includes.h"
"src/_main.cpp"
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

target_include_directories("cpp_world" PRIVATE "../_mzk84_utils")
