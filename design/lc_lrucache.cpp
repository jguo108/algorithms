#include "lc_lrucache.h"
#include <iostream>

namespace lc {

LRUCache::LRUCache(int capacity)
: d_capacity(capacity)
, d_cache()
, d_lru_record()
{
}

int LRUCache::get(int key)
{
    auto it = d_cache.find(key);

    if (it == d_cache.end()) {
        return -1;
    }

    d_lru_record.erase(it->second.it);
    d_lru_record.push_back(key);

    it->second.it = --d_lru_record.end();

    return it->second.val;
}

void LRUCache::put(int key, int value)
{
    if (d_cache.size() == (size_t)d_capacity) {
        auto victim = d_lru_record.begin();
        d_lru_record.pop_front();
        d_cache.erase(*victim);
    }
    d_lru_record.push_back(key);
    d_cache.insert({key, CacheValue(value, --d_lru_record.end())});
}

void LRUCache::show_cache()
{
    for (auto const& pair : d_cache) {
        std::cout << "{" << pair.first << ", " << pair.second.val << "}\n";
    } 
}

}