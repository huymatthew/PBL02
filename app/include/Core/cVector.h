#ifndef CVECTOR_H
#define CVECTOR_H

#include <algorithm>
#include <utility>
#include <stdexcept>

template <typename T>
class Vector {
public:
    using value_type = T;
    using size_type = unsigned long;
    using iterator = T*;
    using const_iterator = const T*;

    Vector() : _capacity(0), _size(0), _data(nullptr) { reserve(4); }
    explicit Vector(size_type n) : _capacity(0), _size(0), _data(nullptr) { reserve(n); for (size_type i = 0; i < n; ++i) push_back(T()); }

    Vector(const Vector& other) : _capacity(0), _size(0), _data(nullptr) {
        reserve(other._capacity);
        for (size_type i = 0; i < other._size; ++i) push_back(other._data[i]);
    }

    Vector(Vector&& other) noexcept : _capacity(other._capacity), _size(other._size), _data(other._data) {
        other._capacity = 0;
        other._size = 0;
        other._data = nullptr;
    }

    Vector& operator=(Vector other) noexcept {
        swap(other);
        return *this;
    }

    ~Vector() {
        delete[] _data;
    }

    void push_back(const T& item) {
        ensure_capacity_for_one();
        _data[_size++] = item;
    }

    void push_back(T&& item) {
        ensure_capacity_for_one();
        _data[_size++] = std::move(item);
    }

    template <typename... Args>
    void emplace_back(Args&&... args) {
        ensure_capacity_for_one();
        _data[_size++] = T(std::forward<Args>(args)...);
    }

    void pop_back() {
        if (_size == 0) return;
        --_size;
        _data[_size].~T();
    }

    T& operator[](size_type idx) { return _data[idx]; }
    const T& operator[](size_type idx) const { return _data[idx]; }

    T& at(size_type idx) {
        if (idx >= _size) throw std::out_of_range("Vector::at: index out of range");
        return _data[idx];
    }
    const T& at(size_type idx) const {
        if (idx >= _size) throw std::out_of_range("Vector::at: index out of range");
        return _data[idx];
    }

    size_type size() const noexcept { return _size; }
    size_type capacity() const noexcept { return _capacity; }
    bool empty() const noexcept { return _size == 0; }

    void reserve(size_type newCap) {
        if (newCap <= _capacity) return;
        T* newData = new T[newCap];
        for (size_type i = 0; i < _size; ++i) newData[i] = std::move(_data[i]);
        delete[] _data;
        _data = newData;
        _capacity = newCap;
    }

    void clear() noexcept { _size = 0; }

    iterator begin() noexcept { return _data; }
    iterator end() noexcept { return _data + _size; }
    const_iterator begin() const noexcept { return _data; }
    const_iterator end() const noexcept { return _data + _size; }

    void swap(Vector& other) noexcept {
        std::swap(_capacity, other._capacity);
        std::swap(_size, other._size);
        std::swap(_data, other._data);
    }

    void erase(iterator pos) {
        if (pos < begin() || pos >= end()) return;
        size_type index = pos - begin();
        for (size_type i = index; i < _size - 1; ++i) {
            _data[i] = std::move(_data[i + 1]);
        }
        --_size;
        _data[_size].~T();
    }

private:
    void ensure_capacity_for_one() {
        if (_size >= _capacity) {
            size_type newCap = _capacity ? _capacity * 2 : 4;
            reserve(newCap);
        }
    }

    size_type _capacity;
    size_type _size;
    T* _data;
};

#endif // CVECTOR_H