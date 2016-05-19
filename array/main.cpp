
#include <iostream>
#include <vector>

#include "util.h"


int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: a.out case" << std::endl;
        return -1;
    }

    long testCase = strtol(argv[1], NULL, 0);

    switch (testCase) {

        case 1: { // Dutch flag 
            std::vector<int> array = { 4, 7, 10, 4, 0, 12, -1, 4, 4, 15, 34, 4, 0};
            Util::print(array);

            Util::dutchFlag(array, 3);
            Util::print(array);
        } break;
        default: {
            std::cerr << "Unknown test case" << std::endl;
        } break;

    }

    return 0;
}

