
#include "lc_questions.h"

#include <unordered_map>
#include <unordered_set>

namespace lc
{

size_t Questions::lengthOfLongestSubstring(const std::string& input)
{
    if (input.empty()) {
        return 0;
    }

    std::unordered_set<char> counters;
    size_t beginPtr = 0;
    size_t endPtr = 0;
    size_t maxLen = 1;

    while (endPtr < input.size()) {
        char currentChar = input[endPtr];

        if (counters.find(currentChar) == counters.end()) {
            counters.insert(currentChar);
        } else {
            maxLen = std::max(maxLen, endPtr - beginPtr);
            while (beginPtr <= endPtr) {
                if (input[beginPtr] == currentChar) {
                    break;
                }
                ++beginPtr;
            }
            ++beginPtr;
        }
        ++endPtr;
    }
    return maxLen;
}

}