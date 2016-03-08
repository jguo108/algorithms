#ifndef LL_LIST_H
#define LL_LIST_H

#include <iostream>

namespace ll {

                                 // ===========
                                 // struct Node
                                 // ===========


template <class T>
struct Node {
    T               d_val; 

    struct Node<T> *d_next;
};


                              // ================
                              // class LinkedList 
                              // ================

template <class T>
class LinkedList {
  private:
    Node<T> *d_head;

  private:
    Node<T>** reverse(Node<T> *list);

  public:
    // CREATORS
    LinkedList();

    ~LinkedList();

    // MANIPULATORS
    void insert(const T& val);

    Node<T>* find(const T& val);

    void remove(const T& val);

    void reverse();

    void r_reverse();

    // ACCESSORS
    void print() const;
};

// =============================================================================
//                               INLINE FUNCTIONS
// =============================================================================
} // namespace ll

#include "ll_list.cpp"

#endif
