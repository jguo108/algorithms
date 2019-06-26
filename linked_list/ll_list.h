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

    Node(const T& val, struct Node<T> *next = NULL);
};


                              // ================
                              // class LinkedList 
                              // ================

template <class T>
class LinkedList {
  private:
    Node<T> *d_head;
    Node<T> *d_tail;
    int      d_size;

  private:
    Node<T>** reverse(Node<T> *list);

  public:
    // CREATORS
    LinkedList();

    ~LinkedList();

    // MANIPULATORS
    void insert(const T& val);

    void insert(Node<T> *node);

    void add(const T& val);

    void add(Node<T> *node);

    Node<T>* find(const T& val);

    void remove(const T& val);

    void reverse();

    void r_reverse();
        // Recursive reverse

    // ACCESSORS
    int size() const;

    void print() const;

    // =============== Exercises ==================
    // EPI, Problem 8.1, Page 102
    friend LinkedList<T> mergeSortedLists(LinkedList<T>& ll1, 
                                          LinkedList<T>& ll2)
    {
        LinkedList<T> result;

        Node<T>* cur1 = ll1.d_head;
        Node<T>* cur2 = ll2.d_head;
        Node<T>* tmp;

        ll1.d_head = NULL;
        ll2.d_head = NULL;

        while (cur1 != NULL && cur2 != NULL) {
            if (cur1->d_val < cur2->d_val) {
                result.add(cur1);
                tmp = cur1->d_next;
                cur1->d_next = NULL;
                cur1 = tmp;
            } else {
                result.add(cur2);
                tmp = cur2->d_next;
                cur2->d_next = NULL;
                cur2 = tmp;
            }
        }
        if (cur1 != NULL) {
            result.add(cur1);
        }

        if (cur2 != NULL) {
            result.add(cur2);
        }

        return result;
    }

    // EPI, Problem 8.2, Page 103 (STAR)
    void reverseSublist(int begin, int end);
    
    // EPI, Problem 8.3, Page 104
    Node<T>* testForCycle();

    // EPI, Problem 8.4, Page 106 
    friend Node<T>* testForOverlapping(LinkedList<T>& ll1, 
                                       LinkedList<T>& ll2)
    {
        return NULL;
    }

    // EPI, Problem 8.5, Page 107
    friend Node<T>* testForOverlappingWithCycle(LinkedList<T>& ll1, 
                                                LinkedList<T>& ll2)
    {
        // Difficult. Need to revisit.
        return NULL;
    }

    // EPI, Problem 8.6, Page 109 
    void deleteNode(Node<T> *node);

    // EPI, Problem 8.7, Page 109
    void removeKthLastNode(int k);

    // EPI, Problem 8.8, Page 110
    void removeDuplicates();

    // EPI, Problem 8.9, Page 111
    void rightShift(int k);

    // EPI, Problem 8.10, Page 112
    void evenOddMerge();

    // EPI, Problem 8.11, Page 113
    bool isPalindromic();

    // EPI, Problem 8.12, Page 114
    void pivoting(const T& k);

    // EPI, Problem 8.13, Page 115
    friend LinkedList<T> addListBasedIntegers(LinkedList<T>& num1, 
                                              LinkedList<T>& num2)
    {
        LinkedList<T> result;
        Node<T> *iter1 = num1.d_head;
        Node<T> *iter2 = num2.d_head;

        int carry = 0;
        while (iter1 != NULL && iter2 != NULL) {
            int sum = iter1->d_val + iter2->d_val + carry;
            int digit = sum % 10;
            result.add(digit);
            carry = sum / 10;
            iter1 = iter1->d_next;
            iter2 = iter2->d_next;
        }
        Node<T> *remaining = NULL;
        if (iter1 != NULL) {
            remaining = iter1;
        } else if (iter2 != NULL) {
            remaining = iter2;
        } else {
            if (carry) {
                result.add(1);
            }
            return result;
        }

        while (remaining != NULL) {
            int sum = remaining->d_val + carry;
            int digit = sum % 10;
            result.add(digit);
            remaining = remaining->d_next;
        }
        if (carry) {
            result.add(1);
        }

        return result;
    }
};

// =============================================================================
//                               INLINE FUNCTIONS
// =============================================================================


} // namespace ll

#include "ll_list.cpp"

#endif

