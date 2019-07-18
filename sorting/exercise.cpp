
#include "exercise.h"
#include <climits>
#include <algorithm>

// ============================================================================

std::vector<int> Exercise::intersectSortedArrays(const std::vector<int>& array1,
                                                 const std::vector<int>& array2)
{
    std::vector<int> result;

    int i = 0;
    int j = 0;

    while (i < array1.size() && j < array2.size()) {
        if (array1[i] < array2[j]) {
            ++i;
        } else if (array1[i] > array2[j]) {
            ++j;
        } else {
            if (result.empty() || array1[i] != result.back()) {
                result.push_back(array1[i]);
            }
            ++i;
            ++j;
        }
    }

    return result;
}
