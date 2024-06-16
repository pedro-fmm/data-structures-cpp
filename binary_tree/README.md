# BinaryTree Data Structure

A `BinaryTree` is a hierarchical data structure that consists of nodes, where each node has a value and references to two child nodes (left and right). The left child node contains a value less than its parent node, and the right child node contains a value greater than or equal to its parent node. This structure allows for efficient insertion, deletion, and search operations.

## Features

- Insert elements into the tree.
- Remove elements from the tree.
- Check if an element exists in the tree.
- Retrieve elements in pre-order, in-order, and post-order traversals.
- Determine if the tree is empty.
- Get the current size of the tree.

## Implementation Details

The `BinaryTree` is implemented as a template class, allowing it to store elements of any type. Here is an overview of the class:

### BinaryTree

```cpp
#ifndef STRUCTURES_BINARY_TREE_H
#define STRUCTURES_BINARY_TREE_H

#include "array_list.h"

namespace structures {

template<typename T>
class BinaryTree {
public:
    BinaryTree();  // default constructor
    ~BinaryTree();  // destructor

    void insert(const T& data);  // insert element
    void remove(const T& data);  // remove element
    bool contains(const T& data) const;  // check if element exists
    bool empty() const;  // check if tree is empty
    std::size_t size() const;  // get size of the tree
    ArrayList<T> pre_order() const;  // traverse tree in pre-order
    ArrayList<T> in_order() const;  // traverse tree in in-order
    ArrayList<T> post_order() const;  // traverse tree in post-order

private:
    struct Node {
        explicit Node(const T& data_);
        
        T data;
        Node* left;
        Node* right;

        void insert(const T& data_);
        bool remove(const T& data_);
        bool contains(const T& data_) const;
        void pre_order(ArrayList<T>& v) const;
        void in_order(ArrayList<T>& v) const;
        void post_order(ArrayList<T>& v) const;
    };

    Node* root;  // root of the tree
    std::size_t size_;  // size of the tree
};

}  // namespace structures

#include "binary_tree.tpp"

#endif
