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
    if (!d_head) {
        return;
    }

    if (d_head->d_val == val) {
        Node<T> *next = d_head->d_next;
        delete d_head;
        d_head = next;
        return;
    }

    Node<T> *cur  = d_head;
    Node<T> *next = d_head->d_next;

    while (next) {
        if (next->d_val == val) {
            cur->d_next = next->d_next;
            delete next;
            next = cur->d_next;
        } else {
            cur = next;
            next = cur->d_next;
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
