#include <iostream>
#include <vector>

// #include "util.h"
#include "exercise.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: a.out case" << std::endl;
        return -1;
    }

    long testCase = strtol(argv[1], NULL, 0);

    switch (testCase) {
        case 1: { // Search for first occrence of k 
            //std::vector<int> array = { -14,  -10, 2, 108, 108, 243, 285, 285, 285, 401 };
            std::vector<int> array = { 108, 108, 108, 243, 285, 285, 285, 401 };
            int target =  108;
            int targetIndex = Exercise::searchFirstOccurence(array, target);
            std::cout << "First occurence of " << target << " is at index " << targetIndex << std::endl;
        } break;
        case 2: { // Search for index equal to element 
            std::vector<int> array = { -2, 0, 3, 4, 6, 7, 9 };
            int result = Exercise::findIndexEqualToElement(array);
            std::cout << "Index where it equals to elment is: " << result << std::endl;
        } break;
        case 3: { // Search cyclically sorted array 
            // std::vector<int> array = { 103, 203, 220, 234, 279, 368, 378, 478, 550, 631 };
            // std::vector<int> array = { 378, 478, 550, 631, 103, 203, 220, 234, 279, 368 };
            // std::vector<int> array = { 368, 378, 478, 550, 631, 103, 203, 220, 234, 279 };
            // std::vector<int> array = { 631, 103, 203, 220, 234, 279, 368, 378, 478, 550 };
            std::vector<int> array = { 203, 220, 234, 279, 368, 378, 478, 550, 631, 103 };
            int result = Exercise::searchCyclicallySortedArray(array);
            std::cout << "Smallest element index is: " << result << ", smallest element is: " << array[result] << std::endl;
        } break;

        default: {
            std::cerr << "Unknown test case" << std::endl;
        } break;
    }

    return 0;
}

