#pragma once
#include <malloc.h>

template <typename T>
struct queue {
    public:
    queue() : capacity_(0), size_(0), data_(nullptr) {}
    queue(size_t size) : capacity_(size), size_(size), data_((T*)malloc(size*sizeof(T))) {}
    queue(size_t size, const T& init) : capacity_(size), size_(size), data_((T*)malloc(size*sizeof(T))) {
        for (size_t i = 0; i < size; i++) {
            data_[i] = init;
        }
    }

    ~queue() {
        if (data_) {
            free(data_);
        }
    }

    void enqueue(const T& v) {
        size_++;
        if (size_ > capacity_) {
            capacity_ = (capacity_+1)*2;
            data_ = (T*)realloc(data_, capacity_*sizeof(T));
        }

        data_[size_-1] = v;
    }
    T& peek() const {
        return data_[0];
    }
    T dequeue() {
        auto v = data_[0];

        size_--;
        for (size_t i = 0; i < size_; i++) {
            data_[i] = data_[i+1];
        }
        
        return v;
    }

    size_t size() const noexcept { return size_; }
    size_t capacity() const noexcept { return capacity_; }

    private:
    T* data_;
    size_t size_;
    size_t capacity_;
};