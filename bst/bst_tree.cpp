
#include "bst_tree.h"

#include <assert.h>
#include <stack>

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


Node* BinarySearchTree::toBinarySearchTree(Node **list, int start, int end)
{
    if (start >= end) {
        return NULL;
    }

    int mid = (start + end) / 2;

    Node *left = toBinarySearchTree(list, start, mid);

    Node *cur = *list;
    cur->setLeft(left);
    (*list) = (*list)->right();

    Node *right = toBinarySearchTree(list, mid + 1, end);
    cur->setRight(right);

    return cur;
}

void BinarySearchTree::toBinarySearchTree()
{
    int size = 0;
    Node *list = d_head;
    while (list) {
        ++size;
        list = list->right();
    }

    d_root = toBinarySearchTree(&d_head, 0, size);
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

    Node *result = NULL;
    if (bst->value() >= value) {
        result = find(bst->left(), value);
    } 

    if (result) {
        return result;
    } else if (bst->value() == value) {
        return bst;
    }
    
    if (bst->value() < value) {
        return find(bst->right(), value);
    }
    return result;
}


Node* BinarySearchTree::find(int value) const
{
    return find(d_root, value);
}


Node* BinarySearchTree::findInMinFirstBST(Node *bst, int value) const
{
    if (!bst) {
        return NULL;
    }

    if (value == bst->value()) {
        return bst;
    }

    if (value < bst->value() || (!bst->left() && !bst->right())) {
        return NULL;
    }

    if (!bst->right()
        || (bst->left()
            && value >= bst->left()->value()
            && value < bst->right()->value())) {
        return findInMinFirstBST(bst->left(), value);
    }

    if (!bst->left() || (bst->right() && value >= bst->right()->value())) {
        return findInMinFirstBST(bst->right(), value);
    }

    return NULL;
}


Node* BinarySearchTree::findInMinFirstBST(int value) const
{
    return findInMinFirstBST(d_root, value);
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

Node* BinarySearchTree::successor(Node *node) const
{
    Node *successor = NULL;
    if (node->right()) {
        successor = node->right();
        while (successor->left()) {
            successor = successor->left();
        }
    } else {
        Node *child  = node;
        Node *parent = node->parent();
        while (parent && parent->right() == child) {
            child = parent;
            parent = parent->parent();
        }
        successor = parent;
    }
    
    return successor;
}

void BinarySearchTree::getKthLargest(Node             *bst,
                                     std::vector<int> *nodes,
                                     int               k) const
{
    if (!bst) {
        return;
    }

    if (nodes->size() == k) {
        return;
    }

    getKthLargest(bst->left(), nodes, k);
    nodes->push_back(bst->value());
    getKthLargest(bst->right(), nodes, k);
}

void BinarySearchTree::getKthLargest(std::vector<int>* nodes, int k) const
{
    getKthLargest(d_root, nodes, k);
}


const Node* BinarySearchTree::findLCA(const Node *bst,
                                      const Node *a,
                                      const Node *b) const
{
    assert(bst != NULL);

    if (bst->value() >= a->value() && bst->value() <= b->value()) {
        return bst;
    }

    if (bst->value() < a->value()) {
        return findLCA(bst->right(), a, b);
    } else {
        return findLCA(bst->left(), a, b);
    }
}

const Node* BinarySearchTree::findLCA(const Node *a, const Node *b) const
{
    return findLCA(d_root, a, b);
}

void BinarySearchTree::printInorder() const
{
    std::stack<Node*> nodes;

    Node *cur = d_root;
    while (!nodes.empty() || cur) {
        if (cur) {
            nodes.push(cur);
            cur = cur->left();
        } else {
            cur = nodes.top();
            nodes.pop();
            std::cout << cur->value() << " "; 
            cur = cur->right();
        }
    }
}

}

