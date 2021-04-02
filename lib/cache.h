//---------------------------------------------------------------------------
// (c) 2021 Satvik Reddy
//
// File: cache.h
// Desc: Header that includes Memoize's caching code
//---------------------------------------------------------------------------

#ifndef CACHE_H
#define CACHE_H

// Singleton class to represent our cache
class Cache
{
public:
	Cache(const Cache &) = delete; // Disable copying
	static Cache *get_instance();  // Returns cache instance

	void test();

private:
	Cache(){}; // Make sure no more instances can be created

	static Cache *s_instance;
};

Cache *Cache::s_instance = nullptr;

#endif