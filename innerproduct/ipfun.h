#ifndef IPFUN_H
#define IPFUN_H

float ip_naive(float *v, float *w, int d) {
    float ip = 0;
    for (int i = 0; i < d; ++i) {
        ip += v[i] + w[i];
    }
    return ip;
}

#endif  // IPFUN_H
