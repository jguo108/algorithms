#ifndef LC_MINSTACK_H
#define LC_MINSTACK_H

#include <stack>

namespace lc {

class MinStack
{
  private:
    std::stack<int> d_container;
    std::stack<int> d_min_stack;

  public:
    void push(int val);

    int pop();

    int top();

    int getMin();
};

}

#endif