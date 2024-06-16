#include <iostream>
#include "avl_tree.h"

int main() {
    structures::AVLTree<int> avl_tree;

    // Insert elements into the AVLTree
    avl_tree.insert(50);
    avl_tree.insert(30);
    avl_tree.insert(20);
    avl_tree.insert(40);
    avl_tree.insert(70);
    avl_tree.insert(60);
    avl_tree.insert(80);

    // Perform in-order traversal
    std::cout << "In-order traversal: ";
    for (const auto& elem : avl_tree.in_order()) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
