#include <iostream>
#include "memoize.h"

typedef MemoizeRunner<int, uint32_t> fib_runner;

static fib_runner *fib_memo;

int fib(uint32_t x)
{
    if (x == 0 || x == 1)
        return 1;
    else
        return fib_memo->Run(x - 1) + fib_memo->Run(x - 2);
}

void test()
{
    fib_memo = new fib_runner(fib);

    auto output = fib_memo->Run(8);

    std::cout << output << std::endl; // should be thirty four

    delete fib_memo;
}

int main(int argc, char **argv)
{
    test();

    return 0;
}
