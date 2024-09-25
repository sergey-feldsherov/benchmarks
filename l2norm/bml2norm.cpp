#include <random>

#include <benchmark/benchmark.h>

#include "l2norm.hpp"

namespace bm = benchmark;  // TODO: fix this everywhere in project

constexpr int kRangeMin = 8;
constexpr int kRangeMax = 1<<16;

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_real_distribution<float> uni(0, 1);  // TODO: try other distributions

void fillrandvec(float *vec, int d) {
    for (int i = 0; i < d; ++i) {
         vec[i] = uni(mt);
    }
}

static void BM_l2norm_naive(bm::State &state) {
    int d = (int)state.range(0);
    float *v = new float[(unsigned int)d];
    fillrandvec(v, d);
    for (auto _ : state) {
        float norm = l2norm_naive(v, d);
        bm::DoNotOptimize(norm);
    }
    state.SetComplexityN(state.range(0));
    delete[] v;
}
BENCHMARK(BM_l2norm_naive)->Range(kRangeMin, kRangeMax)->Complexity(bm::oN);

static void BM_l2normsqr_naive(bm::State &state) {
    int d = (int)state.range(0);
    float *v = new float[(unsigned int)d];
    fillrandvec(v, d);
    for (auto _ : state) {
        float norm = l2normsqr_naive(v, d);
        bm::DoNotOptimize(norm);
    }
    state.SetComplexityN(state.range(0));
    delete[] v;
}
BENCHMARK(BM_l2normsqr_naive)->Range(kRangeMin, kRangeMax)->Complexity(bm::oN);

static void BM_l2norm_blas_snrm2(bm::State &state) {
    int d = (int)state.range(0);
    float *v = new float[(unsigned int)d];
    fillrandvec(v, d);
    for (auto _ : state) {
        float norm = l2norm_blas_snrm2(v, d);
        bm::DoNotOptimize(norm);
    }
    state.SetComplexityN(state.range(0));
    delete[] v;
}
BENCHMARK(BM_l2norm_blas_snrm2)->Range(kRangeMin, kRangeMax)->Complexity(bm::oN);

static void BM_l2normsqr_blas_sdot(bm::State &state) {
    int d = (int)state.range(0);
    float *v = new float[(unsigned int)d];
    fillrandvec(v, d);
    for (auto _ : state) {
        float norm = l2normsqr_blas_sdot(v, d);
        bm::DoNotOptimize(norm);
    }
    state.SetComplexityN(state.range(0));
    delete[] v;
}
BENCHMARK(BM_l2normsqr_blas_sdot)->Range(kRangeMin, kRangeMax)->Complexity(bm::oN);

BENCHMARK_MAIN();
