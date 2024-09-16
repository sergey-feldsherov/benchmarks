#include <random>

#include <benchmark/benchmark.h>

#include "ipfun.h"

static void BM_ip_naive(benchmark::State &state) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float> uni(0, 1);
    int d = (int)state.range(0);
    float *v, *w;
    v = new float[d];
    w = new float[d];
    for (int i = 0; i < d; ++i) {
        v[i] = uni(mt);
        w[i] = uni(mt);
    }
    for (auto _ : state) {
        float d_ip = ip_naive(v, w, d);
        benchmark::DoNotOptimize(d_ip);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_ip_naive)->Range(64, 4096*8)->Complexity(benchmark::oN);

BENCHMARK_MAIN();
