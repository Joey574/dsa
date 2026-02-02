#include <iostream>
#include "dynamicarray.hpp"

int main() {
    auto vec = DynamicArray<int>(10);
    vec[0] = 0;
    vec[1] = 1;
    std::cout << vec.size() << "/" << vec.capacity() << "\n";  
    std::cout << vec.string() << "\n";

    vec.append(1337);
    std::cout << vec.size() << "/" << vec.capacity() << "\n";  
    std::cout << vec.string() << "\n";
}