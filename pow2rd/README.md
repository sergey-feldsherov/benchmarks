# pow2rd benchmark

A benchmark of methods to round down to power of 2.

Builds into bmpow2rd executable, which runs google benchmark tests.

Usage (assuming you've built main.cpp runner with old-Makefile):

```bash
./main.out 1000 naive
./main.out 1000 builtin
```

This was used to profile with perf.

# TODO

write down here a quick reminder on how to use perf to analyze this code
