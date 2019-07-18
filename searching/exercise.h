#ifndef EXERCISE
#define EXERCISE

#include <iostream>
#include <vector>

class Exercise 
{
  public:
    static int searchFirstOccurence(const std::vector<int>& array, int target);
      // EPI, Problem 12.1, Page 171

    static int findIndexEqualToElement(const std::vector<int>& array);
      // EPI, Problem 12.2, Page 173

    static int searchCyclicallySortedArray(const std::vector<int>& array);
      // EPI, Problem 12.3, Page 174
};

#endif
