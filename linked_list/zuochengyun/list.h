#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int          d_val; 

    struct Node *d_next;

    Node(int val, struct Node *next = nullptr);
};

Node::Node(int val, struct Node *next)
: d_val(val)
, d_next(next)
{
}

class LinkedList {
  private:
    Node   *d_head;
    Node   *d_tail;
    size_t  d_size;

  private:
    // Helper function to reverse a list pointed to by
    // head and tail. After the function returns, head
    // and tail point to the reverse head and tail.
    void reverse(Node **head, Node **tail);

  public:
    LinkedList();
    ~LinkedList();
    LinkedList(const vector<int>& array);
 
    void print();
    void print(size_t num);
    void push_front(Node *node);
    void push_back(Node *node);
    size_t size() const { return d_size; }

    void reverse();
    void reverse_from_to(size_t from, size_t to);
    void reverse(size_t k); // reverse every k element

    bool is_plindrome();

    void selection_sort();

    void make_circle() { d_tail->d_next = d_head; }
    void insert_into_sorted(int num);

    void left_right_merge();
};

LinkedList::LinkedList()
: d_head(nullptr)
, d_tail(nullptr)
, d_size(0)
{
}

LinkedList::LinkedList(const vector<int>& array)
: d_head(nullptr)
, d_tail(nullptr)
, d_size(0)
{
    for (auto i : array) {
        Node *node = new Node(i);
        push_back(node);
    }
}

LinkedList::~LinkedList()
{
    size_t count = 0;
    Node *cur = d_head;
    while (count < d_size) {
        Node *next = cur->d_next;
        delete cur;
        cur = next;
        ++count;
    }
}

void LinkedList::print(size_t num) 
{
    if (num > d_size) {
        return;
    } 
    std::cout << "List: ";

    Node *cur = d_head;
    size_t count = 0;
    while (count < num) {
        std::cout << cur->d_val << " ";
        cur = cur->d_next;
        ++count;
    }
    std::cout << "\n";
}

void LinkedList::print() 
{
    std::cout << "List: ";

    Node *cur = d_head;
    while (cur) {
        std::cout << cur->d_val << " ";
        cur = cur->d_next;
    }

    std::cout << "\n";
}

void LinkedList::push_front(Node *node)
{
    node->d_next = d_head;
    d_head = node;
    if (d_tail == NULL) {
        d_tail = node;
    }
    ++d_size;
}

void LinkedList::push_back(Node *node)
{
    if (d_size == 0) {
        d_head = node;
        d_tail = node;
        ++d_size;
        return;
    }

    d_tail->d_next = node;
    d_tail = node;
    node->d_next = nullptr;
    ++d_size;
}

void LinkedList::reverse(Node **head, Node **tail)
{
    Node *old_tail = *tail;
    *tail = *head;

    Node *new_head = nullptr;
    Node *cur = *head;
    while (cur != old_tail) {
        Node *next = cur->d_next;
        cur->d_next = new_head; 
        new_head = cur;
        cur = next;
    }
    cur->d_next = new_head;
    *head = cur;
}

void LinkedList::reverse()
{
    /*
    Node *cur = d_head;
    Node *new_head = nullptr;

    while (cur != nullptr) {
        Node *next = cur->d_next;
        cur->d_next = new_head;
        new_head = cur;
        cur = next;
    }
    d_head = new_head;
    */
   reverse(&d_head, &d_tail);
}

void LinkedList::reverse_from_to(size_t from, size_t to)
{
    if (from < 1 || from > d_size || from > to) {
        return;
    }

    size_t index = 1;
    Node *cur = d_head;
    Node *before_from_node = nullptr;
    Node *after_to_node = nullptr;
    Node *new_head = nullptr;
    Node *new_tail = nullptr;

    while (cur != nullptr) {
        if (index == from - 1) { // found the one just before "from" node
            before_from_node = cur;
            new_tail = cur->d_next;
            cur = cur->d_next;
        } else if (index >= from && index <= to) { // found "from" node
            after_to_node = cur->d_next;
            cur->d_next = new_head;
            new_head = cur;
            cur = after_to_node;
        } else {
            cur = cur->d_next;
        }
        ++index;
    }
    if (from == 1) {
        new_tail = d_head;
        d_head = new_head;
    } else {
        before_from_node->d_next = new_head;
    }
    if (to == d_size) {
        d_tail = new_tail;
    }
    new_tail->d_next = after_to_node;
}

void LinkedList::reverse(size_t k)
{
    if (d_size < k) {
        return;
    }

    size_t elements_to_reverse = d_size - d_size % k;
    size_t index = 0;

    Node *cur = d_head;
    Node *new_head = nullptr;
    Node *previous_segment_tail = nullptr;
    Node *old_previous_segment_tail = nullptr;

    while (cur != nullptr) {
        // if this is the first element in a segment
        if (index % k == 0) {
            old_previous_segment_tail = previous_segment_tail;
            previous_segment_tail = cur;
            new_head = nullptr;
        }

        // if this is the last element in a segment
        if (index % k == (k - 1)) {
            // if this is the first segment
            if (index / k == 0) {
                d_head = cur;
            }
            if (old_previous_segment_tail != nullptr) {
                old_previous_segment_tail->d_next = cur;
            }
        }

        Node *next = cur->d_next;
        cur->d_next = new_head;
        new_head = cur;
        cur = next;
        ++index;
        if (index >= elements_to_reverse) {
            break;
        }
    }

    previous_segment_tail->d_next = cur;
    if (cur == nullptr) {
        d_tail = previous_segment_tail;
    }
}

bool LinkedList::is_plindrome()
{
    // Reverse the second half, compare and revsere it back.
    return true; 
}

void LinkedList::selection_sort()
{
    Node *sorted_list = nullptr;
    Node dummy(0);
    dummy.d_next = d_head;

    while (dummy.d_next != nullptr) {
        Node *max_node = nullptr;
        int max_val = -1;
        Node *max_prev = nullptr;

        Node *iter = &dummy;
        while (iter->d_next != nullptr) {
            if (iter->d_next->d_val > max_val) {
                max_node = iter->d_next;
                max_val = iter->d_next->d_val;
                max_prev = iter;
            }
            iter = iter->d_next;
        }

        max_prev->d_next = max_node->d_next;
        max_node->d_next = sorted_list;
        sorted_list = max_node;
    }
    d_head = sorted_list;
}

void LinkedList::insert_into_sorted(int num)
{
    Node *new_node = new Node(num);
    ++d_size;

    if (d_head == nullptr) {
        d_head = new_node;
        new_node->d_next = d_head;
        return;
    }

    Node *prev = d_head;
    Node *next = d_head->d_next;
    while (next != d_head) {
        if (prev->d_val <= num && num <= next->d_val) {
            new_node->d_next = next;
            prev->d_next = new_node;
            break;
        }
        prev = next;
        next = next->d_next;
    }

    if (next == d_head) {
        new_node->d_next = next;
        prev->d_next = new_node;
        if (num < d_head->d_val) {
            d_head = new_node;
        }
    }
}

void LinkedList::left_right_merge()
{
    if (d_size <= 3) {
        return;
    }

    size_t steps = d_size / 2;

    Node *right_list = d_head;
    while (steps > 0) {
        right_list = right_list->d_next;
        --steps;
    }
    Node *left_list = d_head;

    size_t count = 0;
    while (count < d_size / 2) {
        Node *left_next = left_list->d_next;
        Node *right_next = right_list->d_next;
        left_list->d_next = right_list;
        right_list->d_next = left_next;
        left_list = left_next;
        right_list = right_next; 
        ++count;
    }
}