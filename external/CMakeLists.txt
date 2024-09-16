set(BENCHMARK_ENABLE_GTEST_TESTS OFF)
message(STATUS "Building tests of Google Benchmark is disabled")

set(BENCHMARK_ENABLE_INSTALL OFF)
message(STATUS "Installation of Google Benchmark is disabled")

add_subdirectory(benchmark)
