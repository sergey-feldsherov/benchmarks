#include <random>

#include <benchmark/benchmark.h>

#include "ip.h"

constexpr int kRangeMin = 8;
constexpr int kRangeMaxSingleFill = 1<<13;
constexpr int kRangeMaxRefill = 1<<15;

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_real_distribution<float> uni(0, 1);

void fillrandvec(float *vec, int d) {
    for (int i = 0; i < d; ++i) {
         vec[i] = uni(mt);
    }
}

static void DISABLED_BM_refill_ip_naive(benchmark::State &state) {
    int d = (int)state.range(0);
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
BENCHMARK(DISABLED_BM_refill_ip_naive)->Range(kRangeMin, kRangeMaxRefill)->Complexity(benchmark::oN);

static void BM_single_fill_ip_naive(benchmark::State &state) {
    int d = (int)state.range(0);
    float *v = new float[d], *w = new float[d];
    fillrandvec(v, d);
    fillrandvec(w, d);
    for (auto _ : state) {
        float d_ip = ip_naive(v, w, d);
        benchmark::DoNotOptimize(d_ip);
    }
    state.SetComplexityN(state.range(0));
    delete[] v;
    delete[] w;
}
BENCHMARK(BM_single_fill_ip_naive)->Range(kRangeMin, kRangeMaxSingleFill)->Complexity(benchmark::oN);

#if defined(__AVX512F__)
static void DISABLED_BM_refill_ip_avx512f(benchmark::State &state) {
    int d = (int)state.range(0);
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
BENCHMARK(DISABLED_BM_refill_ip_avx512f)->Range(kRangeMin, kRangeMaxRefill)->Complexity(benchmark::oN);

static void BM_single_fill_ip_avx512f(benchmark::State &state) {
    int d = (int)state.range(0);
    float *v = new float[d], *w = new float[d];
    fillrandvec(v, d);
    fillrandvec(w, d);
    for (auto _ : state) {
        float d_ip = ip_avx512f(v, w, d);
        benchmark::DoNotOptimize(d_ip);
    }
    state.SetComplexityN(state.range(0));
    delete[] v;
    delete[] w;
}
BENCHMARK(BM_single_fill_ip_avx512f)->Range(kRangeMin, kRangeMaxSingleFill)->Complexity(benchmark::oN);
#else
#pragma message("AVX512F not available, not building related benchmarks")
#endif  // __AVX512F__

#if defined(__ARM_NEON)
static void DISABLED_BM_refill_ip_arm_neon(benchmark::State &state) {
    int d = (int)state.range(0);
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
BENCHMARK(DISABLED_BM_refill_ip_arm_neon)->Range(kRangeMin, kRangeMaxRefill)->Complexity(benchmark::oN);

static void BM_single_fill_ip_arm_neon(benchmark::State &state) {
    int d = (int)state.range(0);
    float *v = new float[d], *w = new float[d];
    fillrandvec(v, d);
    fillrandvec(w, d);
    for (auto _ : state) {
        float d_ip = ip_arm_neon(v, w, d);
        benchmark::DoNotOptimize(d_ip);
    }
    state.SetComplexityN(state.range(0));
    delete[] v;
    delete[] w;
}
BENCHMARK(BM_single_fill_ip_arm_neon)->Range(kRangeMin, kRangeMaxSingleFill)->Complexity(benchmark::oN);
#else
#pragma message("ARM Neon not available, not building related benchmarks")
#endif  // __ARM_NEON

static void DISABLED_BM_refill_ip_blas(benchmark::State &state) {
    int d = (int)state.range(0);
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
BENCHMARK(DISABLED_BM_refill_ip_blas)->Range(kRangeMin, kRangeMaxRefill)->Complexity(benchmark::oN);

static void BM_single_fill_ip_blas(benchmark::State &state) {
    int d = (int)state.range(0);
    float *v = new float[d], *w = new float[d];
    fillrandvec(v, d);
    fillrandvec(w, d);
    for (auto _ : state) {
        float d_ip = ip_blas(v, w, d);
        benchmark::DoNotOptimize(d_ip);
    }
    state.SetComplexityN(state.range(0));
    delete[] v;
    delete[] w;
}
BENCHMARK(BM_single_fill_ip_blas)->Range(kRangeMin, kRangeMaxRefill)->Complexity(benchmark::oN);

BENCHMARK_MAIN();
