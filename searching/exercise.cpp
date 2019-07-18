
#include "exercise.h"
#include <climits>
#include <algorithm>

// ============================================================================

static int searchFirstOccurenceImpl(const std::vector<int>& array,
                                    int                     start,
                                    int                     end,
                                    int                     target)
{
    if (start > end) {
        return -1;
    }

    int pivotIndex = (start + end) / 2;
    int pivot = array[pivotIndex];

    if (pivot == target) {
        if (pivotIndex == 0 || array[pivotIndex - 1] < pivot) {
            return pivotIndex;
        }
        return searchFirstOccurenceImpl(array, start, pivotIndex - 1, target); 
    } else if (pivot > target) {
        return searchFirstOccurenceImpl(array, start, pivotIndex - 1, target); 
    } else { // pivot < target
        return searchFirstOccurenceImpl(array, pivotIndex + 1, end, target); 
    }
}

int Exercise::searchFirstOccurence(const std::vector<int>& array, int target)
{
    return searchFirstOccurenceImpl(array, 0, array.size() - 1, target);
}

// ============================================================================

static int findIndexEqualToElementImpl(const std::vector<int>& array,
                                       int                     start,
                                       int                     end)
{
    if (start > end) {
        return -1;
    }

    int midIndex = (start + end) / 2;

    if (midIndex == array[midIndex]) {
        return midIndex;
    }

    if (midIndex > array[midIndex]) {
        return findIndexEqualToElementImpl(array, midIndex + 1, end);
    } else {
        return findIndexEqualToElementImpl(array, start, midIndex - 1);
    }
}

int Exercise::findIndexEqualToElement(const std::vector<int>& array)
{
    return findIndexEqualToElementImpl(array, 0, array.size() - 1);
}

// ============================================================================

static int searchCyclicallySortedArrayImpl(const std::vector<int>& array,
                                           int                     start,
                                           int                     end)
{
    if (array[end] >= array[start]) {
        return start;
    }

    int pivotIndex = (start + end) / 2;
    int pivot = array[pivotIndex];

    if (pivot >= array[start]) {
        return searchCyclicallySortedArrayImpl(array, pivotIndex + 1, end);
    } else {
        return searchCyclicallySortedArrayImpl(array, start, pivotIndex);
    }
}

int Exercise::searchCyclicallySortedArray(const std::vector<int>& array)
{
    return searchCyclicallySortedArrayImpl(array, 0, array.size() - 1);
}

// ============================================================================


























