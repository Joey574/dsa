#include <iostream>
#include "queue.hpp"

int main() {
    auto q = queue<int>();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    std::cout << q.size() << "\n";
    std::cout << q.dequeue() << "\n" << q.dequeue() << "\n" << q.dequeue() << "\n";
}
