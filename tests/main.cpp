#include <iostream>
#include "memoize.h"

void test()
{
	auto c = _Cache<int, int, int>();

	c.set_in_cache(10, 5, 5);

	try
	{
		auto o = c.get_from_cache(5, 5);
		std::cout << o << std::endl;

		auto missed_cache = c.get_from_cache(6, 6);
		std::cout << missed_cache << std::endl; // won't work
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main(int argc, char **argv)
{
	int *a = new int;

	*a = 5;

	// int **ptr = &a;

	// delete *ptr;
	delete a;

	std::cout << *a << std::endl;

	return 0;
}
