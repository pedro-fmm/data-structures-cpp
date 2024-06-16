#ifndef TRIE_H
#define TRIE_H

#include <string>

struct TrieNode {
    TrieNode* children[26] = {nullptr};
    bool word_end = false;
    unsigned long position = 0;
    unsigned long length = 0;
    int prefix_count = 0;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete_cascade(root);
    }

    void insert(const std::string& word, unsigned long position, unsigned long length) {
        TrieNode* current_node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!current_node->children[index]) { 
                // testa se a letra ja foi inserida nos filhos do node
                current_node->children[index] = new TrieNode(); 
            }
            current_node = current_node->children[index]; // pula para o node da letra
            current_node->prefix_count++; 
            // conta quantas palavras "passaram" por aquele node, sendo isso a 
            // quantidade de palavras que usam da raiz até aquele ponto como um 
            // prefixo
        }
        current_node->word_end = true;
        current_node->position = position;
        current_node->length = length;
    }

    bool search_prefix(const std::string& word, bool& is_word, unsigned long& position, unsigned long& length, int& prefix_count) {
        TrieNode* current_node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!current_node->children[index]) { 
            // testa se o prefixo passado é prefixo de alguma palavra na trie
                return false;
            }
            current_node = current_node->children[index];
        }
        // atribui os valores do node aos valores que serao printados
        is_word = current_node->word_end;
        position = current_node->position;
        length = current_node->length;
        prefix_count = current_node->prefix_count;
        return true;
    }

private:
    void delete_cascade(TrieNode* node) {
        // delete recursivo de todos os nodes da trie
        if (node != nullptr) {
            for (std::size_t i = 0; i < 26; i++)
                delete_cascade(node->children[i]); 
            delete node;
        }
    }

    TrieNode* root;
};

#endif // TRIE_H
