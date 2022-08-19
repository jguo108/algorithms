#ifndef LC_LIST_H
#define LC_LIST_H

#include <iostream>

namespace lc {

                                 // ===========
                                 // struct Node
                                 // ===========


struct Node {
    int          d_val; 

    struct Node *d_next;

    Node(int val, struct Node *next = NULL);
};


                              // ================
                              // class LinkedList 
                              // ================

class LinkedList {
  private:
    Node *d_head;
    Node *d_tail;
    int   d_size;

  private:
    void r_reverse_helper(Node *cur, Node **tail);

  public:
    // CREATORS
    LinkedList();

    ~LinkedList();

    // MANIPULATORS
    void insert(int val);

    void insert(Node *node);

    void append(int val);

    void append(Node *node);

    void add(int val);

    void add(Node *node);

    Node* find(int val);

    void remove(int val);


    // ACCESSORS
    int size() const;

    void print() const;

    // =============  Leetcode Exercise =================

    // Leetcode 206
    void reverse();

    // Leetcode 206
    void r_reverse();
        // Recursive reverse

    // Leetcode 92  TODO
    void reverse_ii(int l, int r);

    // Leetcode 25  TODO
    void reverse_k_group(int k);

    // Leetcode 21
    friend LinkedList* merge_sorted_list(LinkedList *list1, LinkedList *list2);
};

// =============================================================================
//                               INLINE FUNCTIONS
// =============================================================================


} // namespace lc

#endif

