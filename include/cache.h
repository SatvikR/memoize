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
class FunctionCache
{
public:
  FunctionCache(){}; // empty constructor

  // Returns cached value (if exists)
  const R &GetFromCache(const Args &...args) const
  {
    auto possible_value = value_map_.find(std::make_tuple(args...)); // (possibly) get value from map

    if (possible_value == value_map_.end()) // if value does not exist yet
    {
      throw MissedCacheException();
    }

    return possible_value->second; // Return value from iterator (possible_value)
  }

  // Inserts args and returning value into the cache
  void SetInCache(const R &returning, const Args &...args)
  {
    value_map_[std::make_tuple(args...)] = returning;
  }

private:
  std::map<std::tuple<Args...>, R> value_map_; // Map that maps function args to return values
};

#endif