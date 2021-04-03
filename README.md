# memoize

A memoization library for C++

This is a header only library, to use it simply copy the `include` directory into
your project and add it to your include directories when compiling.

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
    memoize_runner<int, int, int> add_runner(add); 
    
    // Prints 5
    std::cout << add_runner.run(5, 5) << std::endl; 
}
```

### Fibonacci example

```c++
#include <iostream>
#include <memoize.h>

int fib(uint32_t x)
{
    if (x == 0 || x == 1)
        return 1;
    else
        return fib(x - 1) + fib(x - 2);
}

int fib_with_memo(uint32_t x, memoize_runner<int, uint32_t> *runner)
{
    if (x == 0 || x == 1)
        return 1;
    else
        return runner->run(x - 1) + runner->run(x - 2);
}

void test()
{
    memoize_runner<int, uint32_t> fib_memo_runner(fib);

    int output = fib_with_memo(6, &fib_memo_runner);

    // should be thirteen
    std::cout << output << std::endl; 
}
```
