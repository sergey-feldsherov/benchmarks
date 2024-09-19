#ifndef SEARCH_HPP
#define SEARCH_HPP

unsigned int search_linear(int const *numbers, unsigned int d, int target) {
    unsigned int i = 0;
    for (; i < d; ++i) {
        if (numbers[i] == target) {
            return i;
        }
    }
    return d;
}

unsigned int search_bin(int const *numbers, unsigned int d, int target) {
    int l = 0, r = d - 1;
    while(l <= r) {
        int m = l + (r - l) / 2;
        if (numbers[m] == target) {
            return m;
        } else if (numbers[m] < target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return d;
}

#endif  // SEARCH_HPP
