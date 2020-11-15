cmake_minimum_required(VERSION 3.8)

project("cpp_web")

set(CMAKE_CXX_STANDARD 17)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Boost COMPONENTS system filesystem REQUIRED)
find_package(Threads)

include_directories(${Boost_INCLUDE_DIRS})

add_executable("cpp_web"
"src/_mzk84_utils.h"
"src/_std_includes.h"
"src/_main.cpp"
"src/crow_all.h")

target_link_libraries("cpp_web" ${Boost_LIBRARIES} Threads::Threads)
