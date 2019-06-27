#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <list>

                              // ===========
                              // class Queue 
                              // ===========

class Queue {
  private:
    std::list<int> d_elements;
    std::list<int> d_maxCandidates;

  public:
    // CREATORS
    Queue();

    ~Queue();

    // MANIPULATORS
    void enqueue(int elem);

    int dequeue();

    // ACCESSORS 
    int max() const;

    size_t size() const;

    void print() const;
};

// ============================================================================
//                               INLINE FUNCTIONS
// ============================================================================


#endif
