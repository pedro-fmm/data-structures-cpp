# ArrayQueue Data Structure

A `ArrayQueue` is a queue data structure implemented using a fixed-size array. It supports typical queue operations such as enqueue, dequeue, back, clear, and various utility functions to check the state of the queue.

## Features

- Enqueue elements into the queue.
- Dequeue elements from the queue.
- Retrieve the last element without removing it.
- Clear the queue.
- Check if the queue is empty or full.
- Retrieve the current size and the maximum capacity of the queue.

## Implementation Details

The `ArrayQueue` is implemented as a template class, allowing it to store elements of any type. Here is an overview of the class:

### ArrayQueue

```cpp
#ifndef STRUCTURES_ARRAY_QUEUE_H
#define STRUCTURES_ARRAY_QUEUE_H

#include <cstdint>
#include <stdexcept>

namespace structures {

template<typename T>
class ArrayQueue {
 public:
    ArrayQueue();
    explicit ArrayQueue(std::size_t max);
    ~ArrayQueue();

    void enqueue(const T& data);
    T dequeue();
    T& back();
    void clear();
    std::size_t size();
    std::size_t max_size();
    bool empty();
    bool full();

 private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;
    int begin_;
    int end_;
    static const auto DEFAULT_SIZE = 10u;
};

}  // namespace structures

#endif
