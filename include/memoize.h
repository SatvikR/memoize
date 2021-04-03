//---------------------------------------------------------------------------
// (c) 2021 Satvik Reddy
//
// File: memoize.h
// Desc: Header that needs to be included to use the Memoize library
//---------------------------------------------------------------------------

#ifndef MEMOIZE_H
#define MEMOIZE_H

#include "cache.h"

// memoize_runner will create an object to run your function in a memoized manner
// R: returning type, Args: arg types
template <typename R, typename... Args>
class memoize_runner
{
public:
    memoize_runner(R (*p_func)(Args...))
    {
        m_cache = new _Cache<R, Args...>; // Intialize cache with template types
        m_p_func = p_func;                // Create reference to function pointer to use
    }

    ~memoize_runner()
    {
        delete m_cache;
    }

    R run(Args... args)
    {
        R returning;

        try
        {
            returning = m_cache->get_from_cache(args...); // Try to get value from cache
        }
        catch (const std::exception &e)
        {
            returning = m_p_func(args...);             // Call function
            m_cache->set_in_cache(returning, args...); // cache value
        }

        return returning;
    }

private:
    _Cache<R, Args...> *m_cache; // Cache for the memozied function
    R(*m_p_func)                 // Function pointing to memo'd function
    (Args...);
};

#endif