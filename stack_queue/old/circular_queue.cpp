#include "circular_queue.h"

CircularQueue::CircularQueue(int capacity)
: d_elements(capacity, 0)
, d_head(0)
, d_tail(0)
, d_size(0)
, d_capacity(capacity)
{
}

CircularQueue::~CircularQueue()
{
}

void CircularQueue::enqueue(int elem)
{
    if (d_size < d_capacity) {
        d_elements[d_tail++] = elem;
        d_tail %= d_capacity; 
        ++d_size;
        return;
    }
    std::vector<int> newStorage(d_capacity * 2, 0);
    int newStorageIndex = 0;
    for (int i = d_head; i < d_capacity; ++i, ++newStorageIndex) {
        newStorage[newStorageIndex] = d_elements[i];
    }
    for (int i = 0; i < d_tail; ++i, ++newStorageIndex) {
        newStorage[newStorageIndex] = d_elements[i];
    }
    d_head = 0;
    d_tail = newStorageIndex;
    newStorage[d_tail++] = elem;
    ++d_size;
    d_capacity *= 2;
    d_elements.swap(newStorage);
}

int CircularQueue::dequeue()
{
    if (d_size == 0) {
        throw std::exception();
    }
    int result = d_elements[d_head];
    d_elements[d_head++] = 0;
    d_head %= d_capacity;
    --d_size;

    return result;
}

size_t CircularQueue::size() const
{
    return d_size;
}

void CircularQueue::print() const
{
    for (int i = 0; i < d_capacity; ++i) {
        std::cout << d_elements[i] << " ";
    }
    std::cout << std::endl;
}
