# benchmarks

Various benchmarks.

## TODO

- check how to correctly build Google benchmark in release mode

## Building

First of all, generate a build system:

```bash
user@host:~/benchmarks$ cmake -S. -Bbuild -DCMAKE_BUILD_TYPE=Release -GNinja
```

Invoke the build system afterwards:

```bash
user@host:~/benchmarks$ cmake --build build
```
