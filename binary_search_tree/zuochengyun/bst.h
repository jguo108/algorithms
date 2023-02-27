#pragma once

#include <vector>
#include <cstddef>
#include <string>

using namespace std;

class Node {
  private:
    int   d_value;
    Node *d_left;
    Node *d_right;
    Node *d_parent;

  public:
    // CREATORS
    Node(int   value,
         Node *left = NULL,
         Node *right = NULL);

    // MANIPULATORS
    void setValue(int value);
    void setLeft(Node *left);
    void setRight(Node *right);
    void setParent(Node *parent);

    // ACCESSORS
    int value() const;
    Node* left() const;
    Node* right() const;
    Node* parent() const;
    bool isLeaf() const;
};

class BinarySearchTree {
  private:
    Node *d_root;

    Node* insert(Node *bst, int value);
    Node* insert(const std::vector<int>& nodes, int start, int end);

    int maxHeight(Node *bst) const;

  public:
    BinarySearchTree();
    BinarySearchTree(Node *root);
    BinarySearchTree(const vector<string>& input);

    void insert(int value);
    void setRoot(Node *root);
    Node* root() const;
    void print() const;
    int maxHeight() const;
    Node* find(int value);

    void preorderTraversalIterative();
    void inorderTraversalIterative();
    void postorderTraversalIterative();

    void printBorder();

    vector<string> serialize() const;
    void deserialize(const vector<string>& input);

    Node* maxBSTSubtree();

    size_t longestSumPath(int sum);

    void printByLevel();
    void printByLevelZigZag();

    pair<Node*, Node*> findOutOfOrderPair();

    bool isSubtree(const BinarySearchTree& tree);

    bool isBalanced();

    bool isBSTPostorder(const vector<int>& input);

    void buildBSTFromPostorder(const vector<int>& input);

    bool isBST();
    bool isComplete();

    void buildBSTFromSortedArray(const vector<int>& input);

    Node *getNextNode(Node *node);

    Node* lowestCommonAncestor(Node *node1, Node *node2);

    size_t maxDistance();

    vector<int> postorderFromPreorderAndInOrder(const vector<int>& preorder, const vector<int>&inorder);
};

inline
Node::Node(int value, Node *left, Node *right)
: d_value(value)
, d_left(left)
, d_right(right)
, d_parent(nullptr)
{
    if (left != nullptr) {
        left->setParent(this);
    }
    if (right != nullptr) {
        right->setParent(this);
    }
}

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
bool Node::isLeaf() const
{
    return d_left == nullptr && d_right == nullptr;
}

                               // ----------------
                               // BinarySearchTree 
                               // ----------------


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

inline
BinarySearchTree::BinarySearchTree(const vector<string>& input)
{
    deserialize(input);    
}

inline
void BinarySearchTree::setRoot(Node *root)
{
    d_root = root;
}

inline
Node* BinarySearchTree::root() const
{
    return d_root;
}

