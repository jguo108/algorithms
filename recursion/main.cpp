#include <iostream>
#include <vector>

#include "util.h"
#include "exercise.h"

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: a.out case" << std::endl;
        return -1;
    }

    long testCase = strtol(argv[1], NULL, 0);

    switch (testCase) {
        case 6: { // Genearte all strings with mathcing parens
            std::vector<std::string> result = Exercise::generateMatchedParens(4);
            Util::print(result);
        } break;
        case 7: { // Generate plindromic decompositions
            vector<vector<string>> result = Exercise::plindromicDecompositions("0204451881");
            Util::print(result);
        } break;
        default: {
            std::cerr << "Unknown test case" << std::endl;
        } break;
    }

    return 0;
}

