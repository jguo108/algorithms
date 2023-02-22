#ifndef LC_QUESTIONS_H
#define LC_QUESTIONS_H

#include <string>
#include <vector>

namespace lc
{

class Questions
{
  public:
    // Leetcode 3
    size_t lengthOfLongestSubstring(const std::string& input);

    // Leetcode 76 TODO
    std::string minWindowSubstring(const std::string& input);

    // Leetcode 718 TODO
    size_t maxLenOfRepeatedSubarray(const std::vector<int>& array1, const std::vector<int>& array2);
};

}

#endif