cmake_minimum_required(VERSION 3.20)

project(
    benchmarks
    LANGUAGES CXX
)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
    message(STATUS "Defaulting to Release CMAKE_BUILD_TYPE")
endif()

set(CMAKE_CXX_FLAGS "-Wunused -Wall -Wextra -Wshadow -Wconversion -Wpedantic -Werror")

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(
        FATAL_ERROR
            "Please don't do an in-source build. Create a separate build directory. Feel free to remove CMake files in this directory."
    )
endif()

include(cmake/UpdateSubmodules.cmake)

add_subdirectory(external)

add_subdirectory(pow2rd)
add_subdirectory(innerproduct)
add_subdirectory(search)
