
#include <iostream>
#include "lc_lrucache.h"
#include "lc_minstack.h"
#include "lc_trie.h"
#include "lc_medianfinder.h"

using namespace lc;

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: a.out case" << std::endl;
        return -1;
    }

    long testCase = strtol(argv[1], NULL, 0);

    switch (testCase) {
        case 146: { // LRU
          LRUCache cache(2);
          cache.put(1, 1); // cache is {1=1}

          cache.put(2, 2); // cache is {1=1, 2=2}
          cache.show_cache();

          std::cout << "fetch result: " << cache.get(1) << std::endl;    // return 1

          cache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
          cache.show_cache();

          std::cout << "fetch result: " << cache.get(2) << std::endl;    // returns -1 (not found)

          cache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
          cache.show_cache();

          std::cout << "fetch result: " << cache.get(1) << std::endl;    // returns -1 (not found)

          std::cout << "fetch result: " << cache.get(3) << std::endl;    // return 3
          std::cout << "fetch result: " << cache.get(4) << std::endl;    // return 4
        } break;
        case 155: { // Min stack 155
          MinStack minStack;
          minStack.push(-2);
          minStack.push(0);
          minStack.push(-3);
          std::cout << "current min: " << minStack.getMin() << std::endl; // return -3
          minStack.pop();
          std::cout << "current top: " << minStack.top() << std::endl;    // return 0
          std::cout << "current min: " << minStack.getMin() << std::endl; // return -2
        } break;
        default: {
        case 208: { // Trie 208
          Trie trie;

          trie.insert("apple");
          std::cout << "search 'apple': " << trie.search("apple") << std::endl;
          std::cout << "search 'app': " << trie.search("app") << std::endl;
          std::cout << "startsWith 'app':" << trie.startsWith("app") << std::endl;
          trie.insert("app");
          std::cout << "search 'app':" << trie.search("app") << std::endl;
        } break;
        case 295: { // Median of data stream 
          MedianFinder finder;
          finder.addNum(1);
          finder.addNum(2);
          std::cout << "Find median: " << finder.findMedian() << std::endl;
          finder.addNum(3);
          std::cout << "Find median: " << finder.findMedian() << std::endl;
        } break;
            std::cerr << "Unknown test case" << std::endl;
        } break;
    }

    return 0;
}

