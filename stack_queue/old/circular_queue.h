#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include <iostream>
#include <vector>

                              // ===================
                              // class CircularQueue 
                              // ===================

class CircularQueue {
  private:
    std::vector<int> d_elements;
    int d_head;
    int d_tail;
    int d_size;
    int d_capacity;

  public:
    // CREATORS
    CircularQueue(int capacity);

    ~CircularQueue();

    // MANIPULATORS
    void enqueue(int elem);

    int dequeue();

    // ACCESSORS 
    size_t size() const;

    void print() const;
};

// ============================================================================
//                               INLINE FUNCTIONS
// ============================================================================


#endif

