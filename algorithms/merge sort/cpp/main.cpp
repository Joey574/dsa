#include <cstdlib>
#include <iostream>
#include <chrono>

#include "merge_sort.hpp"

int main(int argc, char* argv[]) {
    srand(time(0));

    size_t n = 20;
    if (argc == 2) {
        n = std::stoul(argv[1]);
    }

    auto u = std::vector<int>(n);
    for (auto& v : u) {
        v = rand() % 1000;
    }

    auto start = std::chrono::high_resolution_clock::now();
    merge_sort_inplace(u.begin(), u.end());
    auto duration = std::chrono::high_resolution_clock::now() - start;

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << "ms\n";
}
