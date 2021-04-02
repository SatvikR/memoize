//---------------------------------------------------------------------------
// (c) 2021 Satvik Reddy
//
// File: cache.cpp
// Desc: Cache implementation
//---------------------------------------------------------------------------

#include "cache.h"

// Define default constructor as empty
template <typename R, typename... Args>
Cache<R, Args...>::Cache()
{
}

// Get value from cache
template <typename R, typename... Args>
R &Cache<R, Args...>::get_from_cache(Args... args)
{
	R possible_value = m_value_map.find(std::make_tuple(args...)); // (possibly) get value from map

	if (possible_value == m_value_map.end()) // if value does not exist yet
	{
		return nullptr; // Return null
	}

	return &possible_value;
}

// Set in cache
template <typename R, typename... Args>
void Cache<R, Args...>::set_in_cache(R returning, Args... args)
{
	m_value_map.insert(std::make_tuple(args...), R); // Insert args and returning into cache
}