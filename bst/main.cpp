#include <iostream>

#include "bst_tree.h"
#include "bst_util.h"

int main()
{
    bst::BinarySearchTree tree;

    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);

    bst::BSTUtil::printBST(tree, 1, 0, std::cout);

    return 0;
}
