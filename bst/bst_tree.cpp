
#include "bst_tree.h"

namespace bst {

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
    
    if (bst->value() < value) {
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

void BinarySearchTree::toLinkedList(Node       **first,
                                    Node       **last,
                                    const Node *node)
{
    if (!node) {
        return;
    }

    Node *leftTreeFirstNode = NULL;
    Node *leftTreeLastNode = NULL;
    toLinkedList(&leftTreeFirstNode, &leftTreeLastNode, node->left());

    Node *newNode = new Node(node->value());

    if (leftTreeFirstNode) {
        *first = leftTreeFirstNode; 
    } else {
        *first = newNode; 
    }

    if (leftTreeLastNode) {
        leftTreeLastNode->setRight(newNode);
    }    

    Node *rightTreeFirstNode = NULL;
    Node *rightTreeLastNode = NULL;
    toLinkedList(&rightTreeFirstNode, &rightTreeLastNode, node->right());

    if (rightTreeLastNode) {
        *last = rightTreeLastNode;
    } else {
        *last = newNode;
    }

    newNode->setRight(rightTreeFirstNode);
}

void BinarySearchTree::toLinkedList()
{
    Node *firstNode = NULL;
    Node *lastNode = NULL;
    toLinkedList(&firstNode, &lastNode, d_root);

    d_head = firstNode;
}

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

int BinarySearchTree::minValue() const
{
    if (d_root == NULL) {
        return INT_MIN;
    }

    return minValue(d_root);
}

int BinarySearchTree::minValue(Node *bst) const
{
    if (bst->left() == NULL) {
        return bst->value();
    }
  
    return minValue(bst->left());
}

Node* BinarySearchTree::find(Node *bst, int value) const
{
    if (!bst) {
        return NULL;
    }

    if (bst->value() > value) {
        return find(bst->left(), value);
    } else if (bst->value() < value) {
        return find(bst->right(), value);
    } else {
        return bst;
    }
}

Node* BinarySearchTree::find(int value) const
{
    return find(d_root, value);
}

Node* BinarySearchTree::findKth(Node *bst, size_t k) const
{
    if (!bst) {
        return NULL;
    }

    if (bst->d_leftSize == k) {
        return bst;
    }

    if (bst->d_leftSize > k) {
        return findKth(bst->left(), k);
    } else {
        return findKth(bst->right(), k - bst->d_leftSize - 1);
    }
}

Node* BinarySearchTree::findKth(size_t k) const
{
    return findKth(d_root, k);
}


bool BinarySearchTree::equals(const Node *tree1, const Node *tree2) const
{
    if ((!tree1 && tree2) || (tree1 && !tree2)) {
        return false;
    }

    if (!tree1 && !tree2) {
        return true;
    }

    return equals(tree1->left(), tree2->left())
        && equals(tree1->right(), tree2->right());
}

bool BinarySearchTree::operator==(const BinarySearchTree& tree) const
{
    return equals(d_root, tree.d_root);
}


void BinarySearchTree::printLinkedList() const
{
    Node *cur = d_head;
    while (cur) {
        std::cout << cur->value() << " -> "; 
        cur = cur->right();
    }
    std::cout << std::endl;
}

}

