#include <iostream>
#include "matrix.hpp"

int main() {
    auto m = matrix<float>(10, 4, 5.0f);
    std::cout << m.string();
    m = m + 5;
    std::cout << m.string();
}
