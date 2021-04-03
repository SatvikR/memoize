# memoize

A memoization library for C++

This is a header only library, to use it, download and unzip [memoize.zip](https://github.com/SatvikR/memoize/releases). Once downloaded, add the `include` folder
to your include directories when compiling.

## Example Usage

### Add example

```c++
#include <iostream>
#include <memoize.h>

int add(int a, int b)
{
    return a + b;
}

int main()
{
    // first int is return type, second two are arg types
    MemoizeRunner<int, int, int> add_runner(add);

    // Prints 10
    std::cout << add_runner.Run(5, 5) << std::endl;
}
```

### Fibonacci example

```c++
#include <iostream>
#include "memoize.h"

// static MemoizeRunner to be used throughout this file.
// If you want your MemoizeRunner to be fully global,
// declare it as extern in a header, and define it somewhere else.
static MemoizeRunner<int, uint32_t> *fib_runner;

int fib(uint32_t x) // standard fib algo
{
  if (x <= 1)
    return 1;
  else
    // Recurse using fib_memo rather than just fib()
    return fib_runner->Run(x - 1) + fib_runner->Run(x - 2);
}

int main(int argc, char **argv)
{
  fib_runner = new MemoizeRunner<int, uint32_t>(fib);

  auto output = fib_runner->Run(45);

  std::cout << output << std::endl;
  // prints 1836311903
  // Stats: tldr; memoized is ~97% faster
  // Memoized fib with 45 as an arg runs in 0.25 seconds! (win 10, 6 core CPU, 16gb RAM, release mode)
  // Non memoized fib with 45 as an arg runs in 7.8 seconds (same PC specs, still release mode)

  delete fib_runner;
}
```
