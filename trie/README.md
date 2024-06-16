# Trie Data Structure

The Trie (or prefix tree) is a tree-like data structure used for efficiently storing and searching strings. It supports fast insertion, deletion, and prefix-based search operations.

## Features

- **Insert**: Adds a word into the trie, marking its end.
- **Search**: Checks if a word or prefix exists in the trie.
- **Prefix Count**: Counts how many words share a common prefix.
- **Efficiency**: Operations such as insertion, deletion, and search are O(L), where L is the length of the word.

## Implementation

The Trie class is implemented as follows:

```cpp
#ifndef TRIE_H
#define TRIE_H

#include <string>

struct TrieNode {
    TrieNode* children[26] = {nullptr};  // Children nodes for each letter 'a' to 'z'
    bool word_end = false;  // Marks if a word ends at this node
    unsigned long position = 0;  // Position of the word in some external context
    unsigned long length = 0;  // Length of the word
    int prefix_count = 0;  // Number of words that have this node as a prefix
};

class Trie {
public:
    Trie();  // Constructor
    ~Trie();  // Destructor

    void insert(const std::string& word, unsigned long position, unsigned long length);  // Insert word into trie
    bool search_prefix(const std::string& word, bool& is_word, unsigned long& position, unsigned long& length, int& prefix_count);  // Search for prefix in trie

private:
    void delete_cascade(TrieNode* node);  // Recursively delete nodes

    TrieNode* root;  // Root of the trie
};

#endif // TRIE_H