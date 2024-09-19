#ifndef IP_H
#define IP_H

float ip_naive(float const *v, float const *w, unsigned int d);
float ip_blas(float const *v, float const *w, unsigned int d);
float ip_avx512f(float const *v, float const *w, unsigned int d);
float ip_arm_neon(float const *v, float const *w, unsigned int d);

#endif  // IP_H
