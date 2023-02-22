#include <stack>
#include <stdexcept>

using namespace std;

class QueueWithTwoStacks 
{
  public:
    int pop();
    void push(int value);
    int front();

  private:
    bool isEmpty() {
        return d_in.empty() && d_out.empty();
    }

    void shuffle() {
        if (!d_out.empty()) {
            return;
        }
        while (!d_in.empty()) {
            d_out.push(d_in.top());
            d_in.pop();
        }
    }

  private:
    stack<int> d_in;
    stack<int> d_out;
};

int QueueWithTwoStacks::pop()
{
    if (isEmpty()) {
        throw std::runtime_error("queue is empty");
    }
    shuffle();
    int value = d_out.top();
    d_out.pop();
    return value;
}

void QueueWithTwoStacks::push(int value)
{
    d_in.push(value);
}

int QueueWithTwoStacks::front()
{
    if (isEmpty()) {
        throw std::runtime_error("queue is empty");
    }
    shuffle();
    return d_out.top();
}