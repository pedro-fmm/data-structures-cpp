# LinkedList Data Structure

A `LinkedList` is a dynamic data structure consisting of a sequence of elements, each containing a reference (or link) to the next element in the sequence. It allows for efficient insertion and removal of elements at both the beginning and end of the list, as well as at any specified position.

## Features

- Add elements to the front, back, or at a specified index.
- Remove elements from the front, back, or at a specified index.
- Search for an element and check if it exists in the list.
- Retrieve the current size of the list.
- Clear the list and check if it is empty.

## Implementation Details

The `LinkedList` is implemented as a template class, allowing it to store elements of any type. Here is an overview of the class:

### LinkedList

```cpp
#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

#include <cstdint>

namespace structures {

template<typename T>
class LinkedList {
 public:
    LinkedList();  // default constructor
    ~LinkedList();  // destructor
    void clear();  // clear the list
    void push_back(const T& data);  // insert at the end
    void push_front(const T& data);  // insert at the beginning
    void insert(const T& data, std::size_t index);  // insert at position
    void insert_sorted(const T& data);  // insert in sorted order
    T& at(std::size_t index);  // access element at position
    T pop(std::size_t index);  // remove from position
    T pop_back();  // remove from end
    T pop_front();  // remove from beginning
    void remove(const T& data);  // remove specific element
    bool empty() const;  // check if the list is empty
    bool contains(const T& data) const;  // check if list contains data
    std::size_t find(const T& data) const;  // get the position of data
    std::size_t size() const;  // get the size of the list

 private:
    class Node {  // Element (Node)
     public:
        explicit Node(const T& data):
            data_{data}
        {}

        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}

        T& data() {  // getter: data
            return data_;
        }

        const T& data() const {  // getter const: data
            return data_;
        }

        Node* next() {  // getter: next
            return next_;
        }

        const Node* next() const {  // getter const: next
            return next_;
        }

        void next(Node* node) {  // setter: next
            next_ = node;
        }

     private:
        T data_;
        Node* next_{nullptr};
    };

    Node* before_index(std::size_t index);  // node before the index

    Node* head{nullptr};  // head of the list
    Node* tail{nullptr};  // tail of the list
    std::size_t size_{0u};  // size of the list
};

}  // namespace structures

#endif
