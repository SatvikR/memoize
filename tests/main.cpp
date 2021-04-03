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
    return fib_runner->Run(x - 1) + fib_runner->Run(x - 2); // Recurse using fib_memo rather than just fib()
}

void test()
{
  fib_runner = new MemoizeRunner<int, uint32_t>(fib);

  auto output = fib_runner->Run(45);

  std::cout << output << std::endl;
  // prints 1836311903
  // Stats:
  // Memoized fib with 45 as an arg runs in 0.25 seconds! (win 10, 6 core CPU, 16gb RAM, release mode)
  // Non memoized fib with 45 as an arg runs in 7.8 seconds (same specs, still release mode)

  delete fib_runner;
}

int main(int argc, char **argv)
{
  test();

  return 0;
}
