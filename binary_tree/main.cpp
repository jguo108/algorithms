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
    BinarySearchTree tree;

    switch (testCase) {
        case 1: { // Is tree height balanced 
            std::vector<int> values = {4, 2, 6, 1, 3, 7};
            populateTree(&tree, values);
            BSTUtil::printBST(tree, 1, 0, std::cout);
            std::cout << "Is tree height balanced: " << tree.isHeightBalanced() << std::endl;
        } break;
        case 2: { // Is tree symmetric
            Node *n3l = new Node(3, NULL, NULL);
            Node *n3r = new Node(3, NULL, NULL);
            Node *n2l = new Node(2, NULL, NULL, NULL, n3l);
            Node *n2r = new Node(2, NULL, NULL, n3r, NULL);
            Node *n120l = new Node(120, NULL, NULL);
            Node *n120r = new Node(120, NULL, NULL);
            Node *n6l = new Node(6, NULL, NULL, n120l, n2l);
            Node *n6r = new Node(6, NULL, NULL, n2r, n120r);
            Node *root = new Node(314, NULL, NULL, n6l, n6r);
            BinarySearchTree t(root);
            BSTUtil::printBST(t, 1, 0, std::cout);
            std::cout << "Is summetric: " << t.isSymmetric() << std::endl;
        } break;
        case 3: { // Lowest common ancester 
            std::vector<int> values = {4, 2, 6, 1, 3, 5, 7};
            populateTree(&tree, values);
            BSTUtil::printBST(tree, 1, 0, std::cout);
            std::cout << "Lowest common anceter is: " << tree.lowestCommonAncester(4, 3) << std::endl;
        } break;
        case 4: { // Lowest common ancester with parent
            std::cerr << "Not implemented" << std::endl;
        } break;
        case 5: { // Sum root to leaf paths 
            std::cerr << "Not tested" << std::endl;
        } break;
        case 6: { // Path with specified sum 
            std::vector<int> values = {4, 2, 6, 1, 3, 5, 7};
            populateTree(&tree, values);
            BSTUtil::printBST(tree, 1, 0, std::cout);
            std::cout << "Path exists for sum: " << tree.pathExistsForSum(16) << std::endl;
        } break;
        case 7: { // Iterative inorder traversal 
            std::vector<int> values = {4, 2, 6, 1, 3, 5, 7};
            populateTree(&tree, values);
            BSTUtil::printBST(tree, 1, 0, std::cout);
            std::cout << "Inorder: ";
            tree.iterativeInorderTraversal();
        } break;
        case 8: { // Iterative preorder traversal 
            std::vector<int> values = {4, 2, 6, 1, 3, 5, 7};
            populateTree(&tree, values);
            BSTUtil::printBST(tree, 1, 0, std::cout);
            std::cout << "Preorder: ";
            tree.iterativePreorderTraversal();
        } break;
        case 9: { // Kth node inroder traversal 
            std::vector<int> values = {4, 2, 6, 1, 3, 5, 7};
            populateTree(&tree, values);
            BSTUtil::printBST(tree, 1, 0, std::cout);
            for (int i = 0 ; i < values.size(); ++i) {
                Node *n = tree.kthNodeInorderTraversal(i);
                std::cout << i << "th node is: " << n->value() << std::endl;
            }
        } break;
        case 10: { // Successor
            Node *n4 = new Node(4, NULL, NULL);
            Node *n5 = new Node(5, NULL, NULL);
            Node *n6 = new Node(6, NULL, NULL);
            Node *n7 = new Node(7, NULL, NULL);
            Node *n2 = new Node(2, NULL, NULL, n4, n5);
            Node *n3 = new Node(3, NULL, NULL, n6, n7);
            Node *n1 = new Node(1, NULL, NULL, n2, n3);
            n2->setParent(n1);
            n3->setParent(n1);
            n4->setParent(n2);
            n5->setParent(n2);
            n6->setParent(n3);
            n7->setParent(n3);

            BinarySearchTree t(n1);
            BSTUtil::printBST(t, 1, 0, std::cout);

            Node *succ;
            std::vector<Node*> nodes = { n1, n2, n3, n4, n5, n6, n7 };
            for (Node *n : nodes) {
                succ = tree.successor(n);
                if (succ) {
                    std::cout << "Node " << n->value() << " successor is " << succ->value() << std::endl; 
                } else {
                    std::cout << "Node " << n->value() << " successor is NULL" << std::endl; 
                }
            }
        } break;
        case 11: { // Iterative inorder traversal with parent
            std::vector<int> values = {4, 2, 0, 6, 8, 99, 1, 3, 5, 7, 101};
            populateTree(&tree, values);
            BSTUtil::printBST(tree, 1, 0, std::cout);
            std::cout << "Inorder: ";
            tree.iterativeInorderTraversalWithParent();
        } break;
        case 12: { // Reconstruct from inorder and preorder 
            std::vector<int> inorder  = {4, 2, 0, 6, 8, 99, 1, 3, 5, 7, 101};
            std::vector<int> preorder = {8, 2, 4, 0, 6, 5, 1, 99, 3, 101, 7};
            BinarySearchTree bst(inorder, preorder);
            BSTUtil::printBST(bst, 1, 0, std::cout);
        } break;
        case 13: { // Tree from preorder 
            std::cerr << "Not implemented" << std::endl;
        } break;
        case 14: { // Get all leaves 
            std::cerr << "Not implemented" << std::endl;
        } break;
        case 15: { // Exterior 
            std::vector<int> values = {134, 78, 0, 890, 8, 265, 1, 46, 515, 12, 101, 10};
            populateTree(&tree, values);
            BSTUtil::printBST(tree, 1, 0, std::cout);
            std::list<int> result = tree.exterior();
            for (int i : result) {
                std::cout << i << " ";
            }
            std::cout << std::endl;
        } break;
        case 16: { // Build all trees from number of nodes 
            std::vector<BinarySearchTree> allTrees = buildTreesFromNumberOfNodes(3);
            for (auto& tree : allTrees) {
                BSTUtil::printBST(tree, 1, 0, std::cout);
            }
        } break;
        default: {
            std::cerr << "Unknown test case" << std::endl;
        } break;

    }

    return 0;
}
