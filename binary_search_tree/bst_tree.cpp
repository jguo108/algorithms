
#include "bst_tree.h"
#include "bst_util.h"

#include <assert.h>
#include <stack>
#include <cmath>
#include <iostream>

namespace bst {

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
//                                Exercises 
// ============================================================================

static bool isBSTImpl(Node *node, Node **prev)
{
    if (node == NULL) {
        return true;
    }

    bool res;
    res = isBSTImpl(node->left(), prev);
    if (!res) {
        return false;
    }
   
    if (*prev != NULL && node->value() < (*prev)->value()) {
        return false;
    }
    *prev = node;

    res = isBSTImpl(node->right(), prev);
    if (!res) {
        return false;
    }
    return true;
}

bool BinarySearchTree::isBST() const
{
    if (d_root == NULL) {
        return true;
    }
    Node *prev = NULL;
    return isBSTImpl(d_root, &prev);
}

// ============================================================================

static Node *firstGreaterThanImpl(Node *node, int k)
{
    if (node == NULL) {
        return NULL;
    }

    Node *n = NULL;
    n = firstGreaterThanImpl(node->left(), k);
    if (n) {
        return n;
    }
    if (node->value() > k) {
        return node;
    }
    n = firstGreaterThanImpl(node->right(), k);
    if (n) {
        return n;
    }
    return NULL;
}

Node* BinarySearchTree::firstGreaterThan(int k) const
{
    return firstGreaterThanImpl(d_root, k);
}

// ============================================================================

static Node* kthLargestImpl(Node *node, int k, int *count)
{
    if (node == NULL) {
        return NULL;
    }
    Node *n;
    n = kthLargestImpl(node->left(), k, count);
    if (n) {
        return n;
    }
    ++(*count);
    if (*count == k) {
        return node;
    }
    n = kthLargestImpl(node->right(), k, count);
    if (n) {
        return n;
    }
    return NULL;
}

Node* BinarySearchTree::kthLargest(int k) const
{
    int count = 0;
    return kthLargestImpl(d_root, k, &count);
}

// ============================================================================

Node* BinarySearchTree::lowestCommonAncester(Node *n1, Node *n2) const
{

    Node *cur = d_root;

    while (cur) {
        if (cur->value() == n1->value() || cur->value() == n2->value()) {
            return cur;
        }
        if (cur->value() > n1->value() && cur->value() < n2->value()) {
            return cur;
        }
        if (cur->value() > n2->value()) {
            cur = cur->left();
        } else {
            cur = cur->right();
        }
    }
    return cur;
}

// ============================================================================

BinarySearchTree::BinarySearchTree(const std::vector<int>& preorder)
{
}

// ============================================================================






















} // Close namespace
