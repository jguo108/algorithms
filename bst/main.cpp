#include <iostream>
#include <vector>
#include <cstdlib>

#include "bst_tree.h"
#include "bst_util.h"

void populateTree(bst::BinarySearchTree *tree, const std::vector<int>& values)
{
    for (auto v : values) {
        tree->insert(v);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: a.out case" << std::endl;
        return -1;
    }

    long testCase = strtol(argv[1], NULL, 0);
    bst::BinarySearchTree tree;

    switch (testCase) {

        case 1: { // Print tree
            std::vector<int> values = {4, 2, 6, 1, 3, 5, 7};
            populateTree(&tree, values);
            bst::BSTUtil::printBST(tree, 1, 0, std::cout);
        } break;

        case 2: { // Find min value
            std::vector<int> values = {4, 2, 6, 1, 3, 5, 7};
            populateTree(&tree, values);
            std::cout << "Min value is: " << tree.minValue() << std::endl;
        } break;

        default: {
            std::cerr << "Unknown test case" << std::endl;
        } break;

    }

    return 0;
}
