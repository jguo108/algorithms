#ifndef LC_TRIE_H
#define LC_TRIE_H

#include <string>
#include <array>
#include <algorithm>

namespace lc {

struct TrieNode
{
    bool d_endWord = false;
    std::array<struct TrieNode*, 26> d_children = { nullptr };
};

class Trie 
{
  private:
    struct TrieNode *d_root;

  public:
    Trie();

    void insert(const std::string& word);

    bool search(const std::string& word);

    bool startsWith(const std::string& prefix);
};

}

#endif