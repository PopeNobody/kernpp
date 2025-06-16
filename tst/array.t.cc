#pragma once

#include <stddef.h>

template<typename T, size_t N>
struct array {
    using value_type = T;
    using ref_t      = T&;
    using ref_T      = const T&;
    using ptr_t      = T*;
    using ptr_T      = const T*;

    T data[N];
    size_t len = 0;

    size_t size()  const { return len; }
    bool   empty() const { return len == 0; }

    ref_t operator[](size_t i)       { return data[i]; }
    ref_T operator[](size_t i) const { return data[i]; }

    ptr_t begin()       { return data; }
    ptr_t end()         { return data + len; }
    ptr_T begin() const { return data; }
    ptr_T end()   const { return data + len; }

    void push_back(ref_T val) {
        if (len < N)
            data[len++] = val;
        else
            panic();
    }

    [[noreturn]] void panic() const {
        // Feel free to write to serial, LED, or stone tablet
        while (1) {}
    }
};

void test_array() {
    array<int, 8> a;

    a.push_back(10);
    a.push_back(20);
    a.push_back(30);

    for (auto x : a)
        puti(x);  // Replace with whatever output you use
}
