# ArrayStack Data Structure

A `ArrayStack` is a stack data structure implemented using a fixed-size array. It supports typical stack operations such as push, pop, top, clear, and various utility functions to check the state of the stack.

## Features

- Push elements onto the stack.
- Pop elements from the stack.
- Retrieve the top element without removing it.
- Clear the stack.
- Check if the stack is empty or full.
- Retrieve the current size and the maximum capacity of the stack.

## Implementation Details

The `ArrayStack` is implemented as a template class, allowing it to store elements of any type. Here is an overview of the class:

### ArrayStack

```cpp
#ifndef STRUCTURES_ARRAY_STACK_H
#define STRUCTURES_ARRAY_STACK_H

#include <cstdint>
#include <stdexcept>

namespace structures {

template<typename T>
class ArrayStack {
 public:
    ArrayStack();
    explicit ArrayStack(std::size_t max);
    ~ArrayStack();

    void push(const T& data);
    T pop();
    T& top();
    void clear();
    std::size_t size();
    std::size_t max_size();
    bool empty();
    bool full();

 private:
    T* contents;
    int top_;
    std::size_t max_size_;

    static const auto DEFAULT_SIZE = 10u;
};

}  // namespace structures

#endif