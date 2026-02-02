#pragma once
#include <malloc.h>

template <typename T>
struct DynamicArray {
    public:
    DynamicArray() : capacity_(0), size_(0), data_(nullptr) {}
    DynamicArray(size_t size) : capacity_(size), size_(size), data_((T*)malloc(size*sizeof(T))) {}
    DynamicArray(size_t size, const T init) : capacity_(size), size_(size), data_((T*)malloc(size*sizeof(T))) {
        for(auto& v : *this) {
            v = init;
        }
    }

    ~DynamicArray() {
        if (data_) { free(data_); }
    }

    T& operator [] (int n) { return data_[n]; }
    T operator [] (int n) const { return data_[n]; }

    constexpr size_t size() { return size_; }
    constexpr size_t capacity() { return capacity_; }

    T* begin() const {return data_; }
    T* begin() { return data_; }

    T* end() const { return &data_[size_]; }
    T* end() { return &data_[size_]; }

    void append(const T d) {
        if (++size_ > capacity_) {
            capacity_ *= 2;
            data_ = (T*)realloc(data_, capacity_*sizeof(T));
        }

        data_[size_-1] = d;
    }

    void reserve(size_t n) {
        if (capacity_ > n) {
            return;
        }

        capacity_ = n;
        data_ = (T*)realloc(data_, capacity_*sizeof(T));
    }

    std::string string(const std::string& delimiter = " ") const {
        if (size_ == 0) {
            return "";
        }
        
        std::string o;
        for (size_t i = 0; i < size_-1; i++) {
            o += std::to_string(data_[i]) + delimiter;
        } o += std::to_string(data_[size_-1]);

        return o;
    }

    private:
    size_t capacity_;
    size_t size_;
    T* data_;
};
