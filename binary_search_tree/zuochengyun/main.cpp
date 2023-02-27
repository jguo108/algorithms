#include <iostream>
#include <vector>

#include "bst.h"
#include "bst_util.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: a.out case" << std::endl;
        return -1;
    }

    long testCase = strtol(argv[1], NULL, 0);
    Node *n3 = new Node(20, new Node(10), new Node(30));
    Node *n4 = new Node(70, new Node(60), new Node(80));
    Node *n5 = new Node(130, new Node(120), new Node(140));
    Node *n6 = new Node(180, new Node(160), new Node(200));
    Node *n1 = new Node(50, n3, n4);
    Node *n2 = new Node(150, n5, n6);
    Node *n0 = new Node(100, n1, n2);
    BinarySearchTree tree(n0);

    switch (testCase) {
        case 1: { // 非递归先序遍历
          tree.print();
          tree.preorderTraversalIterative();
        } break;
        case 2: { // 非递归中序遍历
          tree.print();
          tree.inorderTraversalIterative();
        } break;
        case 3: { // 非递归后序遍历
          tree.print();
          tree.postorderTraversalIterative();
        } break;
        case 4: { // 打印二叉树边界节点 
          Node *n13 = new Node(13);
          Node *n14 = new Node(14);
          Node *n15 = new Node(15);
          Node *n16 = new Node(16);
          Node *n11 = new Node(11, n13, n14);
          Node *n12 = new Node(12, n15, n16);
          Node *n7 = new Node(7);
          Node *n8 = new Node(8, nullptr, n11);
          Node *n9 = new Node(9, n12, nullptr);
          Node *n10 = new Node(10);
          Node *n4 = new Node(4, n7, n8);
          Node *n5 = new Node(5, n9, n10);
          Node *n6 = new Node(6);
          Node *n2 = new Node(2, nullptr, n4);
          Node *n3 = new Node(3, n5, n6);
          Node *n1 = new Node(1, n2, n3);
          BinarySearchTree tree(n1);
          tree.print();
          tree.printBorder();
        } break;
        case 5: { // 二叉树的序列化和反序列化 
          BinarySearchTree tree;
          tree.insert(10);
          tree.insert(12);
          tree.insert(5);
          tree.insert(1);
          tree.insert(7);
          auto result = tree.serialize();
          tree.print();
          cout << "Serialization result: ";
          for (auto i : result) {
            cout << i << " ";
          }
          cout << endl;
          BinarySearchTree new_tree;
          new_tree.deserialize(result);
          new_tree.print();
        } break;
        case 6: { // 在二叉树中找到累加和为指定值的最长路径长度 
          BinarySearchTree tree;
          vector<string> input = {"-3", "3", "1", "#", "#", "0", "1", "#", "#", "6", "#", "#", "-9", "2", "#", "#", "1", "#", "#"};
          tree.deserialize(input);
          tree.print();
          cout << "Max path length: " << tree.longestSumPath(-10) << endl;
        } break;
        case 7: { // 找到二叉树中最大搜索二叉子树 
          Node *n2 = new Node(2);
          Node *n5 = new Node(5);
          Node *n4 = new Node(4, n2, n5);

          Node *n11 = new Node(11);
          Node *n15 = new Node(15);
          Node *n14 = new Node(14, n11, n15);

          Node *n10 = new Node(10, n4, n14);

          Node *n20 = new Node(20);
          Node *n16 = new Node(16);
          Node *n13 = new Node(13, n20, n16);

          Node *n12 = new Node(12, n10, n13);

          Node *n0 = new Node(0);
          Node *n3 = new Node(3);
          Node *n1 = new Node(1, n0, n3);

          Node *n6 = new Node(6, n1, n12);

          BinarySearchTree tree(n6);
          tree.print();

          Node *n = tree.maxBSTSubtree();
          BinarySearchTree tree2(n);
          BSTUtil::printBST(tree2, 1, 0, std::cout);
        } break;
        case 8: { // 二叉树按层打印与ZigZag打印
          BinarySearchTree tree;
          vector<string> input = {"1", "2", "4", "#", "#", "#", "3", "5", "7", "#", "#", "8", "#", "#", "6", "#", "#"};
          tree.deserialize(input);
          tree.print();
          cout << "Tree by level:" << endl;
          tree.printByLevel();
          cout << "Tree by level (ZigZag):" << endl;
          tree.printByLevelZigZag();
        } break;
        case 9: { // 调整二叉树中两个错误的节点
          BinarySearchTree tree;
          tree.insert(100);
          tree.insert(50);
          tree.insert(200);
          tree.insert(25);
          tree.insert(75);
          tree.insert(150);
          tree.insert(250);
          tree.print();

          Node *node1 = tree.find(75);
          Node *node2 = tree.find(200);
          node1->setValue(200);
          node2->setValue(75);
          tree.print();
          //cout << "Found out of order node pair: " << node1->value() << " and " << node2->value() << endl;

          auto out_of_order_pair = tree.findOutOfOrderPair();
          cout << "Found out of order node pair: "
               << out_of_order_pair.first->value() << " and "
               << out_of_order_pair.second->value() << endl;
        } break;
        case 10: { // 判断t1树是否包含t2树全部的拓扑结构
          BinarySearchTree tree1({"1", "2", "4", "8", "#", "#", "9", "#", "#", "5", "10", "#", "#", "#", "3", "6", "#", "#", "7", "#", "#"});
          BinarySearchTree tree2({"2", "4", "8", "#", "#", "#", "5", "#", "#"});
          tree1.print();
          tree2.print();
          cout << "Is subtree: " << tree1.isSubtree(tree2) << endl;
        } break;
        case 11: { // 判断二叉树是否为平衡二叉树
          // TODO: test case missing
          // tree.isBalanced();
        } break;
        case 12: { // 根据后序数组重建搜索二叉树 
          BinarySearchTree tree;
          vector<int> input{25, 75, 50, 150, 250, 200, 100};
          cout << "Is BST postorder: " << tree.isBSTPostorder(input) << endl;

          BinarySearchTree tree2;
          tree2.buildBSTFromPostorder(input);
          tree2.print();
        } break;
        case 13: { // 判断一棵二叉树是否为搜索二叉树和完全二叉树
          // ===== is BST ========
          BinarySearchTree tree;
          tree.insert(100);
          tree.insert(50);
          tree.insert(200);
          tree.insert(25);
          tree.insert(75);
          tree.insert(150);
          tree.insert(250);
          cout << "Is BST :" << tree.isBST() << endl;

          // ===== is Complete ========
          tree.insert(12);
          tree.insert(6);
          tree.print();
          cout << "Is complete:" << tree.isComplete() << endl;
        } break;
        case 14: { // 通过有序数组生成平衡搜索二叉树 
          vector<int> input{1,2,3,4,5,6,7,8,9,10};
          BinarySearchTree tree;
          tree.buildBSTFromSortedArray(input);
          tree.print();
        } break;
        case 15: { // 在二叉树中找到一个节点的后继节点
          vector<int> input{1,2,3,4,5,6,7,8,9,10, 11,12,13,14,15,16,17,18};
          BinarySearchTree tree;
          tree.buildBSTFromSortedArray(input);
          tree.print();

          Node* node = tree.find(18);
          Node *next_node = tree.getNextNode(node);
          if (next_node != nullptr) {
              cout << "next node of " << node->value() << " is: " << next_node->value() << endl;
          } else {
              cout << "next node of " << node->value() << " is nullptr" << endl;
          }
        } break;
        case 16: { // 在二叉树中找到两个节点的最近公共祖先
          vector<int> input{1,2,3,4,5,6,7,8,9,10, 11,12,13,14,15,16,17,18};
          BinarySearchTree tree;
          tree.buildBSTFromSortedArray(input);
          tree.print();

          Node *node1 = tree.find(10);
          Node *node2 = tree.find(16);
          Node *result = tree.lowestCommonAncestor(node1, node2);
          cout << "lca of " << node1->value() << " and " << node2->value() << " is " << result->value() << endl;
        } break;
        case 17: { // 二叉树节点间的最大距离问题 
          vector<int> input{1,2,3,4,5,6,7,8,9,10, 11,12,13,14,15,16,17,18};
          BinarySearchTree tree;
          tree.buildBSTFromSortedArray(input);
          tree.print();
          cout << "Max distance is " << tree.maxDistance() << endl;
        } break;
        case 18: { // 通过先序和中序数组生成后续数组
          vector<int> input{1,2,3,4,5,6,7};
          BinarySearchTree tree;
          tree.buildBSTFromSortedArray(input);
          tree.print();
          auto preorder = {4, 2, 1, 3, 6, 5, 7};
          auto inorder = {1, 2, 3, 4, 5, 6, 7};
          auto postorder = tree.postorderFromPreorderAndInOrder(preorder, inorder);
          for (auto i : postorder) {
            cout << i << " ";
          }
          cout << endl;
        } break;
    }
    return 0;
}