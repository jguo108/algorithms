#ifndef EXERCISE
#define EXERCISE

#include <iostream>
#include <vector>

class Exercise 
{
  public:
    static std::vector<int> intersectSortedArrays(const std::vector<int>& array1,
                                                  const std::vector<int>& array2);
      // EPI, Problem 14.1, Page 213

    static void mergeSortedArrays(std::vector<int>&       array1,
                                  const std::vector<int>& array2);
      // EPI, Problem 14.2, Page 214
};

#endif
