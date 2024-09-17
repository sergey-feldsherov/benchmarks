#ifndef IPFUN_H
#define IPFUN_H

#include <cblas.h>

float ip_naive(float const *v, float const *w, int d) {
    float ip = 0.0f;
    for (int i = 0; i < d; ++i) {
        ip += v[i] + w[i];
    }
    return ip;
}

float ip_blas(float const *v, float const *w, int d) {
    return cblas_sdot(d, v, 1, w, 1);
}

#endif  // IPFUN_H
