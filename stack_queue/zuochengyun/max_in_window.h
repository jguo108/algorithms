
#include <vector>
#include <deque>

using namespace std;

vector<int> findMaxInWindow(const vector<int>& array, size_t windowSize)
{
    vector<int> result;
    deque<size_t> workingQueue;

    int maxIndex = 0;
    int maxVal = array[0];
    for (size_t i = 1; i < windowSize; ++i) {
        if (array[i] > maxVal) {
            maxIndex = i;
            maxVal = array[i];
        }
    }
    result.push_back(maxVal);
    workingQueue.push_back(maxIndex);


    for (size_t i = windowSize; i < array.size(); ++i) {
        int currentVal = array[i];
        while (!workingQueue.empty()) {
            if (currentVal > array[workingQueue.back()]) {
                workingQueue.pop_back();
                continue;
            } else {
                break;
            }
        }
        workingQueue.push_back(i);
        if ((i - workingQueue.front()) >= windowSize) {
            workingQueue.pop_front();
        }
        result.push_back(array[workingQueue.front()]);
    }

    return result;
}