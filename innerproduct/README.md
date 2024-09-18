# inner product distance benchmark

A benchmark for functions running inner product distance computations.

## TODO

- compile options should be dependent on build type
- restricts are forgotten???
- current arm/x86 manual vectorizations are not as good probably...
- is it possible to automatically choose which function to benchmark without so much boilerplate?
- adjust ip_blas complexity (RMS is 10%)
- think about warmup iterations
- multi-vector distance computation
- idea: use stride for multi-vector calculations (BLAS)
