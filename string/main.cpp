#include <iostream>
#include <vector>


int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: a.out case" << std::endl;
        return -1;
    }

    long testCase = strtol(argv[1], NULL, 0);

    switch (testCase) {
        case 1: { // 
        } break;
        default: {
            std::cerr << "Unknown test case" << std::endl;
        } break;

    }

    return 0;
}

