#ifndef LC_BST_H
#define LC_BST_H

#include <vector>
#include <cstddef>

namespace lc {

class Node {
  private:
    int   d_value;
    Node *d_left;
    Node *d_right;

  public:
    // CREATORS
    Node(int   value,
         Node *left = NULL,
         Node *right = NULL);

    // MANIPULATORS
    void setValue(int value);
    void setLeft(Node *left);
    void setRight(Node *right);

    // ACCESSORS
    int value() const;
    Node* left() const;
    Node* right() const;
};

class BinarySearchTree {
  private:
    Node *d_root;

  private:
    // PRIVATE MANIPULATORS
    Node* insert(Node *bst, int value);
    Node* insert(const std::vector<int>& nodes, int start, int end);
    int maxHeight(Node *bst) const;

  public:
    // CREATORS
    BinarySearchTree();
    BinarySearchTree(Node *root);

    // MANIPULATORS
    void insert(int value);
    void setRoot(Node *root);

    // ACCESSORS
    Node* root() const;
    int maxHeight() const;
    void print() const;

  // ==================== Leetcode ==============================

  // Leetcode 102
  void levelOrderTraversal();

  // Leetcode 103
  void zigzagLevelOrderTraversal();

  // Leetcode 236
  const Node* lowestCommonAncester(const Node* n1, const Node *n2);

  // Leetcode 94
  void inorderIterative();

  // Leetcode 99
  void preorderIterative();

  // Leetcode 199
  void rightSideView();

  // Leetcode 105 TODO
  Node *treeFromPreorderAndInorder(const std::vector<int>& preorder, const std::vector<int>& inorder);

  // Leetcode 104
  int maxDepth();

  // Leetcode 129
  int sumRootToLeafNumbers();

  // Leetcode 110 
  bool isBalanced();

  // Leetcode 112
  bool hasPathSum(int sum);

  // Leetcode 113
  std::vector<std::vector<int>> findAllPathSum(int sum);

  // Leetcode 101
  bool isSymmetric();
  bool isSymmetricIterative();

  // Leetcode 543
  int diameter();

  // Leetcode 98
  bool isValidBST();

  // Leetcode 226
  void invert();
};

// ============================================================================
//                          Inline Functions
// ============================================================================


                                    // ----
                                    // Node
                                    // ----

// CREATORS
inline
Node::Node(int value, Node *left, Node *right)
: d_value(value)
, d_left(left)
, d_right(right)
{
}

// MANIPULATORS
inline
void Node::setValue(int value)
{
    d_value = value;
}

inline
void Node::setLeft(Node *left)
{
    d_left = left;
}

inline
void Node::setRight(Node *right)
{
    d_right = right;
}

// ACCESSORS
inline
int Node::value() const
{
    return d_value;
}

inline
Node* Node::left() const
{
    return d_left;
}

inline
Node* Node::right() const
{
    return d_right;
}
                               // ----------------
                               // BinarySearchTree 
                               // ----------------


// CREATORS
inline
BinarySearchTree::BinarySearchTree()
: d_root(NULL)
{
}

inline
BinarySearchTree::BinarySearchTree(Node *root)
: d_root(root)
{
}

// MANIPULATORS
inline
void BinarySearchTree::setRoot(Node *root)
{
    d_root = root;
}

// ACCESSORS
inline
Node* BinarySearchTree::root() const
{
    return d_root;
}

} // namespace lc 

#endif
