#include <iostream>
#include "min_stack.h"
#include "queue_with_two_stacks.h"
#include "stack_reverser.h"
#include "max_in_window.h"

using namespace std;

void print_stack(const stack<int>& st)
{
    stack<int> stack_copy(st);
    while (!stack_copy.empty()) {
        int value = stack_copy.top();
        stack_copy.pop();
        cout << value << endl;
    }
}

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "Usage: a.out case" << std::endl;
        return -1;
    }

    long testCase = strtol(argv[1], NULL, 0);

    switch (testCase) {
        case 1: { // 设计一个有getMin功能的栈
          MinStack minStack;
          minStack.push(1);
          cout << "current min:" << minStack.getMin() << endl;
          minStack.push(2);
          cout << "current min:" << minStack.getMin() << endl;
          minStack.push(3);
          cout << "current min:" << minStack.getMin() << endl;
          minStack.push(4);
          cout << "current min:" << minStack.getMin() << endl;
          minStack.push(0);
          cout << "current min:" << minStack.getMin() << endl;
        } break;
       case 2: { // 由两个栈组成的堆
          QueueWithTwoStacks stack;
          stack.push(1);
          stack.push(2);
          stack.push(3);
          stack.push(4);
          cout << stack.pop() << endl;
          cout << stack.pop() << endl;
          stack.push(5);
          stack.push(6);
          cout << stack.pop() << endl;
          cout << stack.pop() << endl;
          cout << stack.pop() << endl;
          cout << stack.pop() << endl;
        } break;
        case 3: { // 如何仅用递归函数和栈操作逆序一个栈
          stack<int> stack;
          stack.push(1);
          stack.push(2);
          stack.push(3);
          stack.push(4);
          stack.push(5);
          print_stack(stack);
          cout << "======================" << endl;
          StackReverser reverser;
          reverser.reverse(stack);
          print_stack(stack);
        } break;
        case 4: { // 生成窗口最大数组
          auto array = {4, 3, 5, 4, 3, 3, 6, 7};
          size_t windowSize = 3;
          auto result = findMaxInWindow(array, windowSize);
          for (auto i : result) {
              cout << i << " ";
          }
          cout << "======================" << endl;
          cout << endl;

        } break;
        default: {
            std::cerr << "Unknown test case" << std::endl;
        } break;
    }


    return 0;
}