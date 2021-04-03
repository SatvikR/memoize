//---------------------------------------------------------------------------
// (c) 2021 Satvik Reddy
//
// File: cache.h
// Desc: Header that includes Memoize's caching code
//---------------------------------------------------------------------------

#ifndef CACHE_H
#define CACHE_H

#include <map>
#include <exception>

// Exception used when the memoized value is not in the cache
// Results in the value being fetched by calling the function
class _Missed_Cache_Exception : public std::exception
{
    virtual const char *what() const throw()
    {
        return "Memoized value not in cache";
    }
};

// The Cache class holds individual caches for each function that is memoized
template <typename R, typename... Args> // R = return value, ...Args = arg Types
class _Cache                            // Using _ to make sure there is no naming collision if someone has a Cache class in their application
{
public:
    _Cache(){}; // Cache constructor

    // Returns cached value (if exists)
    R &get_from_cache(Args... args)
    {
        auto possible_value = m_value_map.find(std::make_tuple(args...)); // (possibly) get value from map

        if (possible_value == m_value_map.end()) // if value does not exist yet
        {
            throw _Missed_Cache_Exception();
        }

        return possible_value->second; // Return value from iterator (possible_value)
    }

    // Inserts args and returning value into the cache
    void set_in_cache(R returning, Args... args)
    {
        m_value_map[std::make_tuple(args...)] = returning;
    }

private:
    std::map<std::tuple<Args...>, R> m_value_map; // Map that maps function args to return values
};

#endif