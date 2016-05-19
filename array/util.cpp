
#include "util.h"


void Util::dutchFlag(std::vector<int>& array, int pivotIdx)
{
    if (pivotIdx < 0 || pivotIdx >= array.size()) {
        return;
    }

    int pivot = array[pivotIdx];
    size_t left = 0;
    size_t right = array.size() - 1;
    size_t equal = 0;

    while (true) {
        while (array[left] <= pivot && left <= right) {
            if (array[left] < pivot) {
                std::swap(array[left], array[equal]);
                ++equal;
            }
            ++left;
        }
        while (array[right] > pivot && right >= left) {
            --right;
        }

        if (left > right) {
            break;
        }
        std::swap(array[left], array[right]);
    }
}

