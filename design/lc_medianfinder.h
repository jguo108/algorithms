#ifndef LC_MEDIANFINDER_H
#define LC_MEDIANFINDER_H

#include <queue>
#include <vector>

namespace lc {

class MedianFinder
{
  private:
    std::priority_queue<int, std::vector<int>, std::greater<int> > d_min_heap;
    std::priority_queue<int, std::vector<int>, std::less<int> > d_max_heap;

  public:
    void addNum(int num);

    double findMedian();
};

}

#endif