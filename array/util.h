#ifndef UTIL
#define UTIL

#include <iostream>
#include <vector>

class Util
{
  public:
    template<class T>
    static void print(const std::vector<T>& array);
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
