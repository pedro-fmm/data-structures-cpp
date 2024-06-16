#include <iostream>
#include "trie.h"

int main() {
    Trie trie;

    // Insert words into the trie
    trie.insert("apple", 0, 5);
    trie.insert("append", 6, 6);
    trie.insert("orange", 13, 6);

    // Search for prefixes
    bool is_word;
    unsigned long position;
    unsigned long length;
    int prefix_count;

    std::string word_to_search = "app";
    bool found = trie.search_prefix(word_to_search, is_word, position, length, prefix_count);

    if (found) {
        std::cout << "Prefix '" << word_to_search << "' found." << std::endl;
        if (is_word) {
            std::cout << "It is a complete word at position " << position << " with length " << length << "." << std::endl;
        } else {
            std::cout << "It is a prefix of " << prefix_count << " words." << std::endl;
        }
    } else {
        std::cout << "Prefix '" << word_to_search << "' not found." << std::endl;
    }

    return 0;
}
