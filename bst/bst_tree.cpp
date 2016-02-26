
#include "bst_tree.h"

namespace bst {

Node* BinarySearchTree::insertImpl(Node *bst, int value)
{
    if (bst == NULL) {
        bst = new Node(value);
        return bst;
    } 

    if (bst->value() == value) {
        std::cout << "Insert fail: " << value << " already exists!";
        return NULL;
    }
    
    if (bst->value() < value) {
        bst->setRight(insertImpl(bst->right(), value));
        bst->right()->setParent(bst); 
    } else {
        bst->setLeft(insertImpl(bst->left(), value));
        bst->left()->setParent(bst); 
    }
    return bst;
}

void BinarySearchTree::insert(int value)
{
    d_root = insertImpl(d_root, value);
}

int BinarySearchTree::maxHeightImpl(Node *bst) const
{
  if (!bst) {
      return 0;
  }

  int leftHeight = maxHeightImpl(bst->left());
  int rightHeight = maxHeightImpl(bst->right());

  return (leftHeight > rightHeight) ? leftHeight + 1: rightHeight + 1;
}

int BinarySearchTree::maxHeight() const
{
    return maxHeightImpl(d_root);
}

int BinarySearchTree::minValue() const
{
    if (d_root == NULL) {
        return INT_MIN;
    }

    return minValueImpl(d_root);
}

int BinarySearchTree::minValueImpl(Node *bst) const
{
    if (bst->left() == NULL) {
        return bst->value();
    }
  
    return minValueImpl(bst->left());
}

}

