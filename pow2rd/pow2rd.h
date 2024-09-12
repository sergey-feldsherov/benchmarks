#ifndef POW2RD_H
#define POW2RD_H

inline uint32_t pow2rd_naive(uint32_t n) {
    uint32_t res = 1;
    while (2 * res <= n) {
        res *= 2;
    }
    return res;
}

inline uint32_t pow2rd_builtin_clz(uint32_t n) {
    uint32_t nlz = __builtin_clz(n);
    return 1 << (31 - nlz);
}

#endif  // POW2RD_H
