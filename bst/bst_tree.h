#ifndef BST_TREE
#define BST_TREE

#include <iostream>

namespace bst {

class Node {
  private:
    int   d_value;

    Node *d_left;

    Node *d_right;

    Node *d_parent;

  public:
    // CREATORS
    Node(int value, Node *left = NULL, Node *right = NULL);

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
};

class BinarySearchTree {
  private:
    Node *d_root;

  private:
    // PRIVATE MANIPULATORS
    Node* insertImpl(Node *bst, int value);

    int maxHeightImpl(Node *bst) const;

    int minValueImpl(Node *bst) const;

  public:
    // CREATORS
    BinarySearchTree();

    // MANIPULATORS
    void insert(int value);


    // ACCESSORS
    Node* root() const;

    int maxHeight() const;

    int minValue() const;

};

// =============================================================================
//                          Inline Functions
// =============================================================================


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

inline
void Node::setParent(Node *parent)
{
    d_parent = parent;
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

                               // ----------------
                               // BinarySearchTree 
                               // ----------------


// CREATORS
inline
BinarySearchTree::BinarySearchTree()
: d_root(NULL)
{
}

// ACCESSORS
inline
Node* BinarySearchTree::root() const
{
    return d_root;
}




#if 0
Node *lookup( Node *root, T val) 
{
  if( root == NULL) return NULL;

  if( root->value == val) return root; 
  else if( root->value > val) return lookup(root->left, val);
  else return lookup(root->right, val);
}

int treeSize( Node *root) 
{
  if( root == NULL) return 0;

  return 1 + treeSize(root->left) + treeSize(root->right);    
}


T minValue( Node *root)
{
  if( root == NULL) return INT_MIN;
 
  if( root->left == NULL) return root->value;  

  return minValue(root->left);
}

T maxValue( Node *root)
{
  if( root == NULL) return INT_MIN;
 
  if( root->right == NULL) return root->value;  

  return maxValue(root->right);
}
#endif

} // namespace bst

#endif
