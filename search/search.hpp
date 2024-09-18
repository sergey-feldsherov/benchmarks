#ifndef SEARCH_HPP
#define SEARCH_HPP

int search_linear(int const *numbers, int d, int target) {
    int i = 0;
    for (; i < d; ++i) {
        if (numbers[i] == target) {
            return i;
        }
    }
    return -1;
}

int search_bin(int const *numbers, int d, int target) {
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
    return -1;
}

#endif  // SEARCH_HPP
