//---------------------------------------------------------------------------
// (c) 2021 Satvik Reddy
//
// File: memoize.h
// Desc: Header that needs to be included to use the Memoize library
//---------------------------------------------------------------------------

#ifndef MEMOIZE_H
#define MEMOIZE_H

#include "cache.h"

typedef void (*raw_function)(void);

// Class used to map function pointers to caches
class _Function_Cache_Map
{
public:
    _Function_Cache_Map(){}; // No constructor

    ~_Function_Cache_Map()
    {
        for (std::map<raw_function, void *>::iterator it = m_function_map.begin(); it != m_function_map.end(); ++it)
        {
            // _Cache **c_ptr = static_cast<_Cache **>(it->second);
        }
    };

private:
    // Pointer must be void to make sure there is only one _Function_Cache_Map at any time
    std::map<raw_function, void *> m_function_map;
};

// Function that returns the output of the function call from the cache if it exists,
// Or just runs the function and sets it in the cache if it does not yet exist
// R: return type, Args: arg types in order
template <typename R, typename... Args>
R memoized(raw_function func, Args... args)
{
}

#endif