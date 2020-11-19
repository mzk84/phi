cmake_minimum_required(VERSION 3.8)

project("cpp_web")

set(CMAKE_CXX_STANDARD 17)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)
find_package(Boost COMPONENTS system filesystem REQUIRED)
find_package(libmongocxx REQUIRED)

add_executable("cpp_web"
"src/crow_all.h"
"src/_main.cpp")

target_include_directories("cpp_web" PRIVATE ${Boost_INCLUDE_DIRS} ${LIBMONGOCXX_INCLUDE_DIRS})

target_link_libraries("cpp_web" Threads::Threads ${Boost_LIBRARIES} ${LIBMONGOCXX_LIBRARIES})
