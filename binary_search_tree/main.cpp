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
        case 104: { // max depth 
          tree.insert(75);
          tree.print();
          std::cout << "Max depth: " << tree.maxDepth() << std::endl;
        } break;
        case 129: { // Sum root to leaf 
          BinarySearchTree tree;
          tree.insert(2);
          tree.insert(1);
          tree.insert(4);
          tree.insert(3);
          tree.print();
          std::cout << "Sum: " << tree.sumRootToLeafNumbers() << std::endl;
        } break;
        case 110: { // Is balanced tree 
          BinarySearchTree tree;
          tree.insert(50);
          tree.insert(25);
          tree.insert(75);
          tree.insert(65);
          tree.insert(85);
          tree.print();
          std::cout << "Is balanced: " << tree.isBalanced() << std::endl;

          BinarySearchTree tree2;
          tree2.insert(100);
          tree2.insert(110);
          tree2.insert(50);
          tree2.insert(70);
          tree2.insert(25);
          tree2.insert(12);
          tree2.insert(30);
          tree2.print();
          std::cout << "Is balanced: " << tree2.isBalanced() << std::endl;
        } break;
        case 112: { // Has path sum 
          tree.print();
          std::cout << "Has path sum: " << tree.hasPathSum(520) << std::endl;
        } break;
        case 113: { // Find all path sum 
          Node *n0 = new Node(7);
          Node *n1 = new Node(2);
          Node *n2 = new Node(11, n0, n1);
          Node *n3 = new Node(4, n2, NULL);
          Node *n4 = new Node(5);
          Node *n5 = new Node(1);
          Node *n6 = new Node(4, n4, n5);
          Node *n7 = new Node(13);
          Node *n8 = new Node(8, n7, n6);
          Node *root = new Node(5, n3, n8);
          BinarySearchTree tree(root);
          tree.print();

          auto result = tree.findAllPathSum(22);
          for (auto& path : result) {
            std::cout << "[";
            for (auto node : path) {
              std::cout << node << ", ";
            }
            std::cout << "]";
          }
        } break;
        case 101: { // Is symmetric
          Node *n0 = new Node(3);
          Node *n1 = new Node(4);
          Node *n2 = new Node(2, n0, n1);
          Node *n3 = new Node(7);
          Node *n4 = new Node(4);
          Node *n5 = new Node(2, n4, n3);
          Node *root = new Node(1, n2, n5);
          BinarySearchTree tree(root);

          tree.print();

          std::cout << "Is symmetric (Recursive): " << tree.isSymmetric() << std::endl;
          std::cout << "Is symmetric (Iterative): " << tree.isSymmetricIterative() << std::endl;
        } break;
        case 543: { // Diameter 
          tree.print();
          std::cout << "Diameter: " << tree.diameter() << std::endl;
        } break;
        case 98: { // is valid BST 
          n4->setValue(101);
          tree.print();
          std::cout << "Is valid BST: " << tree.isValidBST() << std::endl;
        } break;
        case 226: { // invert 
          tree.print();
          tree.invert();
          tree.print();
        } break;
        default: {
            std::cerr << "Unknown test case" << std::endl;
        } break;

    }

    return 0;
}
