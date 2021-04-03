//---------------------------------------------------------------------------
// (c) 2021 Satvik Reddy
//
// File: memoize.h
// Desc: Header that needs to be included to use the Memoize library
//---------------------------------------------------------------------------

#ifndef MEMOIZE_H
#define MEMOIZE_H

#include "cache.h"

// MemoizeRunner will create an object to run your function in a memoized manner
// R: returning type, Args: arg types
template <typename R, typename... Args>
class MemoizeRunner
{
public:
  MemoizeRunner(R (*p_func)(Args...))
  {
    cache_ = new FunctionCache<R, Args...>; // Intialize cache with template types
    p_func_ = p_func;                       // Create reference to function pointer to use
  }

  ~MemoizeRunner()
  {
    delete cache_;
  }

  R Run(Args... args)
  {
    R returning;

    try
    {
      returning = cache_->GetFromCache(args...); // Try to get value from cache
    }
    catch (std::exception)
    {
      returning = p_func_(args...);           // Call function
      cache_->SetInCache(returning, args...); // cache value
    }

    return returning;
  }

private:
  FunctionCache<R, Args...> *cache_; // Cache for the memozied function
  R(*p_func_)                        // Function pointing to memo'd function
  (Args...);
};

#endif