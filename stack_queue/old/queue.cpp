#include "queue.h"

Queue::Queue()
{
}

Queue::~Queue()
{
}

void Queue::enqueue(int elem)
{
    d_elements.push_back(elem);

    while (!d_maxCandidates.empty()) {
        int last = d_maxCandidates.back();
        if (last > elem) {
            break;
        }
        d_maxCandidates.pop_back();
    }
    d_maxCandidates.push_back(elem);
}

int Queue::dequeue()
{
    if (d_elements.empty()) {
        throw std::exception();
    }
    int result = d_elements.front();
    d_elements.pop_front();

    if (result == d_maxCandidates.front()) {
        d_maxCandidates.pop_front();
    }

    return result;
}

int Queue::max() const
{
    if (d_elements.empty()) {
        throw std::exception();
    }
    return d_maxCandidates.front();
}

size_t Queue::size() const
{
    return d_elements.size();
}

void Queue::print() const
{
    for (int entry : d_elements) {
        std::cout << entry << " ";
    }
    std::cout << std::endl;
}

