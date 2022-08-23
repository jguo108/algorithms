#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <assert.h>

#include "lc_bst.h"
#include "lc_bst_util.h"

using namespace lc;

void populateTree(lc::BinarySearchTree *tree, const std::vector<int>& values)
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
    lc::Node *n3 = new lc::Node(20, new Node(10), new Node(30));
    lc::Node *n4 = new lc::Node(70, new Node(60), new Node(80));
    lc::Node *n5 = new lc::Node(130, new Node(120), new Node(140));
    lc::Node *n6 = new lc::Node(180, new Node(160), new Node(200));
    lc::Node *n1 = new lc::Node(50, n3, n4);
    lc::Node *n2 = new lc::Node(150, n5, n6);
    lc::Node *n0 = new lc::Node(100, n1, n2);
    lc::BinarySearchTree tree(n0);

    tree.print();

    switch (testCase) {
        case 102: { // Level Order Traversal 102 
          tree.levelOrderTraversal();
        } break;
        case 103: { // ZigZag Level Order Traversal 103 
          tree.zigzagLevelOrderTraversal();
        } break;
        case 236: { // Lowest Common Ancester 236 
          Node *node1 = n0;
          Node *node2 = n6;
          const Node* lca = tree.lowestCommonAncester(node1, node2);
          std::cout << "LCA of " << node1->value() << " and " << node2->value() << " is: " << lca->value() << std::endl;
        } break;
        case 94: { // iterative inorder traversal 
          tree.inorderIterative();
        } break;
        case 144: { // iterative preorder traversal 
          tree.preorderIterative();
        } break;
        case 99: { // right side view 
          Node *nx = new Node(16, NULL, NULL);
          Node *n80 = new Node(80, nx, NULL);
          Node *n3 = new Node(20, new Node(10), new Node(30));
          Node *n4 = new Node(70, new Node(60), n80);
          Node *n5 = new Node(130, NULL, NULL);
          Node *n1 = new Node(50, n3, n4);
          Node *n2 = new Node(150, n5, NULL);
          Node *n0 = new Node(100, n1, n2);
          BinarySearchTree tree1(n0);
          tree1.print();
          tree1.rightSideView();
        } break;
        case 105: { // Tree from inorder and preorder
          std::vector<int> inorder = { 10, 20, 30, 50, 60, 70, 80, 100, 120, 130, 140, 150, 160, 180, 200 };
          std::vector<int> preorder = { 100, 50, 20, 10, 30, 70, 60, 80, 150, 130, 120, 140, 180, 160, 200 };
          Node *root = tree.treeFromPreorderAndInorder(preorder, inorder);
          BinarySearchTree newTree(root);
          newTree.print();
        } break;
        default: {
            std::cerr << "Unknown test case" << std::endl;
        } break;

    }

    return 0;
}
