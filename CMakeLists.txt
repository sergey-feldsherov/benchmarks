cmake_minimum_required(VERSION 3.20)

project(
    benchmarks
    LANGUAGES CXX
)

set(CMAKE_CXX_FLAGS "-Wunused -Wall -Wextra -Wshadow -Wconversion -Wpedantic -Werror")

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(
        FATAL_ERROR
            "Please don't do an in-source build. Create a separate build directory. Feel free to remove CMake files in this directory."
    )
endif()

include(cmake/UpdateSubmodules.cmake)

set(BENCHMARK_ENABLE_GTEST_TESTS OFF)
message(
    STATUS
        "Building tests of Google Benchmark is disabled"
)
add_subdirectory(external)

add_subdirectory(pow2rd)
add_subdirectory(innerproduct)
