#ifndef BST_TREE
#define BST_TREE

#include <iostream>
#include <vector>
#include <list>

namespace bst {

class Node {
  private:
    int   d_value;
    Node *d_pred;
    Node *d_succ;
    Node *d_left;
    Node *d_right;
    Node *d_parent;
    Node *d_levelNext;

  public:
    size_t d_leftSize;
    size_t d_rightSize;

  public:
    // CREATORS
    Node(int   value,
         Node *pred = NULL,
         Node *succ = NULL,
         Node *left = NULL,
         Node *right = NULL);

    // MANIPULATORS
    void setValue(int value);
    void setLeft(Node *left);
    void setRight(Node *right);
    void setParent(Node *parent);
    void setPredecessor(Node *pred); 
    void setSuccessor(Node *succ);
    void setLevelNext(Node *succ);

    // ACCESSORS
    int value() const;
    Node* left() const;
    Node* right() const;
    Node* parent() const;
    Node* predecessor() const;
    Node* successor() const;
    Node* levelNext() const;
};

class BinarySearchTree {
  private:
    Node *d_root;

  private:
    // PRIVATE MANIPULATORS
    Node* insert(Node *bst, Node *pred, Node *succ, int value);
    Node* insert(const std::vector<int>& nodes, int start, int end);

    int maxHeight(Node *bst) const;

  public:
    // CREATORS
    BinarySearchTree();
    BinarySearchTree(Node *root);

    // MANIPULATORS
    void insert(int value);

    // ACCESSORS
    Node* root() const;

    int maxHeight() const;

    // EXERCISES
    bool isHeightBalanced() const;
      // EPI, Problem 10.1, Page 137

    bool isSymmetric() const;
      // EPI, Problem 10.2, Page 139

    int lowestCommonAncester(int n1, int n2) const;
      // EPI, Problem 10.3, Page 140

    int lowestCommonAncesterWithParent(int n1, int n2) const;
      // EPI, Problem 10.4, Page 141

    int sumOfRootToLeafPaths() const;
      // EPI, Problem 10.5, Page 142

    bool pathExistsForSum(int targetSum) const;
      // EPI, Problem 10.6, Page 143

    void iterativeInorderTraversal() const;
      // EPI, Problem 10.7, Page 144

    void iterativePreorderTraversal() const;
      // EPI, Problem 10.8, Page 145

    Node* kthNodeInorderTraversal(int k) const;
      // EPI, Problem 10.9, Page 146

    Node* successor(Node *n) const;
      // EPI, Problem 10.10, Page 146

    void iterativeInorderTraversalWithParent() const;
    void iterativePreorderTraversalWithParent() const; // Uncompleted
    void iterativePostorderTraversalWithParent() const; // Uncompleted
      // EPI, Problem 10.11, Page 148

    BinarySearchTree(const std::vector<int>& inorder,
                     const std::vector<int>& preorder); 
      // EPI, Problem 10.12, Page 149

    std::list<int> leaves() const;
      // EPI, Problem 10.14, Page 152

    std::list<int> exterior() const;
      // EPI, Problem 10.15, Page 153

    void rightSibling();
      // EPI, Problem 10.16, Page 154
};

// =============================================================================
//                          Inline Functions
// =============================================================================


                                    // ----
                                    // Node
                                    // ----

// CREATORS
inline
Node::Node(int value, Node *pred, Node *succ, Node *left, Node *right)
: d_value(value)
, d_pred(pred)
, d_succ(succ)
, d_left(left)
, d_right(right)
, d_parent(NULL)
, d_leftSize(0)
, d_rightSize(0)
, d_levelNext(NULL)
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

inline
void Node::setParent(Node *parent)
{
    d_parent = parent;
}

inline
void Node::setPredecessor(Node *pred)
{
    d_pred = pred;
}

inline
void Node::setSuccessor(Node *succ)
{
    d_succ = succ;
}

inline
void Node::setLevelNext(Node *n)
{
    d_levelNext = n;
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

inline
Node* Node::parent() const
{
    return d_parent;
}

inline
Node* Node::predecessor() const
{
    return d_pred;
}

inline
Node* Node::successor() const
{
    return d_succ;
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

// ACCESSORS
inline
Node* BinarySearchTree::root() const
{
    return d_root;
}

} // namespace bst

#endif
