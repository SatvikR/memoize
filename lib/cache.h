//---------------------------------------------------------------------------
// (c) 2021 Satvik Reddy
//
// File: cache.h
// Desc: Header that includes Memoize's caching code
//---------------------------------------------------------------------------

#ifndef CACHE_H
#define CACHE_H

#include <map>

// The Cache class holds individual caches for each function that is memoized
template <typename R, typename... Args> // R = return value, ...Args = arg Types
class Cache
{
public:
	Cache(); // Cache constructor

	R &get_from_cache(Args... args);			  // Returns cached value (if exists)
	void set_in_cache(R returning, Args... args); // Inserts args and returning value into the cache

private:
	std::map<std::tuple<Args...>, R> m_value_map; // Map that maps function args to return values
};

#endif