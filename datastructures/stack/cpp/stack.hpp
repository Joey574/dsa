#pragma once
#include <malloc.h>

template <typename T>
struct stack {
    public:

    stack() : size_(0), capacity_(0), data_(nullptr) {}
    stack(size_t size) : size_(size), capacity_(size), data_((T*)malloc(size*sizeof(T))) {}
    stack(size_t size, const T init) : size_(size), capacity_(size), data_((T*)malloc(size*sizeof(T))) {
        for (size_t i = 0; i < size; i++) {
            data_[i] = init;
        }
    }

    void push(const T v) {
        size_++;
        if (size_ > capacity_) {
            capacity_ = (capacity_+1)*2;
            data_ = (T*)realloc(data_, capacity_*sizeof(T));
        }

        data_[size_-1] = v;
    }
    T& peek() {
        return data_[size_-1];
    }
    T pop() {
        size_--;
        return data_[size_];
    }

    size_t size() const noexcept { return size_; }
    size_t capacity() const noexcept { return capacity_; }

    private:
    T* data_;
    size_t size_;
    size_t capacity_;
};