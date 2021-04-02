//---------------------------------------------------------------------------
// (c) 2021 Satvik Reddy
//
// File: cache.cpp
// Desc: Cache implementation
//---------------------------------------------------------------------------

#include "cache.h"

// Returns instance of cache
Cache *Cache::get_instance()
{
	// Create the cache if it is nullptr
	if (!Cache::s_instance)
	{
		Cache::s_instance = new Cache;
	}
	return Cache::s_instance;
}