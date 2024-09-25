#include "l2norm.hpp"

#include <cblas.h>
#include <cmath>

float l2normsqr_naive(float const *x, int d) {
    float sqrnorm = 0.0f;
    for (int i = 0; i < d; ++i) {
        sqrnorm += x[i] * x[i];
    }
    return sqrnorm;
}

float l2norm_naive(float const *x, int d) {
    return sqrtf(l2normsqr_naive(x, d));
}

float l2normsqr_blas_sdot(float const *x, int d) {
    return cblas_sdot(d, x, 1, x, 1);
}

float l2norm_blas_snrm2(float const *x, int d) {
    return cblas_snrm2(d, x, 1);
}
