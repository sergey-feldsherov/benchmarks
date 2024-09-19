#include <algorithm>
#include <random>

#include <benchmark/benchmark.h>

#include "search.hpp"

constexpr int kRangeMin = 1;
constexpr int kRangeMax = 1<<16;

static void BM_search_linear(benchmark::State &state) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> uni(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    unsigned int d = (unsigned int)state.range(0);
    int *numbers = new int[d];
    for (unsigned int i = 0; i < d; ++i) {
        numbers[i] = uni(mt);
    }
    int target = uni(mt);
    std::sort(numbers, numbers + d);
    for (auto _ : state) {
        unsigned int idx = search_linear(numbers, d, target);
        benchmark::DoNotOptimize(idx);
    }
    state.SetComplexityN(state.range(0));
    delete[] numbers;
}
BENCHMARK(BM_search_linear)->Range(kRangeMin, kRangeMax)->Complexity(benchmark::oN);

static void BM_search_bin(benchmark::State &state) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> uni(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    unsigned int d = (unsigned int)state.range(0);
    int *numbers = new int[d];
    for (unsigned int i = 0; i < d; ++i) {
        numbers[i] = uni(mt);
    }
    int target = uni(mt);
    std::sort(numbers, numbers + d);
    for (auto _ : state) {
        unsigned int idx = search_bin(numbers, d, target);
        benchmark::DoNotOptimize(idx);
    }
    state.SetComplexityN(state.range(0));
    delete[] numbers;
}
BENCHMARK(BM_search_bin)->Range(kRangeMin, kRangeMax)->Complexity(benchmark::oLogN);

BENCHMARK_MAIN();
