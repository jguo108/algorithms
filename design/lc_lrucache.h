#ifndef LC_LRUCACHE_H
#define LC_LRUCACHE_H

#include <list>
#include <unordered_map>

namespace lc {

struct CacheValue {
  public:
    int val;
    std::list<int>::iterator it;

    CacheValue(int val, const std::list<int>::iterator& it)
    : val(val)
    , it(it)
    {
    }
};

class LRUCache {
  private:
    int                                 d_capacity;
    std::unordered_map<int, CacheValue> d_cache;
    std::list<int>                      d_lru_record;

  public:
    LRUCache(int capacity);

    int get(int key);

    void put(int key, int value);

    void show_cache();
};
}

#endif