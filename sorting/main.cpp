#include <iostream>
#include <vector>

#include "exercise.h"
#include "util.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: a.out case" << std::endl;
        return -1;
    }

    long testCase = strtol(argv[1], NULL, 0);

    switch (testCase) {
        case 1: { // Search for first occrence of k 
            std::vector<int> array1 = { 2, 3, 3, 5, 5, 6, 7, 7, 8, 12 };
            std::vector<int> array2 = { 5, 5, 6, 8, 8,9, 10, 10 };
            std::vector<int> result = Exercise::intersectSortedArrays(array1, array2); 
            Util::print(result);
        } break;
        default: {
            std::cerr << "Unknown test case" << std::endl;
        } break;
    }

    return 0;
}

