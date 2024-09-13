#include <random>

#include <benchmark/benchmark.h>

#include "ipfun.h"

constexpr int d = 1024;

static void BM_ip_naive(benchmark::State &state) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float> uni(0, 1);
    float v[d], w[d];
    for (int i = 0; i < d; ++i) {
        v[i] = uni(mt);
        w[i] = uni(mt);
    }
    for (auto _ : state) {
        ip_naive(v, w, d);
    }
}
BENCHMARK(BM_ip_naive);

BENCHMARK_MAIN();
