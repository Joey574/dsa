#pragma once
#include <concepts>
#include <vector>
#include <immintrin.h>

template <typename it>
requires std::random_access_iterator<it> && std::totally_ordered<std::iter_value_t<it>>
std::vector<std::iter_value_t<it>> merge_sort(it first, it last) {
    using T = std::iter_value_t<it>;
    auto size = std::distance(first, last);

    if (size <= 1) {
        return size == 1 ? std::vector<T>{*first} : std::vector<T>{};
    }

    auto mid = first + (size/2);
    auto a = merge_sort(first, mid);
    auto b = merge_sort(mid, last);

    std::vector<T> vec;
    vec.reserve(size);

    auto lhs = a.begin();
    auto rhs = b.begin();
    while (lhs != a.end() && rhs != b.end()) {
        if (*lhs <= *rhs) {
            vec.emplace_back(*lhs++);
        } else {
            vec.emplace_back(*rhs++);
        }
    }

    vec.insert(vec.end(), lhs, a.end());
    vec.insert(vec.end(), rhs, b.end());
    return vec;
}

template <typename it>
requires std::random_access_iterator<it> && std::totally_ordered<std::iter_value_t<it>>
void merge_sort_inplace(it first, it last) {
    using T = std::iter_value_t<it>;
    auto size = std::distance(first, last);
    if (size <= 1) { return; }

    std::vector<T> vec;
    vec.reserve(size);

    for (size_t width = 1; width < size; width *= 2) {

        for (size_t i = 0; i < size; i += 2*width) {

            auto start = first+i;
            auto mid = first + std::min<int>(i + width, size);
            auto end = first + std::min<int>(i + 2 * width, size);

            auto l = start;
            auto r = mid;

            while (l < mid && r < end) {
                if (*l < *r) {
                    vec.emplace_back(*l++);
                } else {
                    vec.emplace_back(*r++);
                }
            }

            vec.insert(vec.end(), l, mid);
            vec.insert(vec.end(), r, end);

            std::copy(vec.begin(), vec.end(), start);
            vec.clear();
        }
    }
}

void merge_sort_simd(std::vector<int>::iterator first, std::vector<int>::iterator last) {
    using T = int;
    auto size = std::distance(first, last);
    if (size <= 1) { return; }

    std::vector<T> vec;
    vec.reserve(size);

    for (size_t width = 1; width < size; width *= 2) {

        for (size_t i = 0; i < size; i += 2*width) {

            auto start = first+i;
            auto mid = first + std::min<int>(i + width, size);
            auto end = first + std::min<int>(i + 2 * width, size);

            auto l = start;
            auto r = mid;

            while (l < mid && r < end) {
                if (*l < *r) {
                    vec.emplace_back(*l++);
                } else {
                    vec.emplace_back(*r++);
                }
            }

            vec.insert(vec.end(), l, mid);
            vec.insert(vec.end(), r, end);

            std::copy(vec.begin(), vec.end(), start);
            vec.clear();
        }
    }     
}
