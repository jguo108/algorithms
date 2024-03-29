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

    // EXERCISES
    bool isBST() const;
      // EPI, Problem 15.1, Page 230

    Node* firstGreaterThan(int k) const; 
      // EPI, Problem 15.2, Page 232

    Node* kthLargest(int k) const;
      // EPI, Problem 15.3, Page 233

    Node* lowestCommonAncester(Node *n1, Node *n2) const;
      // EPI, Problem 15.4, Page 234

    BinarySearchTree(const std::vector<int>& preorder);
      // EPI, Problem 15.5, Page 235

    std::vector<int> rangeLookup(int lowerBound, int upperBound) const;
      // EPI, Problem 15.12, Page 248
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
