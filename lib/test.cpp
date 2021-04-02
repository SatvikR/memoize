#include <iostream>
#include "memoize.h"
#include "cache.h"

void test()
{
	auto c = Cache<int, int, int>();

	c.set_in_cache(10, 5, 5);

	auto o = c.get_from_cache(5, 5);

	std::cout << o << std::endl;
}