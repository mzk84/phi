cmake_minimum_required(VERSION 3.8)

project("pow_sha1")

set(CMAKE_CXX_STANDARD 17)

set(mkz84_commons_dir "${CMAKE_CURRENT_SOURCE_DIR}/../_mzk84_commons")

find_package(OpenSSL REQUIRED)

add_executable("pow_sha1"
"${mkz84_commons_dir}/mzk84_commons.h"
"src/_includes.h"
"src/_main.cpp"
"src/PoW_SHA1.h"
"src/PoW_SHA1.cpp")

target_include_directories("pow_sha1" PRIVATE "${mkz84_commons_dir}")


target_link_libraries("pow_sha1" PRIVATE OpenSSL::Crypto)
