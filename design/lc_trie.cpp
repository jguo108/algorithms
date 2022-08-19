#include "lc_trie.h"

namespace lc {

size_t charToIndex(char c)
{
    return c - 97;
}

Trie::Trie()
: d_root(new TrieNode)
{
}

void Trie::insert(const std::string& word)
{
    TrieNode *node = d_root;

    for (auto c : word) {
        size_t index = charToIndex(c);
        if (node->d_children[index] == nullptr) {
            node->d_children[index] = new TrieNode;
        }
        node = node->d_children[index];
    }
    node->d_endWord = true;
}

bool Trie::search(const std::string& word)
{
    TrieNode *node = d_root;
    for (auto c : word) {
        size_t index = charToIndex(c);
        if (node->d_children[index] == nullptr) {
            return false;
        }
        node = node->d_children[index];
    }
    return node->d_endWord;
}

bool Trie::startsWith(const std::string& prefix)
{
    TrieNode *node = d_root;
    for (auto c : prefix) {
        size_t index = charToIndex(c);
        if (node->d_children[index] == nullptr) {
            return false;
        }
        node = node->d_children[index];
    }
    return true;
}

}
