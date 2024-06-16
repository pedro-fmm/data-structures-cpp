#include <iostream>
#include "doubly_circular_list.h"

int main() {
    structures::DoublyCircularList<int> list;

    // Insert elements into the list
    list.push_back(10);
    list.push_front(5);
    list.insert(7, 1); // Insert 7 at index 1
    list.insert_sorted(8); // Insert 8 in sorted order

    // Display elements
    for (std::size_t i = 0; i < list.size(); ++i) {
        std::cout << list.at(i) << std::endl;
    }

    return 0;
}
