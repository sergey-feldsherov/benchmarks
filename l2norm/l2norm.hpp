#ifndef L2NORM_HPP
#define L2NORM_HPP

float l2normsqr_naive(float const *x, int d);
float l2norm_naive(float const *x, int d);
float l2normsqr_blas_sdot(float const *x, int d);
float l2norm_blas_snrm2(float const *x, int d);

#endif  // L2NORM_HPP
