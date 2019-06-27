#include <iostream>
#include <vector>

#include "stack.h"
#include "exercise.h"
#include "util.h"
#include "circular_queue.h"
#include "queue.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: a.out case" << std::endl;
        return -1;
    }

    long testCase = strtol(argv[1], NULL, 0);

    switch (testCase) {

        case 1: { // Max API
            Stack s;
            s.push(4);
            s.push(5);
            s.push(0);
            s.push(9);
            s.push(8);
            s.print();
            std::cout << "max is: " << s.max() << std::endl;
            s.pop();
            std::cout << "max is: " << s.max() << std::endl;
            s.pop();
            std::cout << "max is: " << s.max() << std::endl;
            s.pop();
            std::cout << "max is: " << s.max() << std::endl;
            s.pop();
            std::cout << "max is: " << s.max() << std::endl;
            s.pop();
        } break;
        case 2: { // RPN expression
            std::vector<std::string> expression = { "3", "4", "+", "2", "*", "1", "+" }; 
            std::cout << "Evaluation result is: "
                      << Exercise::RPNExpression(expression) << std::endl;
        } break;
        case 3: { // Test well formedness
            std::cout << "Not implemented" << std::endl;
        } break;
        case 4: { // Normalize path name
            std::cout << "Not implemented" << std::endl;
        } break;
        case 5: { // Search posting list
            std::cout << "Not implemented" << std::endl;
        } break;
        case 6: { // Sunset view
            std::vector<int> buildings = { 4, 6, 8, 3, 5, 10, 7, 20 };
            std::vector<int> buildingsWithSunsetView = Exercise::sunsetViewEastToWest(buildings);
            Util::print(buildingsWithSunsetView);
        } break;
        case 7: { // BFS using queue
            std::cout << "Not implemented" << std::endl;
        } break;
        case 8: { // Circular queue
            CircularQueue q(5);
            q.enqueue(1);
            q.enqueue(2);
            q.enqueue(3);
            q.enqueue(4);
            q.enqueue(5);
            q.enqueue(6);
            q.dequeue();
            q.dequeue();
            q.dequeue();
            q.enqueue(10);
            q.enqueue(11);
            q.enqueue(12);
            q.enqueue(13);
            q.enqueue(14);
            q.enqueue(15);
            q.enqueue(16);
            q.print();
            q.enqueue(17);
            q.print();
        } break;
        case 9: { // Queue using stack
            std::cout << "Not implemented" << std::endl;
        } break;
        case 10: { // Circular queue
            Queue q;
            q.enqueue(4);
            q.enqueue(2);
            q.enqueue(18);
            q.enqueue(0);
            q.enqueue(10);
            q.enqueue(8);
            q.enqueue(1);

            q.print();
            std::cout << "Max is: " << q.max() << std::endl;

            q.dequeue();
            q.print();
            std::cout << "Max is: " << q.max() << std::endl;

            q.dequeue();
            q.print();
            std::cout << "Max is: " << q.max() << std::endl;

            q.dequeue();
            q.print();
            std::cout << "Max is: " << q.max() << std::endl;

            q.dequeue();
            q.print();
            std::cout << "Max is: " << q.max() << std::endl;

            q.dequeue();
            q.print();
            std::cout << "Max is: " << q.max() << std::endl;

            q.dequeue();
            q.print();
            std::cout << "Max is: " << q.max() << std::endl;


        } break;
        default: {
            std::cerr << "Unknown test case" << std::endl;
        } break;
    }

    return 0;
}

