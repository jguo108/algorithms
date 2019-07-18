
#include "bst_tree.h"

#include <assert.h>
#include <stack>
#include <cmath>

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

Node* BinarySearchTree::insert(Node *bst, Node *pred, Node *succ, int value)
{
    if (bst == NULL) {
        bst = new Node(value, pred, succ);
        if (pred) {
            pred->setSuccessor(bst);
        }
        if (succ) {
            succ->setPredecessor(bst);
        }
        return bst;
    } 

    if (bst->value() == value) {
        std::cout << "Insert fail: " << value << " already exists!";
        return NULL;
    }
    
    if (bst->value() <= value) {
        bst->setRight(insert(bst->right(), bst, succ, value));
        bst->right()->setParent(bst); 
        bst->d_rightSize++;
    } else {
        bst->setLeft(insert(bst->left(), pred, bst, value));
        bst->left()->setParent(bst); 
        bst->d_leftSize++;
    }
    return bst;
}

void BinarySearchTree::insert(int value)
{
    d_root = insert(d_root, NULL, NULL, value);
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

// ============================================================================
//                                Exercises 
// ============================================================================

static bool isHeightBalancedImpl(Node *tree, int *height)
{
    if (tree == NULL) {
        *height = 0;
        return true;
    }

    int leftTreeHeight = 0;
    bool leftTreeBalanced = isHeightBalancedImpl(tree->left(), &leftTreeHeight);
    if (!leftTreeBalanced) {
        return false;
    }

    int rightTreeHeight = 0;
    bool rightTreeBalanced = isHeightBalancedImpl(tree->right(), &rightTreeHeight);
    if (!rightTreeBalanced) {
        return false;
    }

    if (std::abs(leftTreeHeight - rightTreeHeight) > 1) {
        return false;
    }

    *height = std::max(leftTreeHeight, rightTreeHeight) + 1;
    return true;
}

bool BinarySearchTree::isHeightBalanced() const
{
    int height;
    return isHeightBalancedImpl(d_root, &height);
}

// ============================================================================
static bool childEqual(const Node *n1, const Node *n2)
{
    if (n1 == NULL && n2 == NULL) {
        return true;
    }

    if (n1 != NULL && n2 != NULL) {
        return n1->value() == n2->value();
    }

    return false;
}

static void pushIfNotNull(std::stack<Node*> &s, Node *n)
{
    if (n != NULL) {
        s.push(n);
    }
}

bool BinarySearchTree::isSymmetric() const
{
    Node *leftTree = d_root->left();
    Node *rightTree = d_root->right();

    if (leftTree == NULL && rightTree == NULL) {
        return true;
    }

    std::stack<Node*> leftTreeStack;
    std::stack<Node*> rightTreeStack;
    if (leftTree != NULL && rightTree != NULL) {
        leftTreeStack.push(leftTree);
        rightTreeStack.push(rightTree);
    } else {
        return false;
    }

    while (!leftTreeStack.empty() && !rightTreeStack.empty()) {
        Node *l = leftTreeStack.top();
        Node *r = rightTreeStack.top();
        if (!childEqual(l->left(), r->right())
                || !childEqual(l->right(), r->left())) {
            return false;
        }
        leftTreeStack.pop();
        rightTreeStack.pop();
        pushIfNotNull(leftTreeStack, l->left());
        pushIfNotNull(leftTreeStack, l->right());
        pushIfNotNull(rightTreeStack, r->right());
        pushIfNotNull(rightTreeStack, r->left());
    }
    if (!leftTreeStack.empty() || !rightTreeStack.empty()) {
        return false;
    }
    return true;
}

// ============================================================================

static bool lowestCommonAncesterImpl(Node *tree, int n1, int n2, Node **lca)
{
    if (tree == NULL) {
        return false;
    }

    bool leftFound = lowestCommonAncesterImpl(tree->left(), n1, n2, lca);
    if (*lca != NULL) {
        return true;
    }
    bool rightFound = lowestCommonAncesterImpl(tree->right(), n1, n2, lca);
    if (*lca != NULL) {
        return true;
    }
    if (leftFound && rightFound) {
        *lca = tree;
        return true;
    }
    if (!leftFound && !rightFound) {
        return tree->value() == n1 || tree->value() == n2;
    }
    if (tree->value() == n1 || tree->value() == n2) {
        *lca = tree; 
        return true;
    }
    return true;
}

int BinarySearchTree::lowestCommonAncester(int n1, int n2) const
{
    Node *lca = NULL;

    lowestCommonAncesterImpl(d_root, n1, n2, &lca);

    return lca->value();
}

// ============================================================================

static int sumOfRootToLeafPathsImpl(Node *tree, int partialSum)
{
    if (tree == NULL) {
        return 0;
    }
    
    partialSum = partialSum * 2 + tree->value();
    if (tree->left() == NULL && tree->right() == NULL) {
        return partialSum;
    }
    return sumOfRootToLeafPathsImpl(tree->left(), partialSum)
        + sumOfRootToLeafPathsImpl(tree->right(), partialSum);
}

int BinarySearchTree::sumOfRootToLeafPaths() const
{
    int partialSum = 0;
    return sumOfRootToLeafPathsImpl(d_root, partialSum);
}

// ============================================================================

static bool pathExistsForSumImpl(Node *tree, int targetSum)
{
    if (tree == NULL) {
        return false;
    }

    int newTargetSum = targetSum - tree->value();
    if (tree->left() == NULL && tree->right() == NULL) {
        if (newTargetSum == 0) {
            return true;
        } else {
            return false;
        }
    }

    bool exists;
    exists = pathExistsForSumImpl(tree->left(), newTargetSum);
    if (exists) {
        return true;
    }
    exists = pathExistsForSumImpl(tree->right(), newTargetSum);
    if (exists) {
        return true;
    }
    return false;
}

bool BinarySearchTree::pathExistsForSum(int targetSum) const
{
    return pathExistsForSumImpl(d_root, targetSum); 
}

// ============================================================================

static void followLeftChild(Node *tree, std::stack<Node*>& s)
{
    while (tree != NULL) {
        s.push(tree);
        tree = tree->left();
    }
}

static void visit(Node *n)
{
    std::cout << n->value() << " ";
}

static void end()
{
    std::cout << std::endl;
}

void BinarySearchTree::iterativeInorderTraversal() const
{
    std::stack<Node*> s;

    followLeftChild(d_root, s);

    while (!s.empty()) {
        Node *n = s.top();
        s.pop();
        visit(n);
        followLeftChild(n->right(), s);
    }
    end();
}

// ============================================================================

void BinarySearchTree::iterativePreorderTraversal() const
{
    if (d_root == NULL) {
        return;
    }
    std::stack<Node*> s;
    s.push(d_root);

    while (!s.empty()) {
        Node *n = s.top();
        s.pop();
        visit(n);
        if (n->right() != NULL) {
            s.push(n->right());
        }
        if (n->left() != NULL) {
            s.push(n->left());
        }
    }
    end();
}

// ============================================================================

Node *kthNodeInorderTraversalImpl(Node *tree, int k, int& count)
{
    if (tree == NULL) {
        return NULL;
    }
    Node *n = NULL;
    n = kthNodeInorderTraversalImpl(tree->left(), k, count);
    if (n) {
        return n;
    }
    if (count == k) {
        return tree;
    }
    ++count;
    n = kthNodeInorderTraversalImpl(tree->right(), k, count);
    if (n) {
        return n;
    }
    return NULL;
}

Node* BinarySearchTree::kthNodeInorderTraversal(int k) const
{
    int count = 0;
    return kthNodeInorderTraversalImpl(d_root, k, count);
}

// ============================================================================

Node* BinarySearchTree::successor(Node *node) const
{
    Node *succ = NULL;

    if (!node) {
        return succ;
    }

    if (node->right()) {
        succ = node->right();
        while (succ->left()) {
            succ = succ->left();
        }
        return succ;
    }

    Node *parent = node->parent();
    if (!parent) {
        return succ;
    }

    if (parent->left() == node) {
        return parent;
    }

    // Node is a right child
    Node *grandparent = parent->parent();
    while (grandparent) {
        if (grandparent->right() == parent) {
            parent = grandparent;
            grandparent = parent->parent();
        } else {
            break;
        }
    }

    if (grandparent) {
        return grandparent;
    }
    return succ;
}

// ============================================================================

void BinarySearchTree::iterativeInorderTraversalWithParent() const
{
    bool fromParent = true;
    bool fromLeftChild = false;

    Node *cursor = d_root;
    while (true) {
        if (fromParent) {
            if (cursor->left() != NULL) {
                cursor = cursor->left();
            } else {
                visit(cursor);
                if (cursor->right() != NULL) {
                    cursor = cursor->right();
                } else {
                    fromParent = fromLeftChild = false;
                }
            }
        } else {
            if (fromLeftChild) {
                visit(cursor);
                if (cursor->right() != NULL) {
                    cursor = cursor->right();
                    fromParent = true;
                } else {
                    fromParent = fromLeftChild = false;
                }
            } else {
                Node *parent = cursor->parent();
                if (parent == NULL) {
                    break;
                }
                fromLeftChild = (parent->left() == cursor);
                cursor = parent;
            }
        }
    }
}

// ============================================================================

static Node* reconstruct(const std::vector<int>& inorder,
                         int                     inorderStart,
                         int                     inorderEnd,
                         const std::vector<int>& preorder,
                         int                     preorderStart,
                         int                     preorderEnd)
{
    if (inorderEnd < inorderStart) {
        return NULL;
    }

    int nodeValue = preorder[preorderStart];
    Node *n = new Node(nodeValue);

    int i = inorderStart;
    while (inorder[i] != nodeValue) {
        ++i;
    }
    int leftTreeSize = i - inorderStart; 

    n->setLeft(reconstruct(inorder,
                           inorderStart,
                           i - 1, 
                           preorder,
                           preorderStart + 1,
                           preorderStart + leftTreeSize));
    n->setRight(reconstruct(inorder,
                            i + 1,
                            inorderEnd, 
                            preorder,
                            preorderStart + leftTreeSize + 1, 
                            preorderEnd));
    return n;
}

BinarySearchTree::BinarySearchTree(const std::vector<int>& inorder,
                                   const std::vector<int>& preorder)
{
    d_root = reconstruct(inorder,
                         0, 
                         inorder.size() - 1,
                         preorder,
                         0,
                         preorder.size() - 1);
}

// ============================================================================

static void traverseLeftTree(Node *node, std::list<int>& result, bool onLeftEdge)
{
    if (node == NULL)  {
        return;
    }
    if (node->left() == NULL && node->right() == NULL) {
        result.push_back(node->value());
        return;
    }
    if (onLeftEdge) {
        result.push_back(node->value());
    }
    traverseLeftTree(node->left(), result, onLeftEdge);
    traverseLeftTree(node->right(), result, false);
}


static void traverseRightTree(Node *node, std::list<int>& result, bool onRightEdge)
{
    if (node == NULL)  {
        return;
    }
    if (node->left() == NULL && node->right() == NULL) {
        result.push_back(node->value());
        return;
    }
    traverseRightTree(node->left(), result, false);
    traverseRightTree(node->right(), result, onRightEdge);
    if (onRightEdge) {
        result.push_back(node->value());
    }
}

std::list<int> BinarySearchTree::exterior() const
{
    std::list<int> result;
    if (d_root) {
        result.push_back(d_root->value());
    }
    traverseLeftTree(d_root->left(), result, true);
    traverseRightTree(d_root->right(), result, true);
    return result;
}

// ============================================================================

void BinarySearchTree::rightSibling()
{
}


// ============================================================================

void buildTreesFromNumberOfNodesImpl(int                            numberOfNodes,
                                     std::vector<BinarySearchTree>& subTrees)
{
    if (numberOfNodes == 0) {
        subTrees.push_back(BinarySearchTree());
        return;
    }

    int remainingNumberOfNodes = numberOfNodes - 1;

    std::vector<BinarySearchTree> leftSubTrees;
    std::vector<BinarySearchTree> rightSubTrees;
    for (int i = 0; i <= remainingNumberOfNodes; ++i) {
        buildTreesFromNumberOfNodesImpl(i, leftSubTrees);
        buildTreesFromNumberOfNodesImpl(remainingNumberOfNodes - i, rightSubTrees);

        for (int i = 0; i < leftSubTrees.size(); ++i) {
            for (int j = 0; j < rightSubTrees.size(); ++j) {
                BinarySearchTree tree(new Node(0));
                tree.root()->setLeft(leftSubTrees[i].root());
                tree.root()->setRight(rightSubTrees[j].root());
                subTrees.push_back(tree);
            }
        }
        leftSubTrees.clear();
        rightSubTrees.clear();
    }
}

std::vector<BinarySearchTree> buildTreesFromNumberOfNodes(int numberOfNodes)
{
    std::vector<BinarySearchTree> result;

    buildTreesFromNumberOfNodesImpl(numberOfNodes, result);

    return result;
}









































} // Close namespace
