#include <iostream>
#include <vector>

#include "util.h"
#include "exercise.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: a.out case" << std::endl;
        return -1;
    }

    long testCase = strtol(argv[1], NULL, 0);

    switch (testCase) {

        case 1: { // Dutch flag 
            std::vector<int> input = { 4, 7, 10, 4, 0, 12, -1, 4, 4, 15, 34, 4, 0};

            Util::print(input);
            Exercise::dutchFlag(input, 3);
            Util::print(input);
        } break;
        case 2: { // Increment by One 
            std::vector<int> input = { 9, 9, 9 }; 

            Util::print(input);
            Exercise::integerPlusOne(input);
            Util::print(input);
        } break;
        case 3: { // Multiply two integers
            std::cerr << "Integer multiplication is not implemented!" << std::endl;
        } break;
        case 4: { // Increment by One 
            std::vector<int> input = { 3, 2, 0, 0, 2, 0, 1 }; 
            Util::print(input);
            std::cout << "Possible to advance through: "
                      << Exercise::advanceThroughArray(input) << std::endl;
        } break;
        case 5: { // Delete repeated elements 
            std::vector<int> input = { 2, 2, 2, 3, 5, 5, 7, 11, 11, 11, 13, 13, 13 }; 

            Util::print(input);
            Exercise::deleteRepeatedElementsInSortedArray(input);
            Util::print(input);
        } break;
        case 6: { // Buy and sell stock once
            std::vector<int> input = { 310, 315, 275, 295, 260, 270, 290, 230, 255, 250 };

            Util::print(input);
            std::cout << "Max profit is: "
                      << Exercise::buyAndSellStockOnce(input) << std::endl;
        } break;
        case 7: { // Buy and sell stock twice
            std::cerr << "Buy and sell stock twice is not implemented!" << std::endl;
        } break;
        case 8: { // Enumerate all primes 
            std::vector<int> result = Exercise::enumerateAllPrimes(18);
            Util::print(result);
        } break;
        case 9: { // Permuate array 
            std::vector<char> input = { 'a', 'b', 'c', 'd' };
            std::vector<int> permutation = { 2, 0, 1, 3 };
            Exercise::permuteArray(input, permutation);
            Util::print(input);
        } break;
        case 10: { // Next permutation 
            std::vector<int> input = { 6, 2, 1, 5, 4, 3, 0 };
            Util::print(input);
            Exercise::nextPermutation(input);
            Util::print(input);
        } break;
        default: {
            std::cerr << "Unknown test case" << std::endl;
        } break;

    }

    return 0;
}

