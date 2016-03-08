#ifndef LL_LIST_CPP
#define LL_LIST_CPP

#include "ll_list.h"

namespace ll {

template <class T>
LinkedList<T>::LinkedList()
: d_head(NULL)
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
    Node<T> *node = new Node<T>;
    node->d_val = val;
    node->d_next = d_head;
    d_head = node;
}

template <class T>
void LinkedList<T>::remove(const T& val)
{
    while (d_head && d_head->d_val == val) {
        Node<T> *tmp = d_head;
        d_head = d_head->d_next;
        delete tmp;
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

}

#endif
