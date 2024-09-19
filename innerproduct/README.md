# inner product distance benchmark

A benchmark for functions running inner product distance computations.

## TODO

- shift all important stuff to separate lib
- compile options should be dependent on build type
- restricts are forgotten???
- current arm/x86 manual vectorizations are not as good probably...
- is it possible to automatically choose which function to benchmark without so much boilerplate?
- multi-vector distance computation
- idea: use stride for multi-vector calculations (BLAS)
