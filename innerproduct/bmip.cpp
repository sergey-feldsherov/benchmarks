#include <random>

#include <benchmark/benchmark.h>

#include "ip.h"

constexpr int kRangeMin = 16;
constexpr int kRangeMax = 1<<15;
constexpr float kMinWarmUpTime = 0.2f;

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_real_distribution<float> uni(0, 1);

void fillrandvec(float *vec, unsigned int d) {
    for (unsigned int i = 0; i < d; ++i) {
         vec[i] = uni(mt);
    }
}

static void BM_ip_naive(benchmark::State &state) {
    unsigned int d = (unsigned int)state.range(0);
    float *v = new float[d], *w = new float[d];
    for (auto _ : state) {
        state.PauseTiming();
        fillrandvec(v, d);
        fillrandvec(w, d);
        state.ResumeTiming();
        float d_ip = ip_naive(v, w, d);
        benchmark::DoNotOptimize(d_ip);
    }
    state.SetComplexityN(state.range(0));
    delete[] v;
    delete[] w;
}
BENCHMARK(BM_ip_naive)->Range(kRangeMin, kRangeMax)->Complexity(benchmark::oN)->MinWarmUpTime(kMinWarmUpTime);

#if defined(__AVX512F__)
static void BM_ip_avx512f(benchmark::State &state) {
    unsigned int d = (unsigned int)state.range(0);
    float *v = new float[d], *w = new float[d];
    for (auto _ : state) {
        state.PauseTiming();
        fillrandvec(v, d);
        fillrandvec(w, d);
        state.ResumeTiming();
        float d_ip = ip_avx512f(v, w, d);
        benchmark::DoNotOptimize(d_ip);
    }
    state.SetComplexityN(state.range(0));
    delete[] v;
    delete[] w;
}
BENCHMARK(BM_ip_avx512f)->Range(kRangeMin, kRangeMax)->Complexity(benchmark::oN)->MinWarmUpTime(kMinWarmUpTime);
#else
#pragma message("AVX512F not available, not building related benchmarks")
#endif  // __AVX512F__

#if defined(__ARM_NEON)
static void BM_ip_arm_neon(benchmark::State &state) {
    unsigned int d = (unsigned int)state.range(0);
    float *v = new float[d], *w = new float[d];
    for (auto _ : state) {
        state.PauseTiming();
        fillrandvec(v, d);
        fillrandvec(w, d);
        state.ResumeTiming();
        float d_ip = ip_arm_neon(v, w, d);
        benchmark::DoNotOptimize(d_ip);
    }
    state.SetComplexityN(state.range(0));
    delete[] v;
    delete[] w;
}
BENCHMARK(BM_ip_arm_neon)->Range(kRangeMin, kRangeMax)->Complexity(benchmark::oN)->MinWarmUpTime(kMinWarmUpTime);
#else
#pragma message("ARM Neon not available, not building related benchmarks")
#endif  // __ARM_NEON

static void BM_ip_blas(benchmark::State &state) {
    unsigned int d = (unsigned int)state.range(0);
    float *v = new float[d], *w = new float[d];
    for (auto _ : state) {
        state.PauseTiming();
        fillrandvec(v, d);
        fillrandvec(w, d);
        state.ResumeTiming();
        float d_ip = ip_blas(v, w, d);
        benchmark::DoNotOptimize(d_ip);
    }
    state.SetComplexityN(state.range(0));
    delete[] v;
    delete[] w;
}
BENCHMARK(BM_ip_blas)->Range(kRangeMin, kRangeMax)->Complexity(benchmark::oN)->MinWarmUpTime(kMinWarmUpTime);

BENCHMARK_MAIN();
