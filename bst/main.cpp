#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <assert.h>

#include "bst_tree.h"
#include "bst_util.h"

void populateTree(bst::BinarySearchTree *tree, const std::vector<int>& values)
{
    for (auto& v : values) {
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
        case 3: { // show predecessor and successor 
            std::vector<int> values = {4, 2, 6, 1, 3, 5, 7};
            populateTree(&tree, values);
            bst::BSTUtil::printBST(tree, 1, 0, std::cout);

            bst::Node *node;
            bst::Node *pred;
            bst::Node *succ;
            for (auto& v : values) {
                node = tree.find(v); 
                std::cout << "Predecessor of " << v << ": "
                          << ((pred = node->predecessor())
                                  ? pred->value() : INT_MIN)
                          << std::endl;
                std::cout << "Successor of " << v << ": "
                          << ((succ = node->successor())
                                  ? succ->value() : INT_MIN)
                          << std::endl;
            }
        } break;
        case 4: { // find kth node 
            std::vector<int> values = {4, 2, 6, 1, 3, 5, 7};
            populateTree(&tree, values);
            bst::BSTUtil::printBST(tree, 1, 0, std::cout);

            // sorted order: {1, 2, 3, 4, 5, 6, 7, 8}
            std::sort(values.begin(), values.end());
            bst::Node *node;
            for (size_t k = 0; k < values.size(); ++k) {
                node = tree.findKth(k);
                assert(node != NULL);
                assert(node->value() == values[k]); 
                std::cout << "values[" << k << "]: "
                          << node->value() << std::endl;
            }

            node = tree.findKth(100);
            assert(node == NULL);
        } break;
        case 5: { // Equality
            std::vector<int> values = {4, 2, 6, 1, 3, 5, 7};
            populateTree(&tree, values);
            bst::BSTUtil::printBST(tree, 1, 0, std::cout);

            std::vector<int> values2 = {4, 2, 1, 3, 5, 7};
            bst::BinarySearchTree tree2;
            populateTree(&tree2, values2);
            bst::BSTUtil::printBST(tree2, 1, 0, std::cout);

            std::cout << "Are trees equal: " << (tree == tree2) << std::endl;
        } break;
        case 6: { // Convert to linked list
            std::vector<int> values = {4, 2, 6, 1, 3, 5, 7};
            populateTree(&tree, values);
            bst::BSTUtil::printBST(tree, 1, 0, std::cout);

            tree.toLinkedList();
            tree.printLinkedList();
        } break;
        default: {
            std::cerr << "Unknown test case" << std::endl;
        } break;

    }

    return 0;
}
