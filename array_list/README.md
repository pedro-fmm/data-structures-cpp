# ArrayList Data Structure

An `ArrayList` is a dynamic array data structure that allows for efficient random access and dynamic resizing. It supports operations such as adding, removing, and accessing elements, both at the beginning, end, and at specified positions within the array.

## Features

- Add elements to the front, back, or at a specified index.
- Remove elements from the front, back, or at a specified index.
- Search for an element and check if it exists in the list.
- Retrieve the current size and the maximum capacity of the list.
- Clear the list and check if it is empty or full.

## Implementation Details

The `ArrayList` is implemented as a template class, allowing it to store elements of any type. Here is an overview of the class:

### ArrayList

```cpp
#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#include <cstdint>

namespace structures {

template<typename T>
class ArrayList {
 public:
    ArrayList();
    explicit ArrayList(std::size_t max_size);
    ~ArrayList();

    void clear();
    void push_back(const T& data);
    void push_front(const T& data);
    void insert(const T& data, std::size_t index);
    void insert_sorted(const T& data);
    T pop(std::size_t index);
    T pop_back();
    T pop_front();
    void remove(const T& data);
    bool full() const;
    bool empty() const;
    bool contains(const T& data) const;
    std::size_t find(const T& data) const;
    std::size_t size() const;
    std::size_t max_size() const;
    T& at(std::size_t index);
    T& operator[](std::size_t index);
    const T& at(std::size_t index) const;
    const T& operator[](std::size_t index) const;

 private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;

    static const auto DEFAULT_MAX = 10u;
};

}  // namespace structures

#endif
