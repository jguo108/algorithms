#include <iostream>
#include "lc_questions.h"

using namespace lc;

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: a.out case" << std::endl;
        return -1;
    }

    long testCase = strtol(argv[1], NULL, 0);

    Questions questions;

    switch (testCase) {
        case 3: { // Length of longest substring 
          //std::string input = "abcabcbb";
          //std::string input = "bbbbbb";
          std::string input = "pwwkew";
          std::cout << "longest substring: " << questions.lengthOfLongestSubstring(input) << std::endl; 
        } break;
        default: {
            std::cerr << "Unknown test case" << std::endl;
        } break;
    }

    return 0;
}

