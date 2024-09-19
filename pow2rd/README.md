# pow2rd benchmark

A benchmark of methods to round down to power of 2.

## Benchmarks

Building in debug mode vs. release mode changes performance dramatically.

## Manual

Builds into bmpow2rd executable, which runs google benchmark tests.

Usage (assuming you've built main.cpp runner with old-Makefile):

```bash
./main.out 1000 naive
./main.out 1000 builtin
```

This was used to profile with perf.

## TODO

- make sure weird test inputs don't make life easier for any of functions
- add benchmarking results with notes here
- write down here a quick reminder on how to use perf to analyze this code
- fix old-Makefile
- fix bmpow2rd: benchmark on some set of (random?) numbers
