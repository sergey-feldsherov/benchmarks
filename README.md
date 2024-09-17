# benchmarks

Various benchmarks.

## Building

First of all, generate a build system:

```bash
user@host:~/benchmarks$ cmake -S. -Bbuild -DCMAKE_BUILD_TYPE=Release -GNinja
```

Invoke the build system afterwards:

```bash
user@host:~/benchmarks$ cmake --build build
```
