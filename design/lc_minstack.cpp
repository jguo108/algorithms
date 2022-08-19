
#include "lc_minstack.h"

namespace lc {

void MinStack::push(int val)
{
    int new_min = val;
    if (!d_container.empty()) {
        int current_min = d_min_stack.top();
        new_min = (val < current_min) ? val : current_min;
    }
    d_container.push(val);
    d_min_stack.push(new_min);
}

int MinStack::pop()
{
    int result = d_container.top();
    d_container.pop();
    d_min_stack.pop();
    return result;
}

int MinStack::top()
{
    return d_container.top(); 
}

int MinStack::getMin()
{
    return d_min_stack.top();
}

}
