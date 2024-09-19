#include <benchmark/benchmark.h>

#include "pow2rd.h"

uint32_t shortnum = 1940712347;
uint32_t longnum = 2340712347;  // runs for eternity in Debug builds

uint32_t num = shortnum;

static void BM_pow2rd_naive(benchmark::State &state) {
    for (auto _ : state) {
        uint32_t result = pow2rd_naive((uint32_t)state.range(0));
        benchmark::DoNotOptimize(result);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_pow2rd_naive)->Range(7, shortnum)->Complexity(benchmark::oLogN);

static void BM_pow2rd_builtin_clz(benchmark::State &state) {
    for (auto _ : state) {
        uint32_t result = pow2rd_builtin_clz((uint32_t)state.range(0));
        benchmark::DoNotOptimize(result);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_pow2rd_builtin_clz)->Range(7, shortnum)->Complexity(benchmark::o1);

BENCHMARK_MAIN();
