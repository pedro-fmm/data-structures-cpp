#include <iostream>
#include "array_stack.h"

int main() {
    structures::ArrayStack<int> stack(5);

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top element: " << stack.top() << std::endl;

    stack.pop();
    std::cout << "Top element after pop: " << stack.top() << std::endl;

    stack.clear();
    std::cout << "Stack size after clear: " << stack.size() << std::endl;

    return 0;
}