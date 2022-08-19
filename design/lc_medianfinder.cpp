#include "lc_medianfinder.h"

namespace lc {

// max - min

void MedianFinder::addNum(int num)
{
    if (d_min_heap.size() == d_max_heap.size()) {
        d_min_heap.push(num);
    } else {
        int n = d_min_heap.top();
        d_min_heap.pop();
        d_max_heap.push(n);
        d_min_heap.push(num);
    }
}

double MedianFinder::findMedian()
{
    if (d_min_heap.size() == d_max_heap.size()) {
        return (d_min_heap.top() + d_max_heap.top()) / 2.0;
    } else {
        return d_min_heap.top();
    }
}

}

