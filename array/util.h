#ifndef UTIL
#define UTIL

#include <iostream>
#include <vector>

struct Util
{
  public:
    template<class T>
    static void print(const std::vector<T>& array);

    static void dutchFlag(std::vector<int>& array, int pivotIdx);
      // EPI, Problem 3.1, Page 37
};

template<class T>
void Util::print(const std::vector<T>& array)
{
    for (const auto& v : array) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

#endif
