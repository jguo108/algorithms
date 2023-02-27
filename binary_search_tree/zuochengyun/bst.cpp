#include <stack>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <climits>
#include <cstdlib>
#include "bst.h"
#include "bst_util.h"
using namespace std;



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

void BinarySearchTree::print() const
{
    BinarySearchTree tree(d_root);
    BSTUtil::printBST(tree, 1, 0, std::cout);
}

Node* BinarySearchTree::insert(Node *bst, int value)
{
    if (bst == NULL) {
        bst = new Node(value);
        return bst;
    } 

    if (bst->value() == value) {
        std::cout << "Insert fail: " << value << " already exists!";
        return NULL;
    }
    
    if (bst->value() <= value) {
        bst->setRight(insert(bst->right(), value));
    } else {
        bst->setLeft(insert(bst->left(), value));
    }
    return bst;
}

void BinarySearchTree::insert(int value)
{
    d_root = insert(d_root, value);
}


Node* findHelper(Node *node, int value)
{
    if (node == nullptr) {
        return nullptr;
    }

    if (node->value() == value) {
        return node;
    }

    Node *result;
    result = findHelper(node->left(), value);
    if (result) {
        return result;
    } 
    return findHelper(node->right(), value);
}

Node* BinarySearchTree::find(int value)
{
    return findHelper(d_root, value);
}

void BinarySearchTree::preorderTraversalIterative()
{
    if (d_root == nullptr) {
        return;
    }
    stack<Node*> working_stack;
    working_stack.push(d_root);
    
    while (!working_stack.empty()) {
        Node* node = working_stack.top();
        working_stack.pop();
        cout << node->value() << " ";

        if (node->right() != nullptr) {
            working_stack.push(node->right());
        }

        if (node->left() != nullptr) {
            working_stack.push(node->left());
        }
    }
}

void BinarySearchTree::inorderTraversalIterative()
{
    if (d_root == nullptr) {
        return;
    }
    stack<pair<Node*, bool>> working_stack;
    working_stack.push(make_pair(d_root, false));

    auto is_leaf_node = [](Node *n) {
        return n->left() == nullptr && n->right() == nullptr; };

    while (!working_stack.empty()) {
        auto p = working_stack.top();
        working_stack.pop();
        auto node = p.first;
        if (p.second || is_leaf_node(node)) {
            cout << node->value() << " ";
            continue;
        }
        if (node->right() != nullptr) {
            working_stack.push(make_pair(node->right(), false));
        }
        working_stack.push(make_pair(node, true));
        if (node->left() != nullptr) {
            working_stack.push(make_pair(node->left(), false));
        }
    }
}

void BinarySearchTree::postorderTraversalIterative()
{
    if (d_root == nullptr) {
        return;
    }
    stack<pair<Node*, bool>> working_stack;
    working_stack.push(make_pair(d_root, false));

    auto is_leaf_node = [](Node *n) {
        return n->left() == nullptr && n->right() == nullptr; };

    while (!working_stack.empty()) {
        auto p = working_stack.top();
        working_stack.pop();
        auto node = p.first;
        if (p.second || is_leaf_node(node)) {
            cout << node->value() << " ";
            continue;
        }
        working_stack.push(make_pair(node, true));
        if (node->right() != nullptr) {
            working_stack.push(make_pair(node->right(), false));
        }
        if (node->left() != nullptr) {
            working_stack.push(make_pair(node->left(), false));
        }
    }
}


void printBorderLeftSubtree(Node *node, set<int>& levels_seen, int level, std::vector<int>& border_nodes)
{
    if (node == nullptr) {
        return;
    }

    if (node->isLeaf() || levels_seen.find(level) == levels_seen.end()) {
        border_nodes.push_back(node->value());
        levels_seen.insert(level);
    } 
    printBorderLeftSubtree(node->left(), levels_seen, level + 1, border_nodes);
    printBorderLeftSubtree(node->right(), levels_seen, level + 1, border_nodes);
}

void printBorderRightSubtree(Node *node, set<int>& levels_seen, int level, vector<int>& border_nodes)
{
    if (node == nullptr) {
        return;
    }
    if (node->isLeaf() || levels_seen.find(level) == levels_seen.end()) {
        border_nodes.push_back(node->value());
        levels_seen.insert(level);
    } 
    printBorderRightSubtree(node->right(), levels_seen, level + 1, border_nodes);
    printBorderRightSubtree(node->left(), levels_seen, level + 1, border_nodes);
}

void BinarySearchTree::printBorder()
{
    set<int> levels_seen;
    cout << d_root->value() << " ";

    vector<int> left_border_nodes;
    printBorderLeftSubtree(d_root->left(), levels_seen, 0, left_border_nodes);

    levels_seen.clear();

    vector<int> right_border_nodes;
    printBorderRightSubtree(d_root->right(), levels_seen, 0, right_border_nodes);

    for (auto n : left_border_nodes) {
        cout << n << " ";
    }

    reverse(right_border_nodes.begin(), right_border_nodes.end());
    for (auto n : right_border_nodes) {
        cout << n << " ";
    }
    cout << endl;
}

void serializeHelper(Node *node, vector<string>& output)
{
    if (node == nullptr) {
        output.push_back("#");
        return;
    }
    output.push_back(to_string(node->value()));
    serializeHelper(node->left(), output);
    serializeHelper(node->right(), output);
    
}

vector<string> BinarySearchTree::serialize() const
{
    vector<string> result;
    serializeHelper(d_root, result);
    return result;
}

Node* deserializeHelper(queue<string>& nodes)
{
    if (nodes.empty()) {
        return nullptr;
    }

    string str = nodes.front();
    nodes.pop();
    if (str == "#") {
        return nullptr;
    } 

    Node *node = new Node(stoi(str));
    node->setLeft(deserializeHelper(nodes));
    node->setRight(deserializeHelper(nodes));
    return node;
}

void BinarySearchTree::deserialize(const vector<string>& input)
{
    queue<string> nodes;
    for (auto i : input) {
        nodes.push(i);
    }

    d_root = deserializeHelper(nodes);
}

pair<Node*, size_t> maxBSTSubtreeHelper(Node *node, size_t *num_of_nodes, bool *is_bst, int *min_val, int *max_val)
{
    if (node == nullptr) {
        *num_of_nodes = 0;
        *is_bst = true;
        *min_val = 0;
        *max_val = 0;
        return make_pair(nullptr, 0);
    }

    size_t left_num_of_nodes = 0;
    int left_min_val = 0;
    int left_max_val = 0;
    bool left_is_bst = false;
    auto left_result = maxBSTSubtreeHelper(node->left(), &left_num_of_nodes, &left_is_bst, &left_min_val, &left_max_val);

    size_t right_num_of_nodes = 0;
    int right_min_val = 0;
    int right_max_val = 0;
    bool right_is_bst = false;
    auto right_result = maxBSTSubtreeHelper(node->right(), &right_num_of_nodes, &right_is_bst, &right_min_val, &right_max_val);

    *num_of_nodes = right_num_of_nodes + left_num_of_nodes + 1;

    if (left_is_bst && right_is_bst &&
            (node->left() == nullptr  || node->value() > left_max_val) && 
            (node->right() == nullptr || node->value() < right_min_val)) {
        *is_bst = true;
        *min_val = node->left() == nullptr ? node->value() : left_min_val;
        *max_val = node->right() == nullptr ? node->value() : right_max_val;
        return make_pair(node, left_num_of_nodes + right_num_of_nodes + 1);
    }

    *is_bst = false;
    return left_result.second > right_result.second ? left_result : right_result;
}

Node* BinarySearchTree::maxBSTSubtree()
{
    size_t num_of_nodes = 0;
    int min_val = 0;
    int max_val = 0;
    bool is_bst = false;
    auto result = maxBSTSubtreeHelper(d_root, &num_of_nodes, &is_bst, &min_val, &max_val);
    return result.first;
}

size_t longestSumPathHelper(Node *node, size_t path_len, bool path_started, int sum)
{
    if (sum == 0) {
        //cout << "sum is 0: " << node->value() << " path len: " << path_len << endl;
        return path_len;
    } 

    if (node == nullptr) {
        return 0;
    }

    if (path_started) {
        size_t left_longest_path = longestSumPathHelper(node->left(), path_len + 1, path_started, sum - node->value());
        size_t right_longest_path = longestSumPathHelper(node->right(), path_len + 1, path_started, sum - node->value());
        return max(left_longest_path, right_longest_path);
    } else {
        size_t left_longest_path_skip = longestSumPathHelper(node->left(), path_len, path_started, sum);
        size_t right_longest_path_skip = longestSumPathHelper(node->right(), path_len, path_started, sum);

        size_t left_longest_path = longestSumPathHelper(node->left(), path_len + 1, true, sum - node->value());
        size_t right_longest_path = longestSumPathHelper(node->right(), path_len + 1, true, sum - node->value());

        return max({left_longest_path_skip, right_longest_path_skip, left_longest_path, right_longest_path});
    }
}

size_t BinarySearchTree::longestSumPath(int sum)
{
    return longestSumPathHelper(d_root, 0, false, sum);
}

void BinarySearchTree::printByLevel()
{
    queue<Node*> current_level;
    queue<Node*> next_level;

    current_level.push(d_root);
    while (true) {
        while (!current_level.empty()) {
            Node* n = current_level.front();
            current_level.pop();
            cout << n->value() << " ";

            if (n->left() != nullptr) {
                next_level.push(n->left());
            }
            if (n->right() != nullptr) {
                next_level.push(n->right());
            }
        }
        cout << endl;
        if (next_level.empty()) {
            break;
        }
        current_level.swap(next_level);
    }
}

void BinarySearchTree::printByLevelZigZag()
{
    stack<Node*> current_level;
    stack<Node*> next_level;

    bool left_to_right = true;

    current_level.push(d_root);
    while (true) {
        while (!current_level.empty()) {
            Node* n = current_level.top();
            current_level.pop();
            cout << n->value() << " ";

            if (left_to_right) {
                if (n->left() != nullptr) {
                    next_level.push(n->left());
                }
                if (n->right() != nullptr) {
                    next_level.push(n->right());
                }
            } else {
                if (n->right() != nullptr) {
                    next_level.push(n->right());
                }
                if (n->left() != nullptr) {
                    next_level.push(n->left());
                }
            }
        }
        cout << endl;
        if (next_level.empty()) {
            break;
        }
        left_to_right = !left_to_right;
        current_level.swap(next_level);
    }
}

Node* findOutOfOrderPairHelper(Node *node, vector<Node*>& result)
{
    Node *rightmost_node;
    
    rightmost_node = node->left() == nullptr ? node : findOutOfOrderPairHelper(node->left(), result);
    if (node->value() < rightmost_node->value()) {
        if (result.empty()) { 
            result.push_back(rightmost_node);
        } else {
            result.push_back(node);
        }
    }
    rightmost_node = node->right() == nullptr ? node : findOutOfOrderPairHelper(node->right(), result);

    return rightmost_node;
}

pair<Node*, Node*> BinarySearchTree::findOutOfOrderPair()
{
    vector<Node*> result;

    findOutOfOrderPairHelper(d_root, result);
    cout << "size: " << result.size() << endl;

    return make_pair(result[0], result[1]);
}

bool BinarySearchTree::isSubtree(const BinarySearchTree& tree)
{
    stack<Node*> stack1;
    stack<Node*> stack2;

    Node* subtree = find(tree.root()->value());
    if (subtree == nullptr) {
        return false;
    }

    stack1.push(tree.root());
    stack2.push(subtree);

    while (!stack1.empty()) {
        Node* n1 = stack1.top();
        stack1.pop();

        if (stack2.empty()) {
            return false;
        } 
        Node* n2 = stack2.top();
        stack2.pop();

        if (n1->value() != n2->value()) {
            return false;
        }

        if (n1->right() != nullptr) {
            stack1.push(n1->right());
            if (n2->right() == nullptr) {
                return false;
            }
            stack2.push(n2->right());
        } 
        if (n1->left() != nullptr) {
            stack1.push(n1->left());
            if (n2->left() == nullptr) {
                return false;
            }
            stack2.push(n2->left());
        } 
    }
    if (!stack2.empty()) {
        return false;
    }
    return true;
}

bool isBalancedHelper(Node* node, size_t *height)
{
    if (node == nullptr) {
        *height = 0;
        return true;
    }

    size_t left_height = 0;
    bool left_is_balanced = isBalancedHelper(node->left(), &left_height);

    size_t right_height = 0;
    bool right_is_balanced = isBalancedHelper(node->right(), &right_height);

    if (left_is_balanced && right_is_balanced && abs((int)left_height - (int)right_height) <= 1) {
        *height = max(left_height, right_height) + 1;
        return true;
    }
    return false;
}

bool BinarySearchTree::isBalanced()
{
    size_t height = 0;
    return isBalancedHelper(d_root, &height);
}

bool isBSTPostorderHelper(const vector<int>& input, int first, int last)
{
    if (first >= last) {
        return true;
    }

    int root = input[last];
    int cur = first;
    while (cur <= last - 1) {
        if (input[cur] < root) {
            ++cur;
        } else {
            break;
        }
    }
    int left_first = first;
    int left_last = cur - 1;

    while (cur <= last - 1) {
        if (input[cur] < root) {
            return false;
        }
        ++cur;
    }
    int right_first = left_last + 1;
    int right_last = last - 1;

    return isBSTPostorderHelper(input, left_first, left_last)
    && isBSTPostorderHelper(input, right_first, right_last);
}

bool BinarySearchTree::isBSTPostorder(const vector<int>& input)
{
    return isBSTPostorderHelper(input, 0, input.size() - 1);
}


Node* buildBSTFromPostorderHelper(const vector<int>& input, int first, int last)
{
    if (first > last) {
        return nullptr;
    }

    if (first == last) {
        return new Node(input[first]);
    }

    int root = input[last];
    Node *root_node = new Node(root);

    int cur = first;
    while (cur <= last - 1) {
        if (input[cur] < root) {
            ++cur;
        } else {
            break;
        }
    }
    int left_first = first;
    int left_last = cur - 1;
    int right_first = left_last + 1;
    int right_last = last - 1;

    root_node->setLeft(buildBSTFromPostorderHelper(input, left_first, left_last));
    root_node->setRight(buildBSTFromPostorderHelper(input, right_first, right_last));
    return root_node;
}

void BinarySearchTree::buildBSTFromPostorder(const vector<int>& input)
{
    d_root = buildBSTFromPostorderHelper(input, 0, input.size() - 1);
}


bool isBSTHelper(Node* node, int *min_val, int *max_val)
{
    if (node == nullptr) {
        return true;
    }

    int root_val = node->value();
    int left_min_val = root_val;
    int left_max_val = root_val;
    bool is_left_bst = isBSTHelper(node->left(), &left_min_val, &left_max_val);

    if (!is_left_bst) {
        return false;
    }
    *min_val = left_min_val;

    int right_min_val = root_val;
    int right_max_val = root_val;
    bool is_right_bst = isBSTHelper(node->right(), &right_min_val, &right_max_val);

    if (!is_right_bst) {
        return false;
    }
    *max_val = right_max_val;

    return root_val >= left_max_val && root_val <= right_min_val;
}

bool BinarySearchTree::isBST()
{
    int min_val;
    int max_val;
    return isBSTHelper(d_root, &min_val, &max_val);
}

bool BinarySearchTree::isComplete()
{
    queue<Node*> working_queue;

    working_queue.push(d_root);

    while (!working_queue.empty()) {
        Node *n = working_queue.front();
        working_queue.pop();
        if (n == nullptr) {
            break;
        }
        working_queue.push(n->left());
        working_queue.push(n->right());
    }

    while (!working_queue.empty()) {
        Node *n = working_queue.front();
        working_queue.pop();
        if (n != nullptr) {
            return false;
        }
    }
    return true;
}

Node* buildBSTFromSortedArrayHelper(const vector<int>& input, int first, int last)
{
    if (first > last) {
        return nullptr;
    }

    int mid = (first + last) / 2;

    Node *root = new Node(input[mid]);
    Node *left_child = buildBSTFromSortedArrayHelper(input, first, mid - 1);
    root->setLeft(left_child);
    if (left_child != nullptr) {
        left_child->setParent(root);
    } 

    Node *right_child = buildBSTFromSortedArrayHelper(input, mid + 1, last);
    root->setRight(right_child);
    if (right_child != nullptr) {
        right_child->setParent(root);
    } 

    return root;
}

void BinarySearchTree::buildBSTFromSortedArray(const vector<int>& input)
{
    d_root = buildBSTFromSortedArrayHelper(input, 0, input.size() - 1); 
}


Node *getLeftMostNode(Node *node)
{
    if (node == nullptr) {
        return nullptr;
    }
    Node *prev = node;
    Node *next = node->right();

    while (next != nullptr) {
        prev = next;
        next = next->left();
    }
    return prev == node ? nullptr : prev;
}

Node* BinarySearchTree::getNextNode(Node *node)
{
    auto isLeftChild = [this](Node* node) { return node != d_root && node->parent()->left() == node; };    
    auto isRightChild = [this](Node* node) { return node != d_root && node->parent()->right() == node; };    

    auto parentFinder = [this, &isRightChild](Node* node) -> Node*{
        while (node != nullptr && isRightChild(node)) {
            node = node->parent();
        }
        if (node == nullptr) {
            return nullptr;
        }
        return node->parent();
    };

    if (node == d_root) {
        return getLeftMostNode(node);
    }

    if (isLeftChild(node)) {
        return node->parent();
    }

    if (isRightChild(node)) {
        Node *next = getLeftMostNode(node);
        if (next != nullptr) {
            return next;
        }
        return parentFinder(node);
    }
    return nullptr;
}

Node* lowestCommonAncestorHelper(Node *root, bool *found, Node *node1, Node *node2)
{
    if (root == nullptr) {
        return nullptr;
    }
    bool left_found = false;
    bool right_found = false;
    Node *lca = nullptr;

    lca = lowestCommonAncestorHelper(root->left(), &left_found, node1, node2);
    if (lca != nullptr) {
        return lca;
    }
    lca = lowestCommonAncestorHelper(root->right(), &right_found, node1, node2);
    if (lca != nullptr) {
        return lca;
    }

    if (left_found && right_found) {
        return root;
    }
    *found = left_found || right_found;
    if (root == node1 || root == node2) {
        if (*found) {
            return root;
        } else {
            *found = true;
        }
    }
    return nullptr;
}

Node* BinarySearchTree::lowestCommonAncestor(Node *node1, Node *node2)
{
    bool found = false;
    return lowestCommonAncestorHelper(d_root, &found, node1, node2);
}


size_t maxDistanceHelper(Node *root, size_t *maxHeight)
{
    if (root == nullptr) {
        *maxHeight = 0;
        return 0;
    }

    size_t leftMaxHeight;
    size_t leftMaxDistance = maxDistanceHelper(root->left(), &leftMaxHeight);

    size_t rightMaxHeight;
    size_t rightMaxDistance = maxDistanceHelper(root->right(), &rightMaxHeight);

    *maxHeight = max(leftMaxHeight, rightMaxHeight) + 1;

    size_t currentMaxDistance = leftMaxHeight + rightMaxHeight + 1;
    size_t maxOfLeftAndRight = max(leftMaxDistance, rightMaxDistance);
    if (currentMaxDistance > maxOfLeftAndRight) {
        return currentMaxDistance;
    }
    return maxOfLeftAndRight;
}

size_t BinarySearchTree::maxDistance()
{
    size_t maxHeight;
    return maxDistanceHelper(d_root, &maxHeight);
}

void postorderFromPreorderAndInOrderHelper(
    vector<int> *postorder,
    const vector<int>& preorder,
    const vector<int>& inorder,
    int preorder_start,
    int preorder_end,
    int inorder_start,
    int inorder_end)
{
    if (preorder_start > preorder_end) {
        return;
    }


    int root = preorder[preorder_start];
    int index = inorder_start;
    while (true) {
        if (inorder[index] == root) break;
        ++index; 
    }

    int left_tree_size = index - inorder_start;
    //int right_tree_size = inorder_end - index;

    // left subtree
    postorderFromPreorderAndInOrderHelper(
        postorder, preorder, inorder,
        preorder_start + 1, preorder_start + left_tree_size,
        inorder_start, inorder_start + left_tree_size - 1);

    // right subtree
    postorderFromPreorderAndInOrderHelper(
        postorder, preorder, inorder,
        preorder_start + left_tree_size + 1, preorder_end,
        index + 1, inorder_end);

    postorder->push_back(root);
}

vector<int> BinarySearchTree::postorderFromPreorderAndInOrder(
    const vector<int>& preorder, const vector<int>&inorder)
{
    vector<int> postorder;
    postorderFromPreorderAndInOrderHelper(
        &postorder, preorder, inorder,
        0, inorder.size() - 1, 0, inorder.size() - 1);

    return postorder;
}



