#include <benchmark/benchmark.h>

#include "pow2rd.h"

static void BM_pow2rd_naive(benchmark::State &state) {
    int a = 42;
    for (auto _ : state) {
        pow2rd_naive(a);
    }
}
BENCHMARK(BM_pow2rd_naive);

static void BM_pow2rd_builtin_clz(benchmark::State &state) {
    int a = 42;
    for (auto _ : state) {
        pow2rd_builtin_clz(a);
    }
}
BENCHMARK(BM_pow2rd_builtin_clz);

BENCHMARK_MAIN();
