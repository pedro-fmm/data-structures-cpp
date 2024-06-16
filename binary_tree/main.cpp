#include <iostream>
#include "binary_tree.h"

int main() {

    structures::BinaryTree<int> tree;

    // Insert elements into the tree
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    std::cout << "Pre-order traversal: ";
    for (const auto& elem : tree.pre_order()) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::cout << "In-order traversal: ";
    for (const auto& elem : tree.in_order()) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    for (const auto& elem : tree.post_order()) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
