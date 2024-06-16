# AVLTree Data Structure

The AVLTree is a self-balancing binary search tree that maintains the height property of its nodes to ensure O(log n) time complexity for insertion, deletion, and search operations.

## Features

- **Insert**: Adds elements while balancing the tree.
- **Remove**: Deletes elements while maintaining balance.
- **Contains**: Checks if an element exists in the tree.
- **Height**: Returns the height of the tree.
- **Traversals**: Supports pre-order, in-order, and post-order traversals.
- **Empty**: Checks if the tree is empty.
- **Size**: Returns the number of elements in the tree.

## Implementation

The AVLTree class is implemented as a templated C++ class with the following methods:

```cpp
template<typename T>
class AVLTree {
public:
    AVLTree();  // Constructor
    ~AVLTree();  // Destructor

    void insert(const T& data);  // Insert element
    void remove(const T& data);  // Remove element
    bool contains(const T& data) const;  // Check if element exists
    bool empty() const;  // Check if tree is empty
    std::size_t size() const;  // Get size of the tree
    int height() const;  // Get height of the tree
    ArrayList<T> pre_order() const;  // Pre-order traversal
    ArrayList<T> in_order() const;  // In-order traversal
    ArrayList<T> post_order() const;  // Post-order traversal
};
