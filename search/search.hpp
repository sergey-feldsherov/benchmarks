#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <vector>

int search_linear(std::vector<int> numbers, int target) {
    int i = 0;
    for (; i < (int)numbers.size(); ++i) {
        if (numbers[i] == target) {
            return i;
        }
    }
    return -1;
}

int search_bin(std::vector<int> numbers, int target) {
    int l = 0, r = (int)numbers.size() - 1;
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
