#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline uint32_t pow2rd_naive(uint32_t n) {
	uint32_t res = 1;
	while (2 * res <= n) {
		res *= 2;
	}
	return res;
}

inline uint32_t pow2rd_builtin(uint32_t n) {
	uint32_t nlz = __builtin_clz(n);
	return 1 << (31 - nlz);
}

int main(int argc, char *argv[]) {
	assert(argc == 3);
	assert(strcmp(argv[2], "naive") == 0 || strcmp(argv[2], "builtin") == 0);
	char *rest;
	unsigned int num = strtoul(argv[1], &rest, 10);

	uint32_t *args = (uint32_t *) malloc(sizeof(uint32_t) * num);
	for (unsigned int i = 0; i < num; ++i) {
		args[i] = (uint32_t) rand();
	}

	uint32_t *res = (uint32_t *) malloc(sizeof(uint32_t) * num);

	if (strcmp(argv[2], "naive") == 0) {
		for (unsigned int i = 0; i < num; ++i) {
			res[i] = pow2rd_naive(args[i]);
		}
	} else {
		for (unsigned int i = 0; i < num; ++i) {
			res[i] = pow2rd_builtin(args[i]);
		}
	}

	free(args);
	free(res);

	return 0;
}
