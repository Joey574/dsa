#pragma once
#include <malloc.h>
#include <string.h>

template <typename T>
struct matrix {
    public:

    matrix() : rows_(0), cols_(0), data_(nullptr) {}
    matrix(size_t rows, size_t cols) : rows_(rows), cols_(cols), data_((T*)malloc(rows*cols*sizeof(T))) {}
    matrix(size_t rows, size_t cols, const T init) : rows_(rows), cols_(cols), data_((T*)malloc(rows*cols*sizeof(T))) {
        for (auto& v : *this) {
            v = init;
        }
    }

    T* begin() { return data_; }
    T* end() { return &data_[rows_*cols_]; }

    const T* begin() const { return data_; }
    const T* end() const { return &data_[rows_*cols_]; }

    size_t rows() const noexcept { return rows_; }
    size_t cols() const noexcept { return cols_; }

    std::string string(const std::string& delimiter = " ") const noexcept {
        std::string o = "";
        for (size_t r = 0; r < rows_; r++) {
            for (size_t c = 0; c < cols_; c++) {
                o += std::to_string(data_[r*cols_+c]) + delimiter;                
            } o += "\n";
        }

        return o;
    }

    matrix& operator + (const T& scalar) {
        for (auto& v : *this) {
            v += scalar;
        }

        return *this;
    }

    matrix& operator - (const T& scalar) {
        for (auto& v : *this) {
            v -= scalar;
        }

        return *this;
    }

    matrix& operator * (const T& scalar) {
        for (auto& v : *this) {
            v *= scalar;
        }

        return *this;
    }

    matrix& operator / (const T& scalar) {
        for (auto& v : *this) {
            v /= scalar;
        }

        return *this;
    }

    private:
    T* data_;
    size_t rows_;
    size_t cols_;
};