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
        case 7: {
            std::vector<int> values     = {19, 7,  3, 2, 5, 11, 17, 13, 43, 47, 53, 23, 37, 29, 31, 41};
            std::vector<int> successors = {23, 11, 5, 3, 7, 13, 19, 17, 47, 53, -1, 29, 41, 31, 37, 43};
            populateTree(&tree, values);
            bst::BSTUtil::printBST(tree, 1, 0, std::cout);

            for (size_t i = 0; i < values.size(); ++i) {
                bst::Node *node = tree.find(values[i]);
                assert(node != NULL);
                bst::Node *successor = tree.successor(node);
                if (successor) {
                    std::cout << "Node: " << node->value()
                              << " Actual successor: " << successor->value()
                              << " Expected successor: " << successors[i]
                              << std::endl;
                    assert(successor->value() == successors[i]);
                } else {
                    assert(successors[i] == -1);
                }
            }
        } break;
        case 8: { // Build binary tree from sorted array
            std::vector<int> values = {1, 2, 3, 4, 5, 6, 7};
            tree.buildFromInorder(values);
            bst::BSTUtil::printBST(tree, 1, 0, std::cout);
        } break;
        case 9: { // Find node in Min First BST
            std::vector<int> values = {5, 4, 6, 3, 10, 7, 11, 2, 20, 17, 25, 13, 35, 30, 50};
            tree.buildFromInorder(values);
            bst::BSTUtil::printBST(tree, 1, 0, std::cout);

            bst::Node *node = NULL;
            for (const auto& v : values) {
                node = tree.findInMinFirstBST(v);
                assert(node != NULL);
                assert(node->value() == v);
            }

            node = tree.findInMinFirstBST(12);
            assert(node == NULL);
            node = tree.findInMinFirstBST(33);
            assert(node == NULL);
        } break;
        case 10: { // Convert doubly linked list to BST
            std::vector<int> values = {4, 2, 6, 1, 3, 5, 7};
            populateTree(&tree, values);
            bst::BSTUtil::printBST(tree, 1, 0, std::cout);

            tree.toLinkedList();
            tree.printLinkedList();

            tree.toBinarySearchTree();
            bst::BSTUtil::printBST(tree, 1, 0, std::cout);
        } break;
        case 11: { // Get the largest k nodes in the BST
            std::vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
            tree.buildFromInorder(values);
            bst::BSTUtil::printBST(tree, 1, 0, std::cout);

            std::vector<int> nodes;
            tree.getKthLargest(&nodes, 0);
            for (const auto& n : nodes) {
                std::cout << n << " ";
            }
            std::cout << std::endl;
        } break;
        case 12: { // Find the LCA of two nodes
            std::vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
            tree.buildFromInorder(values);
            bst::BSTUtil::printBST(tree, 1, 0, std::cout);

            bst::Node *a = tree.find(3);
            bst::Node *b = tree.find(6);

            const bst::Node *lca = tree.findLCA(a, b);
            assert(lca != NULL);
            std::cout << "LCA of " << a->value() << " and " << b->value()
                      << " is: " << lca->value() << std::endl;

        } break;
        case 13: { // Print inorder with stack
            std::vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
            tree.buildFromInorder(values);
            bst::BSTUtil::printBST(tree, 1, 0, std::cout);

            tree.printInorder();
        } break;
        default: {
            std::cerr << "Unknown test case" << std::endl;
        } break;

    }

    return 0;
}
