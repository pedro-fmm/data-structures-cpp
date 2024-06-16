# DoublyLinkedList Data Structure

A `DoublyLinkedList` is a dynamic data structure consisting of a sequence of elements, each containing a reference (or link) to both the previous and the next element in the sequence. It allows for efficient insertion and removal of elements at both the beginning and end of the list, as well as at any specified position.

## Features

- Add elements to the front, back, or at a specified index.
- Add elements in a sorted order.
- Remove elements from the front, back, or at a specified index.
- Remove a specific element by value.
- Search for an element and check if it exists in the list.
- Retrieve the current size of the list.
- Clear the list and check if it is empty.

## Implementation Details

The `DoublyLinkedList` is implemented as a template class, allowing it to store elements of any type. Here is an overview of the class:

### DoublyLinkedList

```cpp
#ifndef STRUCTURES_DOUBLY_LINKED_LIST_H
#define STRUCTURES_DOUBLY_LINKED_LIST_H

#include <stdexcept>  // C++ exceptions

namespace structures {

template<typename T>
class DoublyLinkedList {
 public:
    DoublyLinkedList();  // default constructor
    ~DoublyLinkedList();  // destructor
    void clear();  // clear the list
    void push_back(const T& data);  // insert at the end
    void push_front(const T& data);  // insert at the beginning
    void insert(const T& data, std::size_t index);  // insert at position
    void insert_sorted(const T& data);  // insert in sorted order
    T& at(std::size_t index);  // access element at position
    const T& at(std::size_t index) const;  // access element at position (const)
    T pop(std::size_t index);  // remove from position
    T pop_back();  // remove from end
    T pop_front();  // remove from beginning
    void remove(const T& data);  // remove specific element
    bool empty() const;  // check if the list is empty
    bool contains(const T& data) const;  // check if list contains data
    std::size_t find(const T& data) const;  // get the position of data
    std::size_t size() const;  // get the size of the list

 private:
    class Node {
     public:
        explicit Node(const T& data);
        Node(const T& data, Node* next);
        Node(const T& data, Node* prev, Node* next);
        T& data();
        const T& data() const;
        Node* prev();
        const Node* prev() const;
        void prev(Node* node);
        Node* next();
        const Node* next() const;
        void next(Node* node);

     private:
        T data_;
        Node* prev_;
        Node* next_;
    };

    Node* posicao(std::size_t index);  // get node at position

    Node* head;  // head of the list
    Node* tail;  // tail of the list
    std::size_t size_;
};

}  // namespace structures

#include "doubly_linked_list.tpp"

#endif
