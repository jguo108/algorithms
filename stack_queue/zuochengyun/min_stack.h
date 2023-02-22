#include <stdexcept>
#include <stack>

using namespace std;

class MinStack
{
  public:
    int pop();
    void push(int value);
    int getMin();

  private:
    stack<int> d_values;
    stack<int> d_mins;
};

// =================================================================

int MinStack::pop()
{
    if (d_values.empty()) {
        throw std::runtime_error("stack is empty");
    }

    int value = d_values.top();
    d_values.pop();
    d_values.pop();
    return value;
}

void MinStack::push(int value)
{
    if (d_values.empty()) {
        d_values.push(value);
        d_mins.push(value);
        return;
    }
    d_values.push(value);
    int current_min = d_mins.top();
    if (value < current_min) {
        d_mins.push(value);
    } else {
        d_mins.push(current_min);
    }
}

int MinStack::getMin()
{
    if (d_values.empty()) {
        throw std::runtime_error("stack is empty");
    }
    return d_mins.top();
}


