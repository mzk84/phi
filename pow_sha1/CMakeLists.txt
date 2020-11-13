cmake_minimum_required(VERSION 3.8)

project("pow_sha1")

set(CMAKE_CXX_STANDARD 17)

add_executable("pow_sha1"
"../_mzk84_utils/_mzk84_utils.h"
"src/_includes.h"
"src/_main.cpp"
"src/PoW_SHA1.h"
"src/PoW_SHA1.cpp")

target_include_directories("pow_sha1" PRIVATE "../_mzk84_utils")

find_package(OpenSSL REQUIRED)
target_link_libraries("pow_sha1" PRIVATE OpenSSL::Crypto)
