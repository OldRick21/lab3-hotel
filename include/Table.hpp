#pragma once
#include <iostream>
#include <algorithm>
#include <mutex>

template <typename T>
class OrderedTable {
private:
    T** data;
    size_t capacity;
    size_t size;
    std::mutex mtx;

    void resize(size_t new_capacity) {
        T** new_data = new T*[new_capacity];
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    OrderedTable(size_t initial_capacity = 10)
        : data(new T*[initial_capacity]), capacity(initial_capacity), size(0) {}

    ~OrderedTable() {
        for (size_t i = 0; i < size; ++i) {
            delete data[i];
        }
        delete[] data;
    }

    void insert(T* value) {
        std::lock_guard<std::mutex> lock(mtx);
        if (size == capacity) {
            resize(capacity * 2);
        }
        size_t i = size;
        while (i > 0 && *(data[i - 1]) > *value) {
            data[i] = data[i - 1];
            --i;
        }
        data[i] = value;
        ++size;
    }

    bool search(const T& value) const {
        return std::binary_search(data, data + size, value, [](const T* a, const T* b) { return *a < *b; });
    }

    bool remove(T* value) {
        std::lock_guard<std::mutex> lock(mtx);
        size_t i = 0;
        while (i < size && *(data[i]) < *value) {
            ++i;
        }
        if (i < size && *(data[i]) == *value) {
            delete data[i];
            for (size_t j = i; j < size - 1; ++j) {
                data[j] = data[j + 1];
            }
            --size;
            return true;
        }
        return false;
    }

    void print() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << *(data[i]) << " ";
        }
        std::cout << std::endl;
    }

    class Iterator {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        Iterator(pointer* ptr) : current(ptr) {}

        reference operator*() const { return **current; }
        pointer operator->() { return *current; }

        Iterator& operator++() {
            current++;
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        Iterator& operator--() {
            current--;
            return *this;
        }

        Iterator operator--(int) {
            Iterator tmp = *this;
            --(*this);
            return tmp;
        }

        friend bool operator==(const Iterator& a, const Iterator& b) { return a.current == b.current; };
        friend bool operator!=(const Iterator& a, const Iterator& b) { return a.current != b.current; };

    private:
        pointer* current;
    };

    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + size); }

    const Iterator begin() const { return Iterator(data); }
    const Iterator end() const { return Iterator(data + size); }

    size_t getSize() const { return size; }
};
