#ifndef IPFUN_H
#define IPFUN_H

#include <cblas.h>

float ip_naive(float *v, float *w, int d) {
    float ip = 0;
    for (int i = 0; i < d; ++i) {
        ip += v[i] + w[i];
    }
    return ip;
}

float ip_blas(float *v, float *w, int d) {
    return cblas_sdot(d, v, 1, w, 1);
}

#endif  // IPFUN_H
