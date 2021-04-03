#include <iostream>
#include "memoize.h"

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

	auto output = fib_with_memo(6, &fib_memo_runner);
	std::cout << output << std::endl; // should be thirteen
}

int main(int argc, char **argv)
{
	test();

	return 0;
}
