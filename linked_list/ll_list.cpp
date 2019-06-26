#ifndef LL_LIST_CPP
#define LL_LIST_CPP

#include "ll_list.h"

namespace ll {

template <class T>
Node<T>::Node(const T& val, struct Node<T> *next)
: d_val(val)
, d_next(next)
{
}

template <class T>
LinkedList<T>::LinkedList()
: d_head(NULL)
, d_tail(NULL)
, d_size(0)
{
}

template <class T>
LinkedList<T>::~LinkedList()
{
    Node<T> *cur = d_head;
    while (cur) {
        Node<T> *next = cur->d_next;
        delete cur;
        cur = next;
    }
}

template <class T>
void LinkedList<T>::insert(const T& val)
{
    Node<T> *node = new Node<T>(val, d_head);
    d_head = node;
    if (d_tail == NULL) {
        d_tail = node;
    }
    ++d_size;
}

template <class T>
void LinkedList<T>::insert(Node<T> *node)
{
    node->d_next = d_head;
    d_head = node;
    if (d_tail == NULL) {
        d_tail = node;
    }
    ++d_size;
}

template <class T>
void LinkedList<T>::add(const T& val)
{
    Node<T> *node = new Node<T>(val);
    if(d_tail != NULL) {
        d_tail->d_next = node;
    } else {
        d_head = node;
    }
    d_tail = node;
    ++d_size;
}

template <class T>
void LinkedList<T>::add(Node<T> *node)
{
    if(d_tail != NULL) {
        d_tail->d_next = node;
    } else {
        d_head = node;
    }
    d_tail = node;
    ++d_size;
}

template <class T>
void LinkedList<T>::remove(const T& val)
{
    while (d_head && d_head->d_val == val) {
        Node<T> *tmp = d_head;
        d_head = d_head->d_next;
        delete tmp;
        --d_size;
    }

    if (!d_head) {
        return;
    }

    Node<T> *pre = d_head;
    Node<T> *cur = pre->d_next;
    while (cur) {
        if (cur->d_val == val) {
            pre->d_next = cur->d_next;
            delete cur;
            cur = pre->d_next;
            --d_size;
        } else {
            pre = cur;
            cur = cur->d_next;
        }
    }
}

template <class T>
Node<T>* LinkedList<T>::find(const T& val)
{
    Node<T> *cur = d_head;
    while (cur) {
        if (cur->d_val == val) {
            return cur;
        }
        cur = cur->d_next;
    }
    return NULL;
}

template <class T>
void LinkedList<T>::reverse()
{
    Node<T> *next;
    Node<T> *newHead = NULL;

    while (d_head) {
        next = d_head->d_next;
        d_head->d_next = newHead;
        newHead = d_head;
        d_head = next;
    }
    d_head = newHead;
}

template <class T>
Node<T>** LinkedList<T>::reverse(Node<T> *list)
{
    if (!list->d_next) {
        d_head = list;
        return &list->d_next;
    }
    Node<T> **nextPtr = reverse(list->d_next);
    *nextPtr = list;
    list->d_next = NULL;
    return &list->d_next;
}

template <class T>
void LinkedList<T>::r_reverse()
{
    if (!d_head) {
        return;
    }
    reverse(d_head);
}

template <class T>
void LinkedList<T>::print() const
{
    std::cout << "List: ";

    Node<T> *cur = d_head;
    while (cur) {
        std::cout << cur->d_val << " ";
        cur = cur->d_next;
    }

    std::cout << "\n";
}

// ======================== Exercise =========================
template <class T>
void LinkedList<T>::reverseSublist(int begin, int end)
{
    if (begin > end || end >= d_size) {
        return;
    }

    T t;
    Node<T> sentinel(t, d_head); 
    Node<T> *beforeBegin = &sentinel;

    for (int i = 0; i <= begin - 1; ++i) {
        beforeBegin = beforeBegin->d_next;
    }

    Node<T> *sublistHead = NULL;
    Node<T> *iter = beforeBegin->d_next;
    Node<T> *sublistTail = iter; 
    Node<T> *next;
    for (int i = 0; i <= end - begin; ++i) {
        next = iter->d_next;
        iter->d_next = sublistHead;
        sublistHead = iter;
        iter = next;
    }
    sublistTail->d_next = next;
    beforeBegin->d_next = sublistHead;
    if (&sentinel == beforeBegin) {
        d_head = sublistHead;
    }
    if (sublistTail->d_next == NULL) {
        d_tail = sublistTail;
    }
}

template <class T>
void LinkedList<T>::removeKthLastNode(int k)
{
    Node<T> *iter1 = d_head;
    Node<T> *iter2 = d_head;

    for (int i = 0; i < k; ++i) {
        if (iter2 != NULL) {
            iter2 = iter2->d_next;
        } else {
            return;
        }
    }

    while (iter2->d_next != NULL) {
        iter2 = iter2->d_next;
        iter1 = iter1->d_next;
    }

    Node<T> *victim = iter1->d_next;
    iter1->d_next = victim->d_next;
    delete victim;
}

template <class T>
void LinkedList<T>::removeDuplicates()
{
    if (d_size <= 1) {
        return;
    }

    Node<T> *iter1 = d_head;
    Node<T> *iter2 = d_head->d_next;
    while (iter2 != NULL) {
        if (iter1->d_val == iter2->d_val) {
            iter1->d_next = iter2->d_next;
            delete iter2;
            iter2 = iter1->d_next;
        } else {
            iter1 = iter1->d_next;
            iter2 = iter2->d_next;
        }
    }
}

template <class T>
void LinkedList<T>::rightShift(int k)
{
    k = k % d_size;

    if (k == d_size) {
        return;
    }

    int leftSize = d_size - k;

    Node<T> *newTail = d_head;
    for (int i = 0; i < leftSize - 1; ++i) {
        newTail = newTail->d_next;
    }

    d_tail->d_next = d_head;
    d_head = newTail->d_next;
    d_tail = newTail;
    d_tail->d_next = NULL;
}

template <class T>
void LinkedList<T>::evenOddMerge()
{
    if (d_size <= 2) {
        return;
    }

    Node<T> *evenIter = d_head; 
    Node<T> *oddIter = d_head->d_next; 
    Node<T> *oddHead = oddIter;
    Node<T> *iter = oddIter->d_next; 

    while (iter != NULL) {
        evenIter->d_next = iter;
        evenIter = iter;
        iter = iter->d_next;
        if (iter != NULL) {
            oddIter->d_next = iter;
            oddIter = iter;
            iter = iter->d_next;
        }
    }
    evenIter->d_next = oddHead;
    oddIter->d_next = NULL;
}

template<class T>
bool LinkedList<T>::isPalindromic()
{
    if (d_size == 1) {

        return true;
    }

    int halfSize = d_size / 2;

    Node<T> *firstHalf = NULL;
    Node<T> *secondHalf = d_head;
    Node<T> *next;
    for (int i = 0; i < halfSize; ++i) {
        next = secondHalf->d_next;
        secondHalf->d_next = firstHalf;
        firstHalf = secondHalf;
        secondHalf = next;
    }

    if (d_size % 2) {
        secondHalf = secondHalf->d_next;
    }

    while (firstHalf != NULL && secondHalf != NULL) {
        if (firstHalf->d_val != secondHalf->d_val) {
            return false;
        }
        firstHalf = firstHalf->d_next;
        secondHalf = secondHalf->d_next;
    }
    return true;
}

template<class T>
void LinkedList<T>::pivoting(const T& k)
{
    Node<T> *lessThanList = NULL;
    Node<T> *lessThanListTail = NULL;
    Node<T> *greaterThanList = NULL;
    Node<T> *greaterThanListTail = NULL;

    Node<T> *cur = d_head;
    Node<T> *next;

    while (cur != NULL) {
        next = cur->d_next;
        if (cur->d_val <= k) {
            if (lessThanList == NULL) {
                lessThanList = lessThanListTail = cur;
            } else {
                lessThanListTail->d_next = cur;
                lessThanListTail = cur;
            }
        } else{
            if (greaterThanList == NULL) {
                greaterThanList = greaterThanListTail = cur;
            } else {
                greaterThanListTail->d_next = cur;
                greaterThanListTail = cur;
            }
        }
        cur->d_next = NULL;
        cur = next;
    }
    lessThanListTail->d_next = greaterThanList;
    d_head = lessThanList;
}

} // Close of namespace 'll'

#endif
























