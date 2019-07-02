#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <assert.h>

#include "bst_tree.h"
#include "bst_util.h"

using namespace bst;

void populateTree(BinarySearchTree *tree, const std::vector<int>& values)
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
    Node *n3 = new Node(20, NULL, NULL);
    Node *n4 = new Node(70, NULL, NULL);
    Node *n5 = new Node(130, NULL, NULL);
    Node *n6 = new Node(180, NULL, NULL);
    Node *n1 = new Node(50, n3, n4);
    Node *n2 = new Node(150, n5, n6);
    Node *n0 = new Node(100, n1, n2);

    BinarySearchTree tree(n0);

    switch (testCase) {
        case 1: { // Is tree BST 
            tree.print();
            std::cout << "Is BST: " << tree.isBST() << std::endl;
        } break;
        case 2: { // First greater than 
            tree.print();
            int k = 56;
            Node *n = tree.firstGreaterThan(k);
            if (n) {
                std::cout << "First node greater than " << k << ": " << n->value() << std::endl;
            } else {
                std::cout << "No node is greater than " << k << std::endl;
            }
        } break;
        case 3: { // kth largest 
            tree.print();
            for (int k = 0; k <= 8; ++k) {
                Node *n = tree.kthLargest(k);
                if (n) {
                    std::cout << k << "th largest: " << n->value() << std::endl;
                } else {
                    std::cout << "No " << k << "th largest" << std::endl;
                }
            }
        } break;
        case 4: { // LCA 
            tree.print();
            Node *smallerNode = n4;
            Node *largerNode = n6;
            Node *lca = tree.lowestCommonAncester(smallerNode, largerNode);
            std::cout << "LCA of " << smallerNode->value() << " and "
                      << largerNode->value() << " is "
                      << lca->value() << std::endl;
        } break;
        default: {
            std::cerr << "Unknown test case" << std::endl;
        } break;

    }

    return 0;
}
