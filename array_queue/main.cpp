#include <iostream>
#include "array_queue.h"

int main() {
    structures::ArrayQueue<int> queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Last element: " << queue.back() << std::endl;

    std::cout << "Dequeued element: " << queue.dequeue() << std::endl;

    queue.clear();
    std::cout << "Queue size after clear: " << queue.size() << std::endl;

    return 0;
}
