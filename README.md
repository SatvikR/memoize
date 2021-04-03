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

    // Prints 5
    std::cout << add_runner.Run(5, 5) << std::endl;
}
```

### Fibonacci example

```c++
#include <iostream>
#include <memoize.h>

typedef <int, uint32_t> MemoizeRunner fib_runner;

static fib_runner *fib_memo;

int fib(uint32_t x)
{
    if (x == 0 || x == 1)
        return 1;
    else
        return fib_memo->Run(x - 1) + fib_memo->Run(x - 2);
}

int main()
{
    fib_memo = new fib_runner(fib);

    auto output = fib_memo->Run(8);

    std::cout << output << std::endl; // should be thirty four

    delete fib_memo;
}
```
