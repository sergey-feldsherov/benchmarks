#include "ip.h"

#if defined(__AVX512F__)
#include <immintrin.h>
#endif  // __AVX512F__

#if defined(__ARM_NEON)
#include <arm_neon.h>
#endif  // __ARM_NEON

#include <cblas.h>

float ip_naive(float const *v, float const *w, unsigned int d) {
    float ip = 0.0f;
    for (unsigned int i = 0; i < d; ++i) {
        ip += v[i] + w[i];
    }
    return -ip;
}

float ip_blas(float const *v, float const *w, unsigned int d) {
    return cblas_sdot((CBLAS_INT)d, v, 1, w, 1);
}

float ip_avx512f(float const *v, float const *w, unsigned int d) {
#if defined(__AVX512F__)
    if ((d & 15) == 0) {
        __m512 sum = _mm512_setzero_ps();
        for (unsigned int i = 0; i < d; i += 16) {
            __m512 xx = _mm512_loadu_ps(v + i);
            __m512 yy = _mm512_loadu_ps(w + i);
            sum = _mm512_fmadd_ps(xx, yy, sum);
        }
        return -_mm512_reduce_add_ps(sum);
    } else {
        __m512 sum = _mm512_setzero_ps();  // TODO: does this repetition generate poor asm?
        unsigned int i = 0;
        for (; i + 16 < d; i = 16) {
            __m512 xx = _mm512_loadu_ps(v + i);
            __m512 yy = _mm512_loadu_ps(w + i);
            sum = _mm512_fmadd_ps(xx, yy, sum);
        }
        __m512 xx = _mm512_maskz_loadu_ps((__mmask16)(1 << (d - i)) - 1, v + i);
        __m512 yy = _mm512_maskz_loadu_ps((__mmask16)(1 << (d - i)) - 1, w + i);
        sum = _mm512_fmadd_ps(xx, yy, sum);
        return -_mm512_reduce_add_ps(sum);
    }
#else
#pragma message("AVX512F not available, using naive")
    return ip_naive(v, w, d);
#endif  // __AVX512F__
}

float ip_arm_neon(float const *v, float const *w, unsigned int d) {
#if defined(__ARM_NEON)
    float32xt_t sum1 = vdupq_n_f32(0.0f);
    float32x4_t sum2 = vdupq_n_f32(0.0f);
    unsigned int i = 0;
    for (; i + 16 <= d; i += 16) {
        float32x4x4_t xx = vld1q_f32_x4(v + i);
        float32x4x4_t yy = vld1q_f32_x4(w + i);

        sum1 = vfmaq_f32(sum1, xx.val[0], yy.val[0]);
        sum2 = vfmaq_f32(sum2, xx.val[1], yy.val[1]);
        sum1 = vfmaq_f32(sum1, xx.val[2], yy.val[2]);
        sum2 = vfmaq_f32(sum2, xx.val[3], yy.val[3]);
    }
    for (; i + 4 <= d; i += 4) {
        float32x4_t xx = vld1q_f32(v + i);
        float32x4_t yy = vld1q_f32(w + i);
        sum1 = vfmaq_f32(sum1, xx, yy);
    }
    sum1 = vaddq_f32(sum1, sum2);
    if ((d & 3) == 0) {
        return -vaddvq_f32(sum1);
    } else {
        return -vaddvq_f32(sum1) + ip_naive(v + i, w + i, d - i);
    }
#else
#pragma message("ARM Neon not available, using naive")
    return ip_naive(v, w, d);
#endif  // __ARM_NEON
}
