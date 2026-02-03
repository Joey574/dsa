#include <iostream>
#include "stack.hpp"

int main() {
    auto s = stack<int>();
    s.push(1);
    s.push(2);
    s.push(3);

    std::cout << s.size() << "\n";
    std::cout << s.pop() << "\n" << s.pop() << "\n" << s.pop() << "\n";
}