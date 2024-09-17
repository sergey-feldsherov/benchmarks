#include <algorithm>
#include <random>
#include <vector>

#include <benchmark/benchmark.h>

#include "search.hpp"

constexpr int kRangeMin = 1;
constexpr int kRangeMax = 1<<15;

static void BM_search_linear(benchmark::State &state) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> uni(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    int d = (int)state.range(0);
    std::vector<int> numbers(d, 0);
    for (int i = 0; i < d; ++i) {
        numbers[i] = uni(mt);
    }
    int target = uni(mt);
    std::sort(numbers.begin(), numbers.end());
    for (auto _ : state) {
        int idx = search_linear(numbers, target);
        benchmark::DoNotOptimize(idx);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_search_linear)->Range(kRangeMin, kRangeMax)->Complexity(benchmark::oN);

static void BM_search_bin(benchmark::State &state) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> uni(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    int d = (int)state.range(0);
    std::vector<int> numbers(d, 0);
    for (int i = 0; i < d; ++i) {
        numbers[i] = uni(mt);
    }
    int target = uni(mt);
    std::sort(numbers.begin(), numbers.end());
    for (auto _ : state) {
        int idx = search_bin(numbers, target);
        benchmark::DoNotOptimize(idx);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_search_bin)->Range(kRangeMin, kRangeMax)->Complexity(benchmark::oLogN);

BENCHMARK_MAIN();
