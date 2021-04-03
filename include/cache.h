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
class MissedCacheException : public std::exception
{
  virtual const char *what() const throw()
  {
    return "Memoized value not in cache";
  }
};

// The FunctionCache class holds individual caches for each function that is memoized
template <typename R, typename... Args> // R = return value, ...Args = arg Types
class FunctionCache                     // Using _ to make sure there is no naming collision if someone has a Cache class in their application
{
public:
  FunctionCache(){}; // Cache constructor

  // Returns cached value (if exists)
  R &GetFromCache(Args... args)
  {
    auto possible_value = m_value_map_.find(std::make_tuple(args...)); // (possibly) get value from map

    if (possible_value == m_value_map_.end()) // if value does not exist yet
    {
      throw MissedCacheException();
    }

    return possible_value->second; // Return value from iterator (possible_value)
  }

  // Inserts args and returning value into the cache
  void SetInCache(R returning, Args... args)
  {
    m_value_map_[std::make_tuple(args...)] = returning;
  }

private:
  std::map<std::tuple<Args...>, R> m_value_map_; // Map that maps function args to return values
};

#endif