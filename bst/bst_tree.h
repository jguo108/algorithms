#ifndef BST_TREE
#define BST_TREE

#include <iostream>

namespace bst {

class Node {
  private:
    int   d_value;

    Node *d_pred;

    Node *d_succ;

    Node *d_left;

    Node *d_right;

    Node *d_parent;

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

    // ACCESSORS
    int value() const;

    Node* left() const;

    Node* right() const;

    Node* parent() const;

    Node* predecessor() const;

    Node* successor() const;
};

class BinarySearchTree {
  private:
    Node *d_root;

    Node *d_head;

  private:
    // PRIVATE MANIPULATORS
    Node* insert(Node *bst, Node *pred, Node *succ, int value);

    int maxHeight(Node *bst) const;

    int minValue(Node *bst) const;

    Node* find(Node *bst, int value) const;

    Node* findKth(Node *bst, size_t k) const;

    bool equals(const Node *tree1, const Node *tree2) const;

    void toLinkedList(Node **first, Node **last, const Node *node);

  public:
    // CREATORS
    BinarySearchTree();

    // MANIPULATORS
    void insert(int value);

    void toLinkedList();

    // ACCESSORS
    Node* root() const;

    int maxHeight() const;

    int minValue() const;

    Node* find(int value) const;

    Node* findKth(size_t k) const;

    void printLinkedList() const;

    bool operator==(const BinarySearchTree& tree) const;
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
, d_head(NULL)
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
