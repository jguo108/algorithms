
#include "lc_bst.h"
#include "lc_bst_util.h"

#include <assert.h>
#include <stack>
#include <queue>
#include <cmath>
#include <iostream>
#include <utility>
#include <unordered_map>
#include <algorithm>

namespace lc {

int BinarySearchTree::maxHeight(Node *bst) const
{
  if (!bst) {
      return 0;
  }

  int leftHeight = maxHeight(bst->left());
  int rightHeight = maxHeight(bst->right());

  return (leftHeight > rightHeight) ? leftHeight + 1: rightHeight + 1;
}

int BinarySearchTree::maxHeight() const
{
    return maxHeight(d_root);
}

Node* BinarySearchTree::insert(Node *bst, int value)
{
    if (bst == NULL) {
        bst = new Node(value);
        return bst;
    } 

    if (bst->value() == value) {
        std::cout << "Insert fail: " << value << " already exists!";
        return NULL;
    }
    
    if (bst->value() <= value) {
        bst->setRight(insert(bst->right(), value));
    } else {
        bst->setLeft(insert(bst->left(), value));
    }
    return bst;
}

void BinarySearchTree::insert(int value)
{
    d_root = insert(d_root, value);
}

Node* BinarySearchTree::insert(const std::vector<int>& nodes,
                               int                     start,
                               int                     end)
{
    if (start > end) {
        return NULL;
    }

    int mid = (start + end) / 2; 
    Node *node = new Node(nodes[mid]);

    Node *left  = insert(nodes, start, mid - 1);
    node->setLeft(left);

    Node *right = insert(nodes, mid + 1, end);
    node->setRight(right);

    return node;
}

void BinarySearchTree::print() const
{
    BinarySearchTree tree(d_root);
    BSTUtil::printBST(tree, 1, 0, std::cout);
}

// ============================================================================
//                                Leetcode 
// ============================================================================

void BinarySearchTree::levelOrderTraversal()
{
    std::queue<Node*> workQueue;
    workQueue.push(d_root);
    workQueue.push(nullptr);

    while (!workQueue.empty()) {
        Node* n = workQueue.front();
        workQueue.pop();

        if (n == nullptr) {
            if (workQueue.back() == nullptr) {
                break;
            }
            workQueue.push(nullptr);
            std::cout << "\n";
            continue;
        } 

        std::cout << n->value() << " ";
        if (n->left() != NULL) {
            workQueue.push(n->left());
        }

        if (n->right() != NULL) {
            workQueue.push(n->right());
        }
    }
}

void BinarySearchTree::zigzagLevelOrderTraversal()
{
    std::stack<Node*> currentStack;
    std::stack<Node*> nextStack;

    currentStack.push(d_root);
    bool leftToRight = false;

    while (true) {
        while (!currentStack.empty()) {
            Node *n = currentStack.top();
            currentStack.pop();

            std::cout << n->value() << " ";
            if (leftToRight) {
                if (n->right() != NULL) {
                    nextStack.push(n->right());
                }
                if (n->left() != NULL) {
                    nextStack.push(n->left());
                }
            } else {
                if (n->left() != NULL) {
                    nextStack.push(n->left());
                }
                if (n->right() != NULL) {
                    nextStack.push(n->right());
                }
            }
        }
        if (nextStack.empty()) {
            break;
        }
        std::cout << "\n";
        leftToRight = !leftToRight;
        currentStack.swap(nextStack);
    }
}


const Node* lowestCommonAncesterHelper(const Node* node, const Node* n1, const Node *n2, bool *found)
{
    if (node == NULL) {
        return NULL;
    }
    bool leftFound = false;
    const Node *leftResult = lowestCommonAncesterHelper(node->left(), n1, n2, &leftFound);
    if (leftResult) {
        return leftResult;
    }

    bool rightFound = false;
    const Node *rightResult = lowestCommonAncesterHelper(node->right(), n1, n2, &rightFound);
    if (rightResult) {
        return rightResult;
    }

    *found = (leftFound || rightFound);
    if (leftFound && rightFound) {
        return node;
    }

    if (node == n1 || node == n2) {
        *found = true;
        if (leftFound || rightFound) {
            return node;
        }
    }
    return NULL;
}

const Node* BinarySearchTree::lowestCommonAncester(const Node* n1, const Node *n2)
{
    bool found = false;
    const Node *result = lowestCommonAncesterHelper(d_root, n1, n2, &found);
    return result;
}

void BinarySearchTree::inorderIterative()
{
    std::stack<std::pair<Node*, bool>> workStack;

    workStack.push(std::make_pair(d_root, false));

    while (!workStack.empty()) {
        auto entry = workStack.top();
        workStack.pop();

        Node *node = entry.first;
        bool flag = entry.second;
        if (flag) {
            std::cout << node->value() << " ";
        } else {
            auto left = node->left(); 
            auto right = node->right(); 

            entry.second = true;
            if (right != NULL) {
                workStack.push(std::make_pair(right, false));
            }
            workStack.push(entry);
            if (left != NULL) {
                workStack.push(std::make_pair(left, false));
            }
        }
    }
    std::cout << std::endl;
}

void rightSideViewHelper(Node* node, int currentHeight, int *maxHeight, bool rightTree)
{
    if (node == NULL) {
        return;
    }

    if (rightTree) {
        std::cout << node->value() << " ";
        *maxHeight += 1;
    } else {
        if (currentHeight >= *maxHeight) {
            std::cout << node->value() << " ";
        }
    }

    if (node->right() != NULL) {
        rightSideViewHelper(node->right(), currentHeight + 1, maxHeight, rightTree);
    } else {
        rightSideViewHelper(node->left(), currentHeight + 1, maxHeight, rightTree);
    }
}

void BinarySearchTree::rightSideView()
{
    int currentHeight = 1;
    int maxHeight = 1;

    std::cout << d_root->value() << " ";

    rightSideViewHelper(d_root->right(), currentHeight, &maxHeight, true);
    rightSideViewHelper(d_root->left(), currentHeight, &maxHeight, false);
}

void BinarySearchTree::preorderIterative()
{
    std::stack<Node*> workingStack;

    workingStack.push(d_root);

    while (!workingStack.empty()) {
        Node *n = workingStack.top();
        workingStack.pop();
        std::cout << n->value() << " ";
        if (n->right() != NULL) {
            workingStack.push(n->right());
        } 
        if (n->left() != NULL) {
            workingStack.push(n->left());
        } 
    }
}

Node *treeFromPreorderAndInorderHelper(
    const std::vector<int>& preorder,
    int preorderStart,
    int preorderEnd,
    const std::vector<int>& inorder,
    int inorderStart,
    int inorderEnd,
    const std::unordered_map<int, int>& nodeIndices)
{
    if (preorderStart > preorderEnd) {
        return NULL;
    }

    //std::cout << "preorderStart: " << preorderStart << std::endl;
    //std::cout << "preorderEnd: " << preorderStart << std::endl;
    int root = preorder[preorderStart];
    std::cout << "root: " << root << std::endl;
    int rootIndexInInorder = nodeIndices.at(root);

    int numOfNodesLeftTree = rootIndexInInorder - inorderStart;

    Node *leftTree = treeFromPreorderAndInorderHelper(
        preorder,
        preorderStart + 1,
        preorderStart + numOfNodesLeftTree - 1,
        inorder,
        inorderStart,
        rootIndexInInorder - 1,
        nodeIndices);

    Node *rightTree = treeFromPreorderAndInorderHelper(
        preorder,
        preorderStart + numOfNodesLeftTree,
        preorderEnd,
        inorder,
        rootIndexInInorder + 1,
        inorderEnd,
        nodeIndices);

    Node *rootNode = new Node(root, leftTree, rightTree);

    return rootNode;
}

Node* BinarySearchTree::treeFromPreorderAndInorder(const std::vector<int>& preorder,
                                                   const std::vector<int>& inorder)
{
    std::unordered_map<int, int> nodeIndices;

    for (size_t i = 0; i < inorder.size(); ++i) {
        nodeIndices.insert({inorder[i], i});
    }

    Node *tree = treeFromPreorderAndInorderHelper(
        preorder, 0, preorder.size() - 1,
        inorder, 0, inorder.size() - 1,
        nodeIndices);

    return tree;
}

int maxDepthHelper(Node *node)
{
    if (node == NULL) {
        return 0;
    }

    int leftMax = maxDepthHelper(node->left());
    int rightMax = maxDepthHelper(node->right());

    return 1 + std::max(leftMax, rightMax);
}

int BinarySearchTree::maxDepth()
{
    return maxDepthHelper(d_root);
}


void sumRootToLeafNumbersHelper(Node *node, int runningSum, int *totalSum)
{
    if (node == NULL) {
        return;
    }

    runningSum = runningSum * 10 + node->value();
    if (node->left() == NULL && node->right() == NULL) {
        *totalSum += runningSum;
    }
    sumRootToLeafNumbersHelper(node->left(), runningSum, totalSum);
    sumRootToLeafNumbersHelper(node->right(), runningSum, totalSum);
}

int BinarySearchTree::sumRootToLeafNumbers()
{
    int totalSum = 0;
    int runningSum = 0;

    sumRootToLeafNumbersHelper(d_root, runningSum, &totalSum);

    return totalSum;
}


bool isBalancedHelper(Node *node, int *maxDepth)
{
    if (node == NULL) {
        *maxDepth = 0;
        return true;
    }
     
    int leftMaxDepth = 0;
    bool isLeftBalanced = isBalancedHelper(node->left(), &leftMaxDepth);
    if (!isLeftBalanced) {
        return false;
    }

    int rightMaxDepth = 0;
    int isRightBalanced = isBalancedHelper(node->right(), &rightMaxDepth);
    if (!isRightBalanced) {
        return false;
    }

    *maxDepth = 1 + std::max(leftMaxDepth, rightMaxDepth);
    return std::abs(leftMaxDepth - rightMaxDepth) <= 1;
}

bool BinarySearchTree::isBalanced()
{
    int maxDepth;
    return isBalancedHelper(d_root, &maxDepth);
}

bool hasPathSumHelper(Node *node, int sum)
{
    if (node == NULL) {
        return false;
    }

    int remain = sum - node->value();
    if (node->left() == NULL && node->right() == NULL) {
        return remain == 0;
    }

    return hasPathSumHelper(node->left(), remain) ||
           hasPathSumHelper(node->right(), remain);
}

bool BinarySearchTree::hasPathSum(int sum)
{
    return hasPathSumHelper(d_root, sum);
}

} // Close namespace
