#pragma once
#include <string>

template <typename T>
struct LinkedList {
    public:
    LinkedList() : root_(nullptr) {}
    LinkedList(size_t size) {
        if (size == 0) { return; }
        Node* last = nullptr;
        for (size_t i = 0; i < size; i++) {
            auto n = new Node();
            if (last) {
                last->next_ = n;
            } else {
                root_ = n;
            }

            last = n;
        }
    }
    LinkedList(size_t size, T init) {
        Node* last = nullptr;
        for (size_t i = 0; i < size; i++) {
            auto n = new Node();
            n->data_ = init;
            
            if (last) {
                last->next_ = n;
            } else {
                root_ = n;
            }

            last = n;
        }
    }

    std::string string(const std::string& delimiter = " ") const {
        std::string o;
        for(auto n = root_; n != nullptr; n = n->next_) {
            o += std::to_string(n->data_) + delimiter;
        }

        return o;
    }


    T& operator [] (size_t n) {
        Node* v = nullptr;
        for (size_t i = 0; i < n; i++) {
            v = v->next_;
        }
        return v->data_;
    }
    T operator [] (size_t n) const {
        Node* v = nullptr;
        for (size_t i = 0; i < n; i++) {
            v = v->next_;
        }
        return v->data_;
    }

    constexpr size_t size() const {
        size_t o = 0;
        for(auto n = root_; n != nullptr; n = n->next_, o++) {}
        return o;
    }
    
    void append(const T d) {
        auto n = new Node();
        n->data_ = d;

        for (Node* v = root_;; v = v->next_) {
            if (v->next_ == nullptr) {
                v->next_ = n;
                return;
            }
        }
    }
    void remove(size_t n) {
        auto v = root_;
        for (size_t i = 0; i < n-1; i++, v = v->next_) {}
        auto tmp = v->next_;
        v->next_ = tmp->next_;
        delete tmp;
    }

    private:
    struct Node {
        public:
        Node* next_;
        T data_;
    };
    
    Node* root_;
};