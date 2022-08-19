#include "lc_list.h"
#include <iostream>

namespace lc {

Node::Node(int val, struct Node *next)
: d_val(val)
, d_next(next)
{
}

LinkedList::LinkedList()
: d_head(NULL)
, d_tail(NULL)
, d_size(0)
{
}

LinkedList::~LinkedList()
{
    Node *cur = d_head;
    while (cur) {
        Node *next = cur->d_next;
        delete cur;
        cur = next;
    }
}

void LinkedList::insert(int val)
{
    Node *node = new Node(val, d_head);
    d_head = node;
    if (d_tail == NULL) {
        d_tail = node;
    }
    ++d_size;
}

void LinkedList::insert(Node *node)
{
    node->d_next = d_head;
    d_head = node;
    if (d_tail == NULL) {
        d_tail = node;
    }
    ++d_size;
}

void LinkedList::append(int val)
{
    Node *node = new Node(val);
    append(node);
}

void LinkedList::append(Node *node)
{
    if (d_size == 0) {
        d_head = node;
        d_tail = node;
        ++d_size;
        return;
    }

    d_tail->d_next = node;
    d_tail = node;
    node->d_next = NULL;
    ++d_size;
}

void LinkedList::add(int val)
{
    Node *node = new Node(val);
    if(d_tail != NULL) {
        d_tail->d_next = node;
    } else {
        d_head = node;
    }
    d_tail = node;
    ++d_size;
}

void LinkedList::add(Node *node)
{
    if(d_tail != NULL) {
        d_tail->d_next = node;
    } else {
        d_head = node;
    }
    d_tail = node;
    ++d_size;
}

void LinkedList::remove(int val)
{
    while (d_head && d_head->d_val == val) {
        Node *tmp = d_head;
        d_head = d_head->d_next;
        delete tmp;
        --d_size;
    }

    if (!d_head) {
        return;
    }

    Node *pre = d_head;
    Node *cur = pre->d_next;
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

Node* LinkedList::find(int val)
{
    Node *cur = d_head;
    while (cur) {
        if (cur->d_val == val) {
            return cur;
        }
        cur = cur->d_next;
    }
    return NULL;
}

void LinkedList::print() const
{
    std::cout << "List: ";

    Node *cur = d_head;
    while (cur) {
        std::cout << cur->d_val << " ";
        cur = cur->d_next;
    }

    std::cout << "\n";
}

void LinkedList::reverse()
{
    if (d_head == NULL) {
        return;
    }

    Node *cur = d_head;
    d_head = NULL;
    Node *next = cur->d_next;
    while (next != NULL) {
        cur->d_next = d_head;
        d_head = cur;
        cur = next;
        next = cur->d_next;
    }
    cur->d_next = d_head;
    d_head = cur;
}

void LinkedList::reverse_ii(int l, int r)
{
    Node *left_node, *right_node, *before_left_node, *after_right_node;
    int index = 1;
    Node *ptr = d_head;
    while (ptr != NULL) {
        if (index == l - 1) {
            before_left_node = ptr;
            break;
        } 
        ptr = ptr->d_next;
        ++index;
    }

    left_node = before_left_node->d_next;
    Node *ptr = left_node;
    Node *new_head = NULL;
    int num_of_links = r - l;
    int i = 0;
    while (i < num_of_links) {
        Node *next = ptr->d_next;
        ptr->d_next = new_head;
        new_head = ptr;
        ptr = next;
        ++i;
    }


}

void LinkedList::r_reverse_helper(Node *cur, Node **tail)
{
    if (cur->d_next == NULL) {
        d_head = cur;
        *tail = cur;
        return;
    }

    r_reverse_helper(cur->d_next, tail);

    (*tail)->d_next = cur;
    cur->d_next = NULL;
    *tail = cur; 
}

void LinkedList::r_reverse()
{
    if (d_head == NULL) {
        return;
    }
    Node *tail = NULL;
    r_reverse_helper(d_head, &tail);
}

void LinkedList::reverse_k_group(int k)
{
    if (k == 1) {
        return;
    }

    Node *cur = d_head;
    int count = 0;

    Node *segment_head = NULL, *segment_tail = NULL;
    Node *previous_segment_tail = NULL;
    int segment_num = 0;
    int total_num_of_segments = d_size / k;

    while (cur != NULL) {
        if (segment_num == total_num_of_segments) {
            break;
        }
        ++count;
        if (count > k) {
            if (previous_segment_tail != NULL) {
                previous_segment_tail->d_next = segment_head;
            }
            previous_segment_tail = segment_tail;
            if (segment_num == 0) {
                d_head = segment_head;
            }
            ++segment_num;
            count = 0;
        } else {
            if (count == 1) {
                segment_tail = cur;
            }
            Node *next = cur->d_next;
            cur->d_next = segment_head; 
            segment_head = cur;
            cur = next; 
        }
    }
    segment_tail->d_next = cur;
}

LinkedList* merge_sorted_list(LinkedList *list1, LinkedList *list2)
{
    LinkedList *result = new LinkedList();
    Node *ptr1 = list1->d_head;
    Node *ptr2 = list2->d_head;
    Node *next;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->d_val < ptr2->d_val) {
            next = ptr1->d_next;
            result->append(ptr1);
            ptr1 = next;
        } else {
            next = ptr2->d_next;
            result->append(ptr2);
            ptr2 = next;
        }
    }

    while (ptr1 != NULL) {
        next = ptr1->d_next;
        result->append(ptr1);
        ptr1 = next;
    }

    while (ptr2 != NULL) {
        next = ptr2->d_next;
        result->append(ptr2);
        ptr2 = next;
    }

    return result;
}

// ======================== Exercise =========================


} // Close of namespace 'lc'
























