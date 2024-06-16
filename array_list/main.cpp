#include <iostream>
#include "array_list.h"

int main() {
    structures::ArrayList<int> list(10);

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    std::cout << "Element at index 0: " << list.at(0) << std::endl;

    list.pop_front();
    std::cout << "Element at index 0 after pop_front: " << list.at(0) << std::endl;

    list.clear();
    std::cout << "List size after clear: " << list.size() << std::endl;

    return 0;
}
