#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>

                              // ===========
                              // class Stack 
                              // ===========

class Stack {
  private:
    std::vector<int> d_elements;
    std::vector<int> d_maxSoFar;

  public:
    // CREATORS
    Stack();

    ~Stack();

    // MANIPULATORS
    void push(int elem);

    int pop();

    // ACCESSORS 
    int size() const;

    bool empty() const;

    int top() const;

    void print() const;

    int max() const;
      // EPI, Problem 9.1, Page 118 
};

// ============================================================================
//                               INLINE FUNCTIONS
// ============================================================================

inline
void Stack::push(int elem)
{
    if (empty()) {
        d_maxSoFar.push_back(elem);
    } else {
        int newMax = std::max(d_maxSoFar.back(), elem);
        d_maxSoFar.push_back(newMax);
    }
    d_elements.push_back(elem);
}

inline
int Stack::pop()
{
   if (d_elements.empty()) {
       throw std::exception();
   }
   int res = d_elements.back(); 
   d_elements.pop_back();
   d_maxSoFar.pop_back();
   return res;
}

inline
int Stack::size() const
{
    return d_elements.size();
}

inline
bool Stack::empty() const
{
    return d_elements.empty();
}

inline
int Stack::top() const
{
    return d_elements.back();
}

inline
void Stack::print() const
{
    for (int i : d_elements) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

#endif

